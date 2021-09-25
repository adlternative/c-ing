#include <bits/stdc++.h> /* 万能头 */

#include <algorithm>
#include <cstdint>
#include <string>
#include <type_traits>

// void FindShortestSeparator(std::string *start,
//                            const Slice &limit) const override {
//   // Find length of common prefix
//   size_t min_length = std::min(start->size(), limit.size());
//   size_t diff_index = 0;
//   /* 找到start和limit第一个不同的字符的坐标 */
//   while ((diff_index < min_length) &&
//          ((*start)[diff_index] == limit[diff_index])) {
//     diff_index++;
//   }

//   if (diff_index >= min_length) {
//     // Do not shorten if one string is a prefix of the other
//   } else {
//     uint8_t diff_byte = static_cast<uint8_t>((*start)[diff_index]);
//     if (diff_byte < static_cast<uint8_t>(0xff) &&
//         /* start[diff_index] + 1 < limit[diff_index] */
//         diff_byte + 1 < static_cast<uint8_t>(limit[diff_index])) {
//       (*start)[diff_index]++;        /* start[diff_index] ++ */
//       start->resize(diff_index + 1); /* start 压缩到出现不同的位置 + 1 ? */
//       assert(Compare(*start, limit) < 0);
//     }
//   }
// }

void FindShortSuccessor(std::string *key) {
  // Find first character that can be incremented
  size_t n = key->size();
  for (size_t i = 0; i < n; i++) {
    const uint8_t byte = (*key)[i];
    /* key 每一位 ++ */
    if (byte != static_cast<uint8_t>(0xff)) {
      (*key)[i] = byte + 1;
      /* 这个 resize 是想要干啥？ */
      key->resize(i + 1);
      return;
    }
  }
  // *key is a run of 0xffs.  Leave it alone.
}

using namespace std;
int main(int argc, char **argv) {
  std::string s("gggee");
  FindShortSuccessor(&s);
  s.clear();
  char mem[10];
  memset(mem, 0xff, sizeof(mem));
  s.append(mem, 10);
  s[3] = 66;
  FindShortSuccessor(&s);
  for (size_t i = 0; i < 10; i++) {
    std::cout << s[i] - 0xff << std::endl;
  }
  std::cout << 66 - 0xff << std::endl;
}