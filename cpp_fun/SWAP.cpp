#include <bits/stdc++.h> /* 万能头 */

using namespace std;
#define SWAP(a, b)                                                             \
  do {                                                                         \
    void *_swap_a_ptr = &(a);                                                  \
    void *_swap_b_ptr = &(b);                                                  \
    unsigned char _swap_buffer[sizeof(a)];                                     \
    memcpy(_swap_buffer, _swap_a_ptr, sizeof(a));                              \
    memcpy(_swap_a_ptr, _swap_b_ptr, sizeof(a));                               \
    memcpy(_swap_b_ptr, _swap_buffer, sizeof(a));                              \
  } while (0)
struct strbuf {
  size_t alloc;
  size_t len;
  char *buf;
};
int main(int argc, char **argv) {
  std::cout << sizeof(strbuf) << std::endl;
  strbuf *a = new strbuf;
  a->alloc = 1;
  a->len = 2;
  strbuf *b = new strbuf;
  b->alloc = 2;
  b->len = 1;

  SWAP(*a, *b);
  std::cout << a->alloc << b->alloc << std::endl;
}