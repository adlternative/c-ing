#include <bits/stdc++.h> /* 万能头 */

struct A {
public:
  int a;
  void funca() {}

protected:
  int b;
  void funcb() {}

private:
  int c;
  void funcc() {}
};

/* 默认公有继承，A的私有成员将无法访问 */
struct B : A {
public:
  void func() {
    int a1 = a;
    int b1 = b;
    /* int c1 = c; // err */
    funca();
    funcb();
    /* funcc(); //err */
  }
};

using namespace std;
int main(int argc, char **argv) {
  B b;
  b.func();
  b.funca();
  // b.funcb();
  // b.funcc();

}