#include <bits/stdc++.h> /* 万能头 */
#include <fmt/core.h>

using namespace std;
enum he { a1, a3 };
class A {
public:
  template <typename T> static void func(int a);
  template <enum he> static void func();
};
// template <enum he> static void A::func();

template <typename T> void A::func(int a) { fmt::print("sad {}", 1); }
template <enum he> void A::func() { fmt::print("sad2"); }
int main(int argc, char **argv) { A::func<a1>(); }