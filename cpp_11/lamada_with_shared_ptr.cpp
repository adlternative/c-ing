#include <fmt/core.h>
#include <functional>
#include <memory>

int main(int argc, char *argv[]) {
  std::function<void()> fn;
  {
    std::shared_ptr<int> p1(new int(1));
    fn = std::move([=]() -> void { fmt::print("*p1={}", *p1); });
  }
  fn();
}