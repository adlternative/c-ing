// #ifndef __cpp_impl_coroutine
// #define __cpp_impl_coroutine true
// #endif
// #if __cplusplus < 202002L
// #undef __cplusplus
// #define __cplusplus 202002L
// #endif

#include <cppcoro/async_mutex.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::literals;
cppcoro::async_mutex mutex;

int sum{}; // (2)

cppcoro::task<> addToSum(int num) {
  std::this_thread::sleep_for(1s);
  cppcoro::async_mutex_lock lockSum = co_await mutex.scoped_lock_async(); // (3)
  sum += num;
} // (4)

int main() {

  std::cout << std::endl;

  std::vector<std::thread> vec(10); // (1)

  for (auto &thr : vec) {
    thr = std::thread([] {
      auto begin = std::chrono::high_resolution_clock::now();
      for (int n = 0; n < 10; ++n) {
        std::cout << "1" << std::endl;
        cppcoro::sync_wait(addToSum(n));
        std::cout << "2" << std::endl;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - begin;
        std::cout << "Consumer waited " << elapsed.count() << " seconds."
                  << std::endl;
      }
    });
  }

  for (auto &thr : vec)
    thr.join();

  std::cout << "sum: " << sum << std::endl;

  std::cout << std::endl;
}