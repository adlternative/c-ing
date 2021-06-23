#include "generator_input_output2.hpp"
#include <tuple>

enum status {
  ok = 0,
  indeterminate = 1,
  fail = -1,
};

generator<status, char> consume(std::string &s) {
  char c = co_await generator<status, char>::generator_input{};
  while (1) {
    if (c == 'b') {
      s += c;
      c = co_yield indeterminate;
    } else {
      co_yield fail;
    }
    if (c == 'c') {
      s += c;
      c = co_yield indeterminate;
    } else {
      co_yield fail;
    }
    if (c == '3') {
      s += c;
      c = co_yield indeterminate;
    } else {
      co_yield fail;
    }
    if (c == 'a') {
      s += c;
      c = co_yield ok;
    } else {
      co_yield fail;
    }
  }
}

class request_parser {
  bool running;
  generator<status, char> h;
  std::string &req_;

public:
  request_parser(std::string &req)
      : running(false), req_(req), h(consume(req)) {
    /* 从 init 恢复协程（协程马上调用 await 返回并等待值） */
    assert(h.next());
  }
  template <typename Iterator>
  std::tuple<status, Iterator> parse(Iterator begin, Iterator end) {
    running = true;
    while (begin != end) {
      std::cout << *begin << std::endl;
      h.send(*begin++);
      /* 协程final了（尽管这里是不可能的情况） */
      if (!h.next())
        break;
      auto result = h.value();
      // std::cout << result << std::endl;
      if ((result == ok) || (result == fail))
        return std::make_tuple(result, begin);
    }
    return std::make_tuple(indeterminate, begin);
  }
  void handle(std::string src) {
    // status sta;
    auto [sta, i] = parse(src.begin(), src.end());
    if (sta == ok) {
      std::cout << req_ << std::endl;
      req_.clear();
    } else
      std::cout << "status= " << sta << std::endl;
  }
};

void main2() {
  std::string req;
  request_parser rp(req);
  rp.handle("bc3a");
  rp.handle("bc3");
  rp.handle("a");
  rp.handle("bc");
  rp.handle("3a");
}

int main(int, char **) { main2(); }
