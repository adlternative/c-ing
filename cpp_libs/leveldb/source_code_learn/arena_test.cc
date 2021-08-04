#include "arena.h"
#include <iostream>

int main(int argc, char **argv) {
  leveldb::Arena arena;

  auto ptr = arena.AllocateAligned(1024 * 3 + 3);
  printf("ptr= %p\n", ptr);
  ptr = arena.AllocateAligned(1025);
  printf("ptr= %p\n", ptr);
  // ptr = new char[10111];
  // printf("ptr= %p\n", ptr);
  // ptr = new char('c');
  // printf("ptr= %p\n", ptr);
}