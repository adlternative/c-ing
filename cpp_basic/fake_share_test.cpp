#include <bits/stdc++.h> /* 万能头 */

using namespace std;

void t3() {
  int a;
  long padding[8];
  int b;
  std::vector<std::thread> threads(2);

  threads[0] = thread([&]() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int rc = pthread_setaffinity_np(threads[0].native_handle(),
                                    sizeof(cpu_set_t), &cpuset);
    int cnt = 10000;
    while (cnt--)
      ++a;
    std::cout << "a=" << a << std::endl;
  });
  threads[1] = thread([&]() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int rc = pthread_setaffinity_np(threads[1].native_handle(),
                                    sizeof(cpu_set_t), &cpuset);
    int cnt = 10000;
    while (cnt--)
      ++b;
    std::cout << "b=" << b << std::endl;
  });

  for (auto &t : threads) {
    t.join();
  }
}

void t2() {
  int a, b;
  std::vector<std::thread> threads(2);

  threads[0] = thread([&]() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int rc = pthread_setaffinity_np(threads[0].native_handle(),
                                    sizeof(cpu_set_t), &cpuset);
    int cnt = 10000;
    while (cnt--)
      ++a;
    std::cout << "a=" << a << std::endl;
  });
  threads[1] = thread([&]() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int rc = pthread_setaffinity_np(threads[1].native_handle(),
                                    sizeof(cpu_set_t), &cpuset);
    int cnt = 10000;
    while (cnt--)
      ++b;
    std::cout << "b=" << b << std::endl;
  });

  for (auto &t : threads) {
    t.join();
  }
}

void t1() {
  int a;
  std::vector<std::thread> threads(2);

  threads[0] = thread([&]() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int rc = pthread_setaffinity_np(threads[0].native_handle(),
                                    sizeof(cpu_set_t), &cpuset);
    int cnt = 10000;
    while (cnt--)
      ++a;
    std::cout << "a1=" << a << std::endl;
  });
  threads[1] = thread([&]() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    int rc = pthread_setaffinity_np(threads[1].native_handle(),
                                    sizeof(cpu_set_t), &cpuset);
    int cnt = 10000;
    while (cnt--)
      ++a;
    std::cout << "a2=" << a << std::endl;
  });

  for (auto &t : threads) {
    t.join();
  }
}

int main(int argc, char **argv) {
  if (argc == 2) {
    switch (argv[1][0]) {
    case '1':
      t1();
      break;
    case '2':
      t2();
      break;
    case '3':
      t3();
      break;
    }
  }
}