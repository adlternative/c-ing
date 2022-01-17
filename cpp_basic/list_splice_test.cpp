#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main(int argc, char *argv[]) {
  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  auto iter = l.begin();
  std::advance(iter, 4);
  l.splice(l.begin(), l, iter);
  for_each(l.begin(), l.end(), [](int i) { std::cout << i << " "; });
}