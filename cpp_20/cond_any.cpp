// conditionVariableAny.cpp

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std::literals;

std::mutex mutex_;
std::condition_variable_any condVar;

bool dataReady;

void receiver(std::stop_token stopToken) { // (1)

  std::cout << "Waiting" << '\n';

  std::unique_lock<std::mutex> lck(mutex_);
  bool ret = condVar.wait(lck, stopToken, [] { return dataReady; });
  if (ret) {
    std::cout << "Notification received: " << '\n';
  } else {
    /* 如果 该线程被　request_stop了　wait 会立刻返回并表示收到stop信号
     * 返回值表示是否满足 cond的条件*/
    std::cout << "Stop request received" << '\n';
  }
}

void sender() { // (2)

  std::this_thread::sleep_for(5s);
  {
    std::lock_guard<std::mutex> lck(mutex_);
    dataReady = true;
    std::cout << "Send notification" << '\n';
  }
  condVar.notify_one(); // (3)
}

int main() {

  std::cout << '\n';

  std::jthread t1(receiver);
  std::jthread t2(sender);

  t1.request_stop(); // (4)

  t1.join();
  t2.join();

  std::cout << '\n';
}