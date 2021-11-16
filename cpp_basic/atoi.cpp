#include <bits/stdc++.h> /* 万能头 */
#include <math.h>
using namespace std;
class A {
  int a;
};

class A2 : virtual public A {};
class A3 : virtual public A {};
class A4 : virtual public A2, A3 {};

void func(A *a) { printf("%p\n", a); }

int main() {
  A4 a;
  printf("%p\n", &a);
  func(&a);
}