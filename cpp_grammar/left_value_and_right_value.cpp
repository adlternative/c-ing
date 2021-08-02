#include <bits/stdc++.h> /* 万能头 */
// #include <fmt/core.h>
using namespace std;

class temp {
public:
  explicit temp(const string &ss) noexcept : s(ss) {
    printf("temp(const string &ss)\n");
  }
  explicit temp(string &&ss) noexcept : s(std::move(ss)) {
    printf("temp(string &&ss)\n");
  }
  temp(temp &&rhs) noexcept { printf("temp(temp &&rhs)\n"); }
  temp(const temp &rhs) { printf("temp(const temp &rhs)\n"); }

  temp &operator=(temp &&rhs) noexcept {
    printf("temp &operator=(temp &&rhs)\n");
    return *this;
  }
  temp &operator=(const temp &rhs) noexcept {
    printf("&operator=(const temp &rhs)\n");
    return *this;
  }

  ~temp() noexcept { printf("~temp()\n"); }
  string get_string() const noexcept { return s; }
  string s;
};

std::vector<temp> test() {
  std::vector<temp> ret;
  /* temp(string &&ss) */
  temp t1("asd");
  string s("bbb");
  /* temp(const string &ss) */
  temp t2(s);
  /* temp(const temp &rhs) */
  ret.push_back(t1);
  ret.pop_back();
  /* temp(temp &&rhs) */
  ret.push_back(std::move(t2));
  printf("===========\n");
  return ret;
  // ~temp()
  // temp(const temp &rhs)

  // ~temp()
  // temp(const temp &rhs)
}

temp test2() {
  temp t1("asd");
  std::cout << &t1 << std::endl;
  return t1;
}

int main(int argc, char *argv[]) {
  // auto ret = test();
  // printf("===========\n");
  // for (auto &&t : ret) {
  //   printf("%s\n", t.get_string().c_str());
  // }
  auto temp = test2();
  std::cout << &temp << std::endl;
  temp.get_string();
}