#include <deque>
#include <fmt/ranges.h>
#include <vector>

int main() {
  std::deque<int> d = {1, 2, 3};
  std::vector<int> v = {1, 2, 3};
  fmt::print("{}\n", d);
}