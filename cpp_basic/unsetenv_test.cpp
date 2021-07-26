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

#define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>/* log */

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
using namespace std;
int main(int argc, char *argv[], char **env) {
  if (getenv("GG"))
    printf("ok");
  else
    printf("not ok");

  if (unsetenv("GG"))
    printf("ok");
  else
    printf("not ok");
  return 0;
}