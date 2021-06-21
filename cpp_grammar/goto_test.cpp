#include <bits/stdc++.h> /* 万能头 */

using namespace std;
int func(int *a) {
  *a += 123;
  return *a;
}

int main(int argc, char **argv) {
  // goto end; err 跳过未初始化的变量
  int a = 2;
  int c = func(&a);
  printf("%d\n", c);
end:
  a = 2;
}