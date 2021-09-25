#include <stdio.h>

/* only for gcc */

int (*mk_counter(int x))(void) {
  int inside(void) { return ++x; }
  return inside;
}

int main() {
  int (*counter)(void) = mk_counter(1);
  int x;
  x = counter();
  x = counter();
  x = counter();
  printf("%d\n", x);
  return 0;
}