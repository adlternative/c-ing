#include <atomic>
#include <bits/stdc++.h> /* 万能头 */
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <thread>

/* 全篇的重排需要考虑的cpu重排，而且不仅仅是 X86体系 */

using namespace std;
TEST(atomic, fetch_add) {
  atomic<int> a(1);
  EXPECT_EQ(1, a.fetch_add(3));
  EXPECT_EQ(4, a);
}

namespace atomic_operations {
std::atomic<std::string *> ptr;
int data_;
std::atomic<int> atoData;

void producer() {
  std::string *p = new std::string("C++11");
  data_ = 2011;
  atoData.store(2014, std::memory_order_relaxed);
  /* release 之前写都在(不会重排到它之下) */
  ptr.store(p, std::memory_order_release);
  /* 但是这里的读写还是可以有机会重排上去 */
}

void consumer() {
  std::string *p2;
  /* 但是这里的读写还是可以有机会重排下去 */
  while (!(p2 = ptr.load(std::memory_order_acquire)))
    ;
  /* acquire 之后读都在,不会重排到它之上 */

  EXPECT_EQ(*p2, "C++11");
  EXPECT_EQ(data_, 2011);
  EXPECT_EQ(atoData.load(std::memory_order_relaxed), 2014);
}

TEST(atomic, atomic_operations) {
  // acquireRelease.cpp
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();
  delete ptr;
}
} // namespace atomic_operations

namespace memory_barriers {
// acquireReleaseFences.cpp

#include <atomic>
#include <iostream>
#include <string>
#include <thread>

std::atomic<std::string *> ptr;
int data;
std::atomic<int> atoData;

void producer() {
  std::string *p = new std::string("C++11");
  data = 2011;
  atoData.store(2014, std::memory_order_relaxed);
  /* release 之前写都在(不会重排到它之下) */
  std::atomic_thread_fence(std::memory_order_release);
  /* 这里的读写无机会重排上去 */
  ptr.store(p, std::memory_order_relaxed);
}

void consumer() {
  std::string *p2;
  /* 这里的读写还是可以有机会重排下去 */
  while (!(p2 = ptr.load(std::memory_order_relaxed)))
    ;
  /* acquire 之后读不会重排到它之上 */
  std::atomic_thread_fence(std::memory_order_acquire);

  EXPECT_EQ(*p2, "C++11");
  EXPECT_EQ(data, 2011);
  EXPECT_EQ(atoData.load(std::memory_order_relaxed), 2014);
}

TEST(atomic, memory_barriers) {
  // acquireRelease.cpp
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();
  delete ptr;
}
} // namespace memory_barriers