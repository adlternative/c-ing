// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "./arena.h"

namespace leveldb {

static const int kBlockSize = 4096;

Arena::Arena()
    : alloc_ptr_(nullptr), alloc_bytes_remaining_(0), memory_usage_(0) {}

Arena::~Arena() {
  for (size_t i = 0; i < blocks_.size(); i++) {
    delete[] blocks_[i];
  }
}

char *Arena::AllocateFallback(size_t bytes) {
  if (bytes > kBlockSize / 4) {
    // 如果分配的大小大于 1024
    // Object is more than a quarter of our block size.  Allocate it separately
    // to avoid wasting too much space in leftover bytes.
    /* 对象是我们块大小的四分之一以上。
    单独分配它以避免在剩余字节中浪费太多空间。 */
    char *result = AllocateNewBlock(bytes);
    return result;
  }

  // We waste the remaining space in the current block.
  /* 否则分配 4096 Byte 新块 */
  alloc_ptr_ = AllocateNewBlock(kBlockSize);
  alloc_bytes_remaining_ = kBlockSize;
  /* 将该地址作为返回的内容 */
  char *result = alloc_ptr_;
  /* 然后将 空闲指针后移 bytes 大小 */
  alloc_ptr_ += bytes;
  /* 然后设置 空闲大小 */
  alloc_bytes_remaining_ -= bytes;
  return result;
}

char *Arena::AllocateAligned(size_t bytes) {
  // align == 8 in x86
  const int align = (sizeof(void *) > 8) ? sizeof(void *) : 8;
  static_assert((align & (align - 1)) == 0,
                "Pointer size should be a power of 2");
  /* 找到当前空闲指针模 8 余数 */
  size_t current_mod = reinterpret_cast<uintptr_t>(alloc_ptr_) & (align - 1);
  /* slop 由于内存对齐到8 而不可以拿来分的大小。
  表示如果模数是 0 则 无剩余，否则是 8 - 余数 */
  size_t slop = (current_mod == 0 ? 0 : align - current_mod);
  /* 需要拿走大小是 bytes + 剩余 ----> 其实就是 bytes 向上模 8 值 */
  size_t needed = bytes + slop;
  char *result;
  /* 如果小于空闲值 */
  if (needed <= alloc_bytes_remaining_) {
    /* |*****___|***... */
    /* result 定位到 下一个地址模 8 位置 */
    result = alloc_ptr_ + slop;
    /* 空闲指针后移 */
    alloc_ptr_ += needed;
    /* 设置空闲大小 */
    alloc_bytes_remaining_ -= needed;
  } else {
    // AllocateFallback always returned aligned memory
    /* 否则回落，回落总可以分配到对齐地址 因为分配的空间16对齐*/
    result = AllocateFallback(bytes);
  }
  assert((reinterpret_cast<uintptr_t>(result) & (align - 1)) == 0);
  return result;
}

char *Arena::AllocateNewBlock(size_t block_bytes) {
  /* 分配 block_bytes 大小的块 */
  char *result = new char[block_bytes];
  /* 放到 blocks 的 动态数组列表中 */
  blocks_.push_back(result);
  /* 内存占用量 += 块大小 + 8 这个 + 8 估计是考虑对齐了吧 */
  memory_usage_.fetch_add(block_bytes + sizeof(char *),
                          std::memory_order_relaxed);
  return result;
}

} // namespace leveldb
