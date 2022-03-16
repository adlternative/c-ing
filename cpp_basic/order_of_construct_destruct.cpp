#include <bits/stdc++.h> /* 万能头 */

using namespace std;

class B {
public:
  B(int v) { std::cout << __func__ << std::endl; }
  ~B() { std::cout << __func__ << std::endl; }
};
class C {
public:
  C(int v) { std::cout << __func__ << std::endl; }
  ~C() { std::cout << __func__ << std::endl; }
};

class A {
public:
  A() : c(0), b(1) { std::cout << __func__ << std::endl; }
  ~A() { std::cout << __func__ << std::endl; }

  B b;
  C c;
};

int main(int argc, char **argv) { A a; }