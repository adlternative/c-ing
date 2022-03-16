#include <iostream>
using namespace std;

class K {
  virtual void func() = 0;
};
class KK : public K {
  void func() { std::cout << "hehe" << std::endl; }
};

class B {
public:
  virtual void show() { cout << "B show" << endl; }
  B() {
    show();
    std::cout << "B" << std::endl;
  }
};

class D3 : public B {
public:
  void show() { cout << "D1 show" << endl; }
  D3() {
    std::cout << "D1" << std::endl;
    show();
  }
};

class D1 : virtual public B {
public:
  void show() { cout << "D1 show" << endl; }
  D1() {
    std::cout << "D1" << std::endl;
    show();
  }
};

class D2 : virtual public B {
public:
  void show() { cout << "D2 show" << endl; }
  D2() {
    std::cout << "D2" << std::endl;
    show();
  }
};

class DD : public D1, public D2 {
public:
  void show() { cout << "DD show" << endl; }
  DD() {
    std::cout << "DD" << std::endl;
    show();
  }
};

class K2 {};
class K3 : public K2 {};
class K4 : public K2 {
  int k;
};

int main() {
  // DD d;
  // KK k;
  // D3 d3;
  std::cout << sizeof(K2) << std::endl;
  std::cout << sizeof(K3) << std::endl;
  std::cout << sizeof(K4) << std::endl;
  // std::cout << sizeof(K) << std::endl;
  // std::cout << sizeof(KK) << std::endl;
  // std::cout << sizeof(B) << std::endl;
  // std::cout << sizeof(D1) << std::endl;
  // std::cout << sizeof(D2) << std::endl;
  // std::cout << sizeof(DD) << std::endl;
}
