#include <bits/stdc++.h> /* 万能头 */
#include <fmt/core.h>
using namespace std;
/* valgrind  ./a.out

==179646== Memcheck, a memory error detector
==179646== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==179646== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==179646== Command: ./a.out
==179646==
1
故意
==179646==
==179646== HEAP SUMMARY:
==179646==     in use at exit: 4 bytes in 1 blocks
==179646==   total heap usage: 5 allocs, 4 frees, 73,907 bytes allocated
==179646==
==179646== LEAK SUMMARY:
==179646==    definitely lost: 4 bytes in 1 blocks
==179646==    indirectly lost: 0 bytes in 0 blocks
==179646==      possibly lost: 0 bytes in 0 blocks
==179646==    still reachable: 0 bytes in 0 blocks
==179646==         suppressed: 0 bytes in 0 blocks
==179646== Rerun with --leak-check=full to see details of leaked memory
==179646==
==179646== For lists of detected and suppressed errors, rerun with: -s
==179646== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */
class foo {
public:
  foo() : a(new int(1)) {
    fmt::print("{:d}\n", *a);
    throw std::runtime_error("故意");
  }

  int *a;
};

int main() {
  try {
    foo f;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}