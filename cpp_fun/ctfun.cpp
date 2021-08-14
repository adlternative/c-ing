#include <iostream> /*输入输出*/

#include <sys/types.h>/*  一堆类型*/
#include <sys/wait.h> /* 进程 wait */

#include <cstring>   /* 字符串处理 */
#include <fcntl.h>   /* 文件操作 */
#include <memory>    /* 智能指针 */
#include <sys/stat.h>/* 文件 stat */
#include <unistd.h>  /* 文件操作 */

// #include <fmt/chrono.h> /* fmtlib */
// #include <fmt/color.h>
// #include <fmt/core.h>
// #include <fmt/os.h>
// #include <fmt/ranges.h>

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

using namespace std;
int main(int argc, const char **argv, const char **envp) {
  int v4;        // [rsp+Ch] [rbp-74h] BYREF
  char buf[16];  // [rsp+10h] [rbp-70h] BYREF
  char dest[8];  // [rsp+20h] [rbp-60h] BYREF
  __int64_t v7;  // [rsp+28h] [rbp-58h]
  int v8;        // [rsp+30h] [rbp-50h]
  char v9;       // [rsp+34h] [rbp-4Ch]
  char v10[56];  // [rsp+40h] [rbp-40h] BYREF
  __int64_t v11; // [rsp+78h] [rbp-8h]

  // v11 = __readfsqword(0x28u);
  setvbuf(stdout, 0LL, 2, 0LL);
  setvbuf(stdin, 0LL, 1, 0LL);
  *(long *)dest = 0x20676E6970LL;
  v7 = 0LL;
  v8 = 0;
  v9 = 0;
  v4 = 0;
  puts("Welcome to BJDCTF router test program! ");
  while (1) {
    puts("Please input u choose:");
    v4 = 0;
    scanf("%d", &v4);
    switch (v4) {
    case 1:
      puts("Please input the ip address:");
      read(0, buf, 0x10uLL);
      strcat(dest, buf);
      system(dest);
      puts("done!");
      break;
    default:
      puts("Functional development!");
      break;
    }
  }
}