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
#include <limits.h>
#include <netinet/in.h>
#include <sys/socket.h>
using namespace std;

std::string fd2name(int fd) {
  std::string path("/proc/self/fd/" + std::to_string(fd));
  char link[PATH_MAX];
  const ssize_t length =
      std::max<ssize_t>(readlink(path.c_str(), link, PATH_MAX), 0);
  return path.assign(link, length);
}
int main(int argc, char **argv) { std::cout << fd2name(1000) << std::endl; }