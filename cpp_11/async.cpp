#include <bits/stdc++.h> /* 万能头 */
#include <thread>

using namespace std;

int func() {
  std::this_thread::sleep_for(1s);
  std::cout << __func__ << std::endl;
  return ::rand();
}

int main(int argc, char **argv) {
  std::cout << __func__ << std::endl;
  /* 参数 async 会再次开启一个线程执行异步函数 */
  // std::future<int> asy1 = std::async(std::launch::async, func);
  // std::future<int> asy2 = std::async(std::launch::async, func);
  /* 参数 deferred 则会到某个线程执行 get 的时候执行 */
  std::future<int> asy1 = std::async(std::launch::deferred, func);
  std::future<int> asy2 = std::async(std::launch::deferred, func);
  std::this_thread::sleep_for(2s);
  std::cout << __func__ << std::endl;
  std::cout << asy1.get() + asy2.get() << std::endl;
}