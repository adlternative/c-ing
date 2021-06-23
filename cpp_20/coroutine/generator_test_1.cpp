#include "generator_input_output2.hpp"
generator<char, std::string> hello(std::string word) {
  for (auto &ch : word) {
    if (ch == '#')
      break;
    else
      std::cout << ch << " ";
  }
  /* 切出一个e 新单词 */
  word = co_yield 'e';
  for (auto &ch : word) {
    if (ch == '#')
      break;
    else
      std::cout << ch << " ";
  }
}

int main() {
  /* init_suspend 获得 future(generator)对象 */
  auto test = hello("hello w#orld\n");
  /* 向协程内部发送内容 */
  /* 恢复协程，并取得协程是否done(final_suspend())
   *如果 done了咱们就结束，否则打印协程的内容 */
  if (test.next()) {
    std::cout << test.value() << ' ';
  }
  test.send("wha#t\n");
  if (test.next()) {
    std::cout << test.value() << ' ';
  }
}