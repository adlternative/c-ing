#include <bits/stdc++.h> /* 万能头 */
#include <ranges>
using namespace std;

int main(int argc, char *argv[]) {

  using namespace std::ranges;
  vector<int> a{1, 2, 3};
  for (int i : (a | views::reverse) | views::transform([](int x) {
                 return x + 1;
               }) | views::filter([](int x) { return x % 2; })) {
    std::cout << i;
  }
  for (int i : views::filter(
           views::transform(views::reverse(a), [](int x) { return x + 1; }),
           [](int x) { return x % 2; })) {
    std::cout << i;
  }
  for (int i : iota_view(1) | views::take(5)) {
    std::cout << i;
  }
}