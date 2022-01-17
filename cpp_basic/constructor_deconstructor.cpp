#include <bits/stdc++.h> /* 万能头 */

using namespace std;
struct S1 {
  ~S1() { printf("S1\n"); }
};

struct S2 {
  ~S2() { printf("S2\n"); }
};

int main(int argc, char **arg) {
  S1 s1;
  S2 s2;
}