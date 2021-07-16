#include "Mutex.hpp"
#include <bits/stdc++.h> /* 万能头 */
#include <fmt/core.h>
#include <gtest/gtest.h>
#include <thread>

using namespace std;

TEST(Mutex, futex_impl) {
  spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][thread %t][%@,%!][%l] : %v");
  Mutex m;
  thread t1([&]() {
    m.lock();
    std::this_thread::sleep_for(3s);
    m.unlock();
  });
  thread t2([&]() {
    m.lock();
    std::this_thread::sleep_for(3s);
    m.unlock();
  });
  t1.join();
  t2.join();
}