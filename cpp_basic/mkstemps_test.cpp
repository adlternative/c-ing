#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <filesystem>
#include <iostream>

int main(int argc, char **argv) {
  static char tmpfile[] = "/tmp/adl_XXXXXX";
  int fd = mkstemp(tmpfile);
  if (fd == -1) {
    perror("mkstemp");
    return EXIT_FAILURE;
  }
  auto filename = std::filesystem::read_symlink(
      std::filesystem::path("/proc/self/fd/") / std::to_string(fd));
  printf("%s\n", filename.string().c_str());

  while (1)
    ;
  return 0;
}