#include <bits/stdc++.h> /* 万能头 */

using namespace std;

class A {
public:
  static A *NewA() { return new A; }

private:
  A() = default;
};

int main(int argc, char **argv) { auto a = A::NewA(); }