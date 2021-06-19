#include <iostream>

using namespace std;
/* 使用 mutable 后 lambda 中的 t 作为了 函数对象f 中的一个”成员“变量 */
int main() {
  size_t t = 9;
  auto f = [t]() mutable { return ++t; };
  cout << f() << endl;
  cout << f() << endl;
  cout << "t:" << t << endl;
  return 0;
}
