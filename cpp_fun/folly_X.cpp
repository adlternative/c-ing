#include <fmt/core.h>

#define X(c)                                                                   \
  case c:                                                                      \
    return #c

namespace adl {
enum Num {
  ONE = 1,
  TWO = 2,
};
}

const char *Num_to_string(adl::Num num) {
  switch (num) {
    X(adl::ONE);
    X(adl::TWO);
  }
  return "<INVALID Num>";
}

int main(int argc, char *argv[]) {
  adl::Num num1 = adl::ONE;
  adl::Num num2 = adl::TWO;
  fmt::print("{} {}\n", Num_to_string(num1), Num_to_string(num2));
}