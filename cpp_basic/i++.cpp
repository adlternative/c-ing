#include <bits/stdc++.h> /* 万能头 */
#include <thread>

using namespace std;

void thread1() {
  int i = rand();
  printf("heheh\n");
  printf("hehe2w\n");
  printf("heheerh\n");
  printf("%d\n", i);
}

int main() {
  thread ts[10];
  for (int i = 1; i != 10; i++)
    ts[i] = thread{thread1};
  for (int i = 1; i != 10; i++)
    ts[i].join();
}
