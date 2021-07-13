#include <fmt/core.h>
#include <vector>

int main(int argc, char **argv) {
  std::vector<int> v;
  fmt::print("{}", v.size());
  fmt::print("{}", v.max_size());
}