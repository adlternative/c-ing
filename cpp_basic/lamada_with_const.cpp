#include <bits/stdc++.h> /* 万能头 */

using namespace std;

void test(const string &str) {
  auto fun = [&str]() { std::cout << str << std::endl; };
  fun();
}

int main(int argc, char **argv) {
  string s("asd");
  test(s);
}