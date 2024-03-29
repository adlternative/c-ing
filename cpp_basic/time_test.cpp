#include <chrono>
#include <iostream>
#include <unistd.h>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

int main() {
  high_resolution_clock::time_point beginTime = high_resolution_clock::now();
  ::sleep(3);
  high_resolution_clock::time_point endTime = high_resolution_clock::now();
  milliseconds timeInterval =
      std::chrono::duration_cast<milliseconds>(endTime - beginTime);
  std::cout << timeInterval.count() << "ms\n";
}