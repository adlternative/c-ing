#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main(int argc, char **argv) {

  std::string sa = "Was the string";
  std::string sb = std::move(sa);
  std::cout << "Old [" << sa << "] new [" << sb << "]" << std::endl;

  std::string sc = "s";
  std::string sd = std::move(sc);
  std::cout << "Old [" << sc << "] new [" << sd << "]" << std::endl;

  std::map<std::string, std::string> m1;
  std::map<std::string, std::string> m2;
  m1["hello"] = "world";
  m1["hello1"] = "world2";
  m2 = std::move(m1);
  std::cout << "Old [";
  for (auto entry : m1) {
    std::cout << entry.first << " " << entry.second << " ";
  }
  std::cout << "]" << std::endl;
  std::cout << "new [";
  for (auto entry : m2) {
    std::cout << entry.first << " " << entry.second << " ";
  }
  std::cout << "]" << std::endl;
}