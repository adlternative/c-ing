#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int *use = 0;
/* g++ mem_leak_test.cpp -fsanitize=leak
not fine use!!!
*/

void malloc_no_free() {
  use = (int *)malloc(sizeof(int));
  *use = 1;
  printf("%d\n", *use);
  free(use);
  printf("hsakljkdaskldasjkln\n");
  use = NULL;
}

int *malloc_zero() {
  int *ret = (int *)malloc(0);
  // if (ret)
  //   printf("%p\n", ret);
  ret[1] = 1;
  ret[23] = 1;
  ret[25] = 1;
  ret[3000] = 1;
  return ret;
}

int main(int argc, char **argv) {
  // int *ret = malloc_zero();
  // printf("%d\n", ret[3000]);
  malloc_no_free();
  printf("bye\n");
  return 0;
}