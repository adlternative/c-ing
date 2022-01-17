#include <bits/stdc++.h> /* 万能头 */

using namespace std;

class S {
public:
  S() { std::cout << "S" << std::endl; }
  ~S() { std::cout << "~S" << std::endl; }
  void SetA() { a = 1; }
  int a;
};

S test() {
  S s;
  s.SetA();

  return s;
}

int main(int argc, char **argv) {
  S s = test();
  return 0;
}