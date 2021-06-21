#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numbers>
#include <string>

// class Cls {
// public:
//   void do_some(long double __secs) { std::cout << __secs << std::endl; }
//   void do_some2(long double __secs) { std::cout << __secs << std::endl; }
// };
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"
constexpr long double operator"" s(long double __secs) { return 2 * __secs; }
#pragma GCC diagnostic pop

// used as conversion from degrees (input param) to radians (returned output)
// constexpr long double operator"" _deg_to_rad(long double deg) {
//   long double radians = deg * std::numbers::pi_v<long double> / 180;
//   return radians;
// }

constexpr unsigned long long operator"" _kk(unsigned long long a) {
  // std::cout << "bb" << std::endl;
  return 1;
}

// int main(int argc, char **argv) { unsigned long long a = 3333_kk; }

int main(int argc, char **argv) {
  double x_rad = 90.2s;
  // long double x = 2_deg_to_rad;
  std::cout << x_rad << std::endl;
}