#include <bits/stdc++.h> /* 万能头 */
#include <optional>

using namespace std;

int main(int argc, char *argv[]) {
  optional<int> o{1};

  o = 2;
  *o = 3;

  std::cout << *o << std::endl;
}