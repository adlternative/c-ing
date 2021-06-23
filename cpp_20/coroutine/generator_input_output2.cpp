#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif

#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <cassert>
#include <coroutine>
#include <exception>
#include <iostream>
#include <string>
/**
 * @brief 可输出可输出生成器
 *
 * @tparam OutputType 输出类型
 * @tparam InputType 输入类型
 */
template <typename OutputType, typename InputType> struct generator {
  struct promise_type;
  using coro_handle = std::coroutine_handle<promise_type>;

  struct generator_input {};

  struct promise_type {
    OutputType current_value; /* 协程内部通过 await/ yield 输出值 */
    InputType input_value;    /* 协程外界通过 await/ yield 输入值 */
    struct yield_awaiter {
      InputType &input_value;
      /**
       * @brief 需要挂起并从协程外部获取值
       */
      bool await_ready() const noexcept { return false; }
      void await_suspend(coro_handle) {}
      InputType &await_resume() const noexcept { return input_value; }
    };
    /**
     * @brief 强制指定 await generator_input{}
     * 使用 yield_awaiter挂起 然后外部 send and resume 返回给协程内部
     * input_value
     * @return yield_awaiter
     */
    auto await_transform(generator_input) { return yield_awaiter{input_value}; }

    auto get_return_object() {
      return generator{coro_handle::from_promise(*this)};
    }
    /**
     * @brief initial_suspend 和 final_suspend 都默认挂起
     * @return auto
     */
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }
    /**
     * @brief 向外界提供值
     *
     * @param value 输出值
     * @return yield_awaiter
     */
    auto yield_value(OutputType value) {
      current_value = value;
      return yield_awaiter{input_value};
    }

    void return_void() {}
  };
  /* 恢复协程 下一次协程切出的时候返回协程是否是 done (final_suspend)*/
  bool next() { return coro ? (coro.resume(), !coro.done()) : false; }
  /* 获取协程切出值 */
  OutputType value() { return coro.promise().current_value; }
  /* 向协程发送值 */
  void send(const InputType &input) { coro.promise().input_value = input; }
  /* 向协程发送值的右值版本 */
  void send(InputType &&input) {
    /* future 可以从外界调用方向协程内部生产值 */
    coro.promise().input_value = std::move(input);
  }

  generator() {}
  generator(generator const &rhs) = delete;
  generator(generator &&rhs) : coro(rhs.coro) { rhs.coro = nullptr; }
  ~generator() {
    if (coro)
      coro.destroy();
  }

private:
  /* 协程构造（留给编译器） */
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
#include <tuple>

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
