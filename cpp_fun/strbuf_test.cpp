#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string str("xiyou");
  str += "linux";
  printf("%s\n", str.c_str()); // xiyoulinux
}