// main.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *m = (char *)malloc(3);
  strcpy(m, "he");
  printf("%s\n", m);
  free(m);
  int *array = new int[10];
  memset(array, 0, 10 * sizeof(int));
  delete[] array;
}