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

#include <cppcoro/cancellation_source.hpp>
#include <cppcoro/cancellation_token.hpp>

using namespace std::chrono_literals;

int main() {

  std::cout << std::endl;

  cppcoro::cancellation_source canSource;
  cppcoro::cancellation_token canToken = canSource.token(); // (1)

  auto cancelSender = std::async([&canSource] {
    std::this_thread::sleep_for(2s);
    canSource.request_cancellation(); // (3)
    std::cout << "canSource.request_cancellation() " << std::endl;
  });

  auto cancelReceiver = std::async([&canToken] {
    while (true) {
      std::cout << "Wait for cancellation request" << std::endl;
      std::this_thread::sleep_for(200ms);
      if (canToken.is_cancellation_requested())
        return; // (2)
    }
  });

  cancelSender.get(), cancelReceiver.get();

  std::cout << std::endl;
}
