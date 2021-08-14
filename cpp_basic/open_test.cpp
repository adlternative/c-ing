#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd = open(argv[1], O_RDONLY);
  struct stat st;
  fstat(fd, &st);
  close(fd);
}