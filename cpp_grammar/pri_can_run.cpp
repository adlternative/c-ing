#include <bits/stdc++.h> /* 万能头 */

using namespace std;

// class A {
// public:
//   void *f() { return (void *)func; }

// private:
//   void func() { std::cout << "123" << std::endl; }
// };

// int main() {
//   A a;
//   void (A::*p)() = (void (A::*)())a.f();
//   pr(&a);
// }

#include <iostream>
using namespace std;
class A {
private:
    std::cout << "A: func()" << std::endl;
  virtual void func() {
  }
  int a = 1000000;
};
class B : public A {
public:
  void func() { std::cout << "B: func()" << std::endl; }
};
typedef void (*fun)();

int main(int argc, const char *argv[]) {
  // insert code here...
  // func<std::string>("10.0");
  A a;
  long *ptr = reinterpret_cast<long *>(&a); //取对象地址的前8个字节
  cout << "对象a的地址" << &a << endl;
  cout << "对象a的地址" << ptr << endl;

  long *p = reinterpret_cast<long *>(*ptr); //对ptr解引用，就是虚表的地址
  cout << "虚表地址" << p << endl;
  cout << "第一个虚函数地址:" << p[0] << endl;

  fun point = (fun)(p[0]);
  cout << "第一个虚函数地址" << (long)point << endl;
  point();
  return 0;
}
