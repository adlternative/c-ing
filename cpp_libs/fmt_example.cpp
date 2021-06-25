#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/os.h>
#include <fmt/ranges.h>
#include <map>
#include <vector>
int main() {
  using namespace std::literals::chrono_literals;
  fmt::print("Default format: {} {}\n", 42s, 100ms);
  fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
  fmt::print("Hello, world!\n");
  std::vector<int> v = {1, 2, 3};
  std::map<char, std::string> mm;
  mm['a'] = "asd";
  mm['c'] = "asds";
  fmt::print(" hehe {:s}", std::string("sad"));
  fmt::print("{}\n", mm);
  std::string s = fmt::format("The answer is {}.", 42);

  s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
  fmt::print(s);
  auto out = fmt::output_file("guide.txt");
  out.print("Don't {}", "Panic");
  fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Hello, {}!\n",
             "world");
  fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
                 fmt::emphasis::underline,
             "Hello, {}!\n", "мир");
  fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic, "Hello, {}!\n",
             "世界");
}
