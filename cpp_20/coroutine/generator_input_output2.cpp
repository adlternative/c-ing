#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif

#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <coroutine>
#include <exception>
#include <iostream>
#include <string>

struct generator_input {};

template <typename OutputType, typename InputType> struct generator {
  struct promise_type;
  using coro_handle = std::coroutine_handle<promise_type>;
  struct promise_type {
    OutputType current_value;
    InputType input_value;

    struct yield_awaiter {
      InputType &input_value;
      bool await_ready() const noexcept { return false; }
      void await_suspend(std::coroutine_handle<> h) {}
      InputType &await_resume() const noexcept { return input_value; }
    };

    auto get_return_object() {
      return generator{coro_handle::from_promise(*this)};
    }

    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }

    auto yield_value(OutputType value) {
      current_value = value;
      return yield_awaiter{input_value};
    }

    void return_void() {}
  };
  /* 恢复协程 下一次返回的时候返回协程是否是 done (final_suspend)*/
  bool next() { return coro ? (coro.resume(), !coro.done()) : false; }
  OutputType value() { return coro.promise().current_value; }

  void send(const InputType &input) { coro.promise().input_value = input; }

  void send(InputType &&input) {
    /* future 可以从外界调用方向协程内部生产值 */
    coro.promise().input_value = std::move(input);
  }

  generator(generator const &rhs) = delete;
  generator(generator &&rhs) : coro(rhs.coro) { rhs.coro = nullptr; }
  ~generator() {
    if (coro)
      coro.destroy();
  }

private:
  generator(coro_handle h) : coro(h) {}
  coro_handle coro;
};

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

void main1() {
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

enum status {
  ok = 1,
  fail = 0,
  indeterminate = -1,
};

generator<status, char> consume(std::string &s, char c) {
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
  if (c == 'a')
    co_yield ok;
  else
    co_yield fail;
}
#include <tuple>
std::tuple<status, std::string::iterator> parse(std::string &req,
                                                std::string::iterator begin,
                                                std::string::iterator end) {
  if (begin != end) {
    auto h = consume(req, *begin++);
    while (h.next()) {
      auto result = h.value();
      if ((result == ok) || (result == fail))
        return std::make_tuple(result, begin);
      if (begin == end)
        break;
      h.send(*begin++);
    }
  }
  auto result = indeterminate;
  return std::make_tuple(result, begin);
}
void handle(std::string &s, std::string s2) {
  status sta;
  std::string::iterator i;

  std::tie(sta, i) = parse(s, s2.begin(), s2.end());
  if (sta == ok)
    std::cout << s << std::endl;
  else
    std::cout << "status= " << sta << std::endl;
}

void main2() {
  std::string s;
  std::string s2("bc123a");
  handle(s, s2);
  s2 = "bc3";
  handle(s, s2);
  s2 = "bc3a";
  handle(s, s2);
}

int main(int, char **) { main2(); }
