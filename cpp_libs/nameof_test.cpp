// #include <bits/stdc++.h> /* 万能头 */
#include <iostream>
#include <nameof.hpp>
using namespace std;

int main(int argc, char **argv) {

  int a;
  enum class Color { RED = 1, BLUE = 2, GREEN = 4 };

  auto color = Color::RED;
  // Name of enum variable.
  // NAMEOF_ENUM(color)->"RED";
  std::cout << NAMEOF_ENUM(color) << std::endl;
}