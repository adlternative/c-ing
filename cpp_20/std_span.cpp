#include <array>
#include <fmt/core.h>
#include <iostream>
#include <numeric>
#include <span>
#include <string>
#include <vector>

void printMe(std::span<char> container) {

  std::cout << "container.size(): " << container.size() << '\n'; // (4)
  for (auto e : container)
    std::cout << e << ' ';
  std::cout << "\n\n";
}

void printMe(std::span<int> container) {

  std::cout << "container.size(): " << container.size() << '\n'; // (4)
  for (auto e : container)
    std::cout << e << ' ';
  std::cout << "\n\n";
}

void test() {
  std::vector<int> myVec(20);
  std::iota(myVec.begin(), myVec.end(), 0); // (1)
  for (auto v : myVec)
    std::cout << v << " ";

  std::cout << "\n\n";

  std::span<int> mySpan(myVec); // (2)
  auto length = mySpan.size();

  auto count = 5; // (3)
  for (long unsigned int first = 0; first <= (length - count); first += count) {
    for (auto ele : mySpan.subspan(first, count))
      std::cout << ele << " ";
    std::cout << std::endl;
  }
}
int main() {

  std::cout << std::endl;

  int arr[]{1, 2, 3, 4}; // (1)
  printMe(arr);

  std::vector vec{1, 2, 3, 4, 5}; // (2)
  printMe(vec);

  std::array arr2{1, 2, 3, 4, 5, 6}; // (3)
  printMe(arr2);

  char s[1024] = "abcdef";
  printMe(s);

  std::vector myVec{1, 2, 3, 4, 5};

  std::span mySpan1{myVec};                      // (1)
  std::span mySpan2{myVec.data(), myVec.size()}; // (2)

  bool spansEqual = std::equal(mySpan1.begin(), mySpan1.end(), mySpan2.begin(),
                               mySpan2.end());

  std::cout << "mySpan1 == mySpan2: " << spansEqual << std::endl; // (3)
  std::vector vec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printMe(vec2);

  std::span span1(vec2);                               // (1)
  std::span span2{span1.subspan(1, span1.size() - 2)}; // (2)
  std::span span3{vec2.data() + 1, 3};                 // (2)

  std::transform(span2.begin(), span2.end(), // (3)
                 span2.begin(), [](int i) { return i * i; });

  // printMe(vec2);
  printMe(span3);
  std::cout << std::endl;
  // test();
}