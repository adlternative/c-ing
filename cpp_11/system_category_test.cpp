#include <iomanip>
#include <iostream>
#include <string>
#include <system_error>

int main() {
  std::error_condition econd =
      std::system_category().default_error_condition(EDOM);
  std::cout << "Category: " << econd.category().name() << '\n'
            << "Value: " << econd.value() << '\n'
            << "Message: " << econd.message() << '\n';

  econd = std::system_category().default_error_condition(10001);
  std::cout << "Category: " << econd.category().name() << '\n'
            << "Value: " << econd.value() << '\n'
            << "Message: " << econd.message() << '\n';
}
