// interruptJthread.cpp

#include <chrono>
#include <iostream>
#include <thread>

using namespace ::std::literals;

int main() {

  std::cout << '\n';

  std::jthread nonInterruptable([] { // (1)
    int counter{0};
    while (counter < 10) {
      std::this_thread::sleep_for(0.2s);
      std::cerr << "nonInterruptable: " << counter << '\n';
      ++counter;
    }
  });

  std::jthread interruptable([](std::stop_token stoken) { // (2)
    int counter{0};
    while (counter < 10) {
      std::this_thread::sleep_for(0.2s);
      if (stoken.stop_requested())
        return; // (3)
      std::cerr << "interruptable: " << counter << '\n';
      ++counter;
    }
  });

  std::this_thread::sleep_for(1s);

  std::cerr << '\n';
  std::cerr << "Main thread interrupts both jthreads" << '\n';
  nonInterruptable.request_stop();
  interruptable.request_stop(); // (4)

  std::cout << '\n';
}