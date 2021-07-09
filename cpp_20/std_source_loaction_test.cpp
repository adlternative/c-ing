#include <iostream>
#include <source_location>
#include <string_view>

void log(std::string_view message, const std::source_location &location =
                                       std::source_location::current()) {
  std::cout << "info:" << location.file_name() << ":" << location.line() << " "
            << message << '\n';
}

int main() {
  log("Hello world!"); // info:main.cpp:15 Hello world!
}