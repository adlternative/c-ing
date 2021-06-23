#ifndef GENERATOR
#define GENERATOR
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

#endif
