#include <bits/stdc++.h> /* 万能头 */

using namespace std;

class FUN {
public:
  FUN(int *p) : ptr(p) { std::cout << "我构造" << std::endl; }
  ~FUN() {
    std::cout << "我析构" << std::endl;
    delete ptr;
  }

private:
  int *ptr;
};
int main(int argc, char **argv) {
  // int a;
  // new (&a) int(1);

  alignas(FUN) unsigned char buf[sizeof(FUN)];
  // 静态分配拥有自动存储期的存储，对任何对象类型 `FUN` 足够大。
  FUN *tptr =
      new (buf) FUN(new int(1)); // 构造一个 `FUN` 对象，将它直接置于
                                 // 你预分配的位于内存地址 `buf` 的存储。
  tptr->~FUN();
  // delete tptr;
}