#include <bits/stdc++.h> /* 万能头 */
#include <memory>

using namespace std;
int main(int argc, char *argv[]) {
  set<shared_ptr<int>> s;
  set<shared_ptr<int>> s1;
  s.insert(std::make_shared<int>(1));
  s.insert(std::make_shared<int>(2));
  s1 = s;
  for (auto it = s1.begin(); it != s1.end(); it++)
    cout << (*it).use_count() << endl;
  return 0;
}