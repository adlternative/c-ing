#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main(int argc, char **argv) {
  string s("\0\0\0\0\1", 6);
  for (int i = 0; i < 10; i++)
    s.append("\0\0\0\2\1",6);
  for (int i = 0; i < 40; i++) {
    printf("%d\n", s[i]);
  }
}