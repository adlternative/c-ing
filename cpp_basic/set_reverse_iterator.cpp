#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main(int argc, char **) {
  set<int> s;
  for (int i = 0; i < 10; i++)
    s.insert(i);
  for (auto iter = s.rbegin(); iter != s.rend(); iter++)
    std::cout << *iter << std::endl;
}