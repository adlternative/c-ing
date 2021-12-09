#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main() {
  vector items = {1, 2, 3};
  // pair pa(4, "string"); 不直接匹配字符串
  pair pa(4, string("hihi"));
  cout << pa.second << " " << items[2] << endl;
}