#include "static_constexpr_test.hpp"
#include <bits/stdc++.h> /* 万能头 */
using namespace std;

int main(int argc, char **argv) {
  A aa;
  // aa.a = 1;
  std::cout << A::a << std::endl;
  A::a++;
  std::cout << A::a << std::endl;
}