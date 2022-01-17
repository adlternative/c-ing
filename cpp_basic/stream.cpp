#include <iostream>
#include <sstream>

using namespace std;
int main(int argc, char **argv) {
  stringstream ss;
  ss << 1 << "asd" << 2;
  std::cout << ss.str() << std::endl;
  return 0;
}