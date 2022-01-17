#include <fmt/ostream.h>

#include <string>

class A {
public:
  A(int a, std::string b) : a_(a), b_(std::move(b)) {}
  friend std::ostream &operator<<(std::ostream &os, const A &a);

private:
  int a_;
  std::string b_;
};

std::ostream &operator<<(std::ostream &os, const A &a) {
  return os << fmt::format("{} {}", a.a_, a.b_);
}

int main(int argc, char **argv) {
  A aa(1, "A");
  fmt::print("{}", aa);
}