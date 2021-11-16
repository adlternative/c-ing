#include <stdio.h>


int main(int argc, char *argv[]) {
  int b;
  {
    int a;
    a = 1;
    {
      int a;
      a = 1;
      {
        int a;
        a = 1;
      }
    }
  }
  b = 1;
}