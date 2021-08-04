// Copyright (c) 2018 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "./no_destructor.h"

#include <cstdint>
#include <cstdlib>
#include <utility>

#include "gtest/gtest.h"

namespace leveldb {

namespace {

struct DoNotDestruct {
public:
  DoNotDestruct(uint32_t a, uint64_t b) : /* s_(s), */ a_(a), b_(b) {}
  ~DoNotDestruct() {
    std::cout << "发生析构了？" << std::endl;
    std::abort();
  }

  // Used to check constructor argument forwarding.
  uint32_t a_;
  uint64_t b_;
  // std::string s_;
};

constexpr const uint32_t kGoldenA = 0xdeadbeef;
constexpr const uint64_t kGoldenB = 0xaabbccddeeffaabb;
} // namespace

TEST(NoDestructorTest, StackInstance) {
  std::string str("what");

  NoDestructor<DoNotDestruct> instance(kGoldenA, kGoldenB/* , str */);
  ASSERT_EQ(kGoldenA, instance.get()->a_);
  ASSERT_EQ(kGoldenB, instance.get()->b_);
}

TEST(NoDestructorTest, StaticInstance) {
  std::string str("what");
  static NoDestructor<DoNotDestruct> instance(kGoldenA, kGoldenB/* , str */);
  ASSERT_EQ(kGoldenA, instance.get()->a_);
  ASSERT_EQ(kGoldenB, instance.get()->b_);
}

} // namespace leveldb

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
