#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main(int argc, char **argv) {
  map<string, string> m;
  for (int i = 0; i < 20; i++) {
    string key("key");
    key += std::to_string(i);
    string value("value");
    value += std::to_string(i);
    m.insert({key, value});
  }
  for (auto &p : m) {
    cout << p.first << " " << p.second << endl;
  }
}