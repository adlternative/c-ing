// cppcoroTask.cpp
#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include <cppcoro/sync_wait.hpp>
#include <cppcoro/task.hpp>

using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::time_point;

using namespace std::chrono_literals; // 1s

auto getTimeSince(const time_point<high_resolution_clock> &start) {

  auto end = high_resolution_clock::now();
  duration<double> elapsed = end - start;
  return elapsed.count();
}

cppcoro::task<> third(const time_point<high_resolution_clock> &start) {

  std::this_thread::sleep_for(1s);
  std::cout << "Third waited " << getTimeSince(start) << " seconds."
            << std::endl;

  co_return; // (4)
}

cppcoro::task<> second(const time_point<high_resolution_clock> &start) {

  auto thi = third(start); // (2)
  std::this_thread::sleep_for(1s);
  co_await thi; // (3)

  std::cout << "Second waited " << getTimeSince(start) << " seconds."
            << std::endl;
}

cppcoro::task<> first(const time_point<high_resolution_clock> &start) {

  auto sec = second(start); // (2)
  std::this_thread::sleep_for(1s);
  co_await sec; // (3)

  std::cout << "First waited " << getTimeSince(start) << " seconds."
            << std::endl;
}
/* g++ -std=c++2a  cppcoroTask.cpp -lcppcoro  */
int main() {

  std::cout << std::endl;

  auto start = high_resolution_clock::now();
  /* sync wait()函数可用于同步等待，直到指定的可等待对象完成。
   * 指定的可等待对象将在新创建的协程内的当前线程上共同等待。
   * sync wait()调用将阻塞直到操作完成，并将返回co await表达式的结果，如果co
   * await表达式带有未处理的异常完成则重新抛出异常。
   * sync_wait（）函数大多是从main（）中启动顶级任务，然后等待完成任务完成，
   * 实际上是启动第一个/顶级任务的唯一方法。
   */

  cppcoro::sync_wait(first(start)); // (1)

  std::cout << "Main waited " << getTimeSince(start) << " seconds."
            << std::endl;

  std::cout << std::endl;
}