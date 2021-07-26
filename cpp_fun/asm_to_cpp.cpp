/**
 * @brief 等于旧则变新并返回旧值 否则返回其本身的值
 *
 * @param ptr
 * @param old_
 * @param new_
 * @return unsigned long
 */
unsigned long cmpxchg(void *ptr, unsigned long old_, unsigned long new_) {
  if (*(unsigned long *)ptr == old_) {
    *(unsigned long *)ptr = new_;
    return old_;
  }
  return *(unsigned long *)ptr;
}
namespace reorder {
/* 86的存储器模型使得sfence与lfence对CPU之间的通信完全无用;
 * 阻止编译时重新排序就足够了 */

/*  写屏障控制写的顺序。因为写入内存很慢（与 CPU
 * 的速度相比），通常有一个写入请求队列，写入在“真正发生”之前发布。
 *尽管它们按顺序排队，但在队列内部时，写入可能会重新排序。
 *（所以也许“队列”不是最好的名字......）除非你使用写屏障来防止重新排序。 */

/* 读屏障控制读的顺序。由于推测性执行（CPU
 *   提前查看并提前从内存加载）以及写入缓冲区的存在（如果存在，CPU
 *   将从写入缓冲区而不是内存中读取值 - 即 CPU 认为它只是写了 X =
 *   5，那为什么要读回来，只是看写缓冲区还在等待变成5）读取可能会发生乱序。
 */

// smp_mb() 是一个完整的障碍，确实需要一个实际的 asm
// 指令，以及阻止编译时重新排序。 asm volatile ("" :::
// "memory")在需要的地方使用，
//但名称不同（例如smp_rmb()，smp_wmb())。

/*
 *摘自 io_uring pdf
 * read_barrier():
 * Ensure previous writes are visible before doing subsequent memory reads.
 *        write_barrier():
 * Order this write after previous writes.
 */

#include <assert.h>
//  Ensure previous writes are visible before doing subsequent memory reads.
void read_barrier() {}

void read_barrier_example() {
  int write1 = 0, write2 = 0;
  int read;
  write1 = 1;
  write2 = 1;
  read_barrier();
  read = write1; /*  */
  assert(read == 1);
}

// Order this write after previous writes.
void write_barrier() {}

void write_barrier_example() {
  int write1 = 0, write2 = 0;
  int read;
  write1 = 1;
  write2 = 1;
  write_barrier();
  int write3 = write1 + write2; /* */
}
} // namespace reorder