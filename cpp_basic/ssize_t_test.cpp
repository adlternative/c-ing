#include <iostream> /*输入输出*/

#include <sys/types.h>/*  一堆类型*/
#include <sys/wait.h> /* 进程 wait */

#include <fcntl.h>   /* 文件操作 */
#include <sys/stat.h>/* 文件 stat */
#include <unistd.h>  /* 文件操作 */

#include <memory>/* 智能指针 */

#include <fmt/chrono.h> /* fmtlib */
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/os.h>
#include <fmt/ranges.h>

// #define SPDLOG_FMT_EXTERNAL
// #include <spdlog/spdlog.h>/* log */

#include <algorithm>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
/* stl */
#include <map>
#include <string>
#include <vector>
/* web */
#include <netinet/in.h>
#include <sys/socket.h>

// #include <gtest/gtest.h>

using namespace std;
int main(int argc, char *argv[]) {
  ssize_t t;
  t = 1;
  fmt::print("{}\n", t);
  // printf("%ld", t);
  t = -1;
  printf("%ld\n", t);
  // fmt::print("{}\n", t);
  t = -2;
  printf("%ld\n", t);
  // fmt::print("{}\n", t);
  size_t t2 = -2;
  if (t2 < 0)
    std::cout << "-1 < 0" << std::endl;
  ssize_t t3 = -1;
  if (t3 < 0)
    std::cout << "-1 < 0" << std::endl;

  ssize_t t4 = -2;
  if (t4 < 0)
    std::cout << "-2 < 0" << std::endl;
  t4 = t2;
  printf("%ld\n", t4);

  return 0;
}