#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif
#include <cppcoro/single_consumer_event.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>

/* 单次的等待事件（无法复用了之后） */
cppcoro::single_consumer_event event;

cppcoro::task<> consumer() {

  auto start = std::chrono::high_resolution_clock::now();

  co_await event; // suspended until some thread calls event.set()

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Consumer waited " << elapsed.count() << " seconds."
            << std::endl;

  co_return;
}

void producer() {

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(2s);

  event.set(); // resumes the consumer
}

int main() {

  std::cout << std::endl;

  auto con = std::async([] { cppcoro::sync_wait(consumer()); }); // (1)
  auto prod = std::async(producer);                              // (2)

  con.get(), prod.get();

  std::cout << std::endl;
}