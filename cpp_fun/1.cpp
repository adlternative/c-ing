#include <stdio.h>

extern "C" {
struct aa {};

void func() { printf("%ld\n", sizeof(aa)); }
}
int main(int argc, char *argv[]) {
  int b;
  {
    int a;
    a = 1;
    {
      {
        aa a;
        printf("%ld\n", sizeof(aa));
        func();
      }
    }
  }
  b = 1;
}