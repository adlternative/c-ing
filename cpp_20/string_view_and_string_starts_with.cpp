#include <iostream>
#include <string_view>
using namespace std::literals::string_view_literals;
int main() {
  std::string_view str{"Trains are fast!"};

  std::cout << str.length() << '\n';                 // 16
  std::cout << str.substr(0, str.find(' ')) << '\n'; // Trains
  std::cout << (str == "Trains are fast!") << '\n';
  // 1

  // Since C++20
  std::cout << str.starts_with("Boats") << '\n'; // 0
  std::cout << str.ends_with("fast!") << '\n';   // 1

  std::cout << str << '\n'; // Trains are fast!
  auto v = "This is a view"sv;
  std::cout << std::string(v).c_str() << std::endl;
  std::string_view s1 = "abc\0\0def";
  std::string_view s2 = "abc\0\0def"sv;
  std::cout << "s1: " << s1.size() << " \"" << s1 << "\"\n";
  std::cout << "s2: " << s2.size() << " \"" << s2 << "\"\n";

  std::string_view str2{"abc", 1};

  std::cout << str2.data() << std::endl;
  std::cout << std::string(str2) << std::endl;
  return 0;
}