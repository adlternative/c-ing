// strbuf_test2.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
  int len = 5;
  char *str = malloc(sizeof(char) * len);
  memcpy(str, "xiyou", 5);
  str = realloc(str, len + strlen("linux") + 1);
  strcpy(str + 5, "linux");
  printf("%s\n", str);
}
