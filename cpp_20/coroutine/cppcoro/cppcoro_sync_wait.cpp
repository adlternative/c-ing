#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <chrono>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>
#include <iostream>
#include <string>
#include <thread>

using namespace cppcoro;

void example_task() {
  auto makeTask = []() -> task<std::string> { co_return "foo"; };

  auto task = makeTask();

  // start the lazy task and wait until it completes
  sync_wait(task);       // -> "foo"
  sync_wait(makeTask()); // -> "foo"
}
/* FAIL */
void example_shared_task() {
  auto makeTask = []() -> shared_task<int> { co_return ::rand(); };

  auto task = makeTask();
  int result = sync_wait(task);
  std::cout << result << std::endl;
  result = sync_wait(makeTask());
  std::cout << result << std::endl;
  // start the shared task and wait until it completes
}

int main(int argc, char **argv) { example_shared_task(); }