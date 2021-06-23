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

  struct passthru_value {
    InputType &ret_;

    bool await_ready() { return true; }
    void await_suspend(coro_handle) {}
    InputType &await_resume() { return ret_; }
  };

  struct promise_type {
    OutputType current_value;
    InputType input_value;

    auto get_return_object() {
      return generator{coro_handle::from_promise(*this)};
    }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }
    auto yield_value(OutputType value) {
      current_value = value;
      return std::suspend_always{};
    }

    void return_void() {}
    /**
     * @brief 这里定制了一波 await(<expr>) -> promise->await_transform(<expr>)
     *
     * @return auto
     */
    auto await_transform(generator_input) {
      return passthru_value{input_value};
    }
  };
  /* 恢复协程 */
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

generator<char, std::string> hello() {
  auto word = co_await generator_input{};

  for (auto &ch : word) {
    co_yield ch;
  }
}

int main(int, char **) {

  /* init_suspend 获得 future(generator)对象 */
  auto test = hello();
  /* 向协程内部发送内容 */
  test.send("hello world");
  /* 恢复协程，并取得协程是否done(final_suspend())
   *如果 done了咱们就结束，否则打印协程的内容 */
  while (test.next()) {
    std::cout << test.value() << ' ';
  }
}
