// cppcoroLatch.cpp
#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <chrono>
#include <future>
#include <iostream>

#include <cppcoro/async_latch.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

using namespace std::chrono_literals;

cppcoro::task<> waitFor(cppcoro::async_latch &latch) {
  std::cout << "Before co_await" << std::endl;
  co_await latch; // (3)
  std::cout << "After co_await" << std::endl;
}

int main() {

  std::cout << std::endl;

  cppcoro::async_latch latch(3); // (1)

  // (2)
  auto waiter = std::async([&latch] { cppcoro::sync_wait(waitFor(latch)); });

  auto counter1 = std::async([&latch] { // (2)
    std::this_thread::sleep_for(2s);
    std::cout << "counter1: latch.count_down() " << std::endl;
    latch.count_down();
  });

  auto counter2 = std::async([&latch] { // (2)
    std::this_thread::sleep_for(1s);
    std::cout << "counter2: latch.count_down(2) " << std::endl;
    latch.count_down(2);
  });

  waiter.get(), counter1.get(), counter2.get();

  std::cout << std::endl;
}