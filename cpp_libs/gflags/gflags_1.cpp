#include <gflags/gflags.h>
#include <iostream>

DEFINE_string(name, "zhang san", "your name");
DEFINE_int32(age, 18, "your age");

int main(int argc, char **argv) {

  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::cout << "your name is : " << FLAGS_name << ", your age is: " << FLAGS_age
            << std::endl;
  return 0;
}
