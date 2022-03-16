#include <bits/stdc++.h> /* 万能头 */

using namespace std;

class A {
public:
  A() { std::cout << "A" << std::endl; }
  A(const A &a) { std::cout << "A(const A&)" << std::endl; }
  A(A &&a) noexcept { std::cout << "A(A &&)" << std::endl; }

  ~A() { std::cout << "~A" << std::endl; }
};

int main(int argc, char **argv) {
  vector<A> vv;
  for (int i = 0; i < 10; i++) {
    vv.emplace_back();
  }
}