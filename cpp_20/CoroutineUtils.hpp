#pragma once

#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif
#include <coroutine>
#include <exception>

/**
 * @brief 协程基类
 * 模板参数future是子类供外界调用，作为协程函数的返回值
 * @tparam Future
 */
template <typename Future> class coroutine_base {
  /**
   * @brief Get the future object
   * 获得子类future实体引用
   * @return Future&
   */
  Future &get_future() { return static_cast<Future &>(*this); }

protected:
  using suspend_never = std::suspend_never;
  using suspend_always = std::suspend_always;
  template <typename... U> using coroutine_handle = std::coroutine_handle<U...>;
  /**
   * @brief promise_base_type promise 基类
   * 需要实现 initial_suspend, final_suspend, get_return_object,
   * unhandled_exception, return_value, return_void, yield_value 基类已经实现
   * initial_suspend, final_suspend, get_return_object, unhandled_exception
   * 让子类实现 yield_value, (return_value/return_void 二者选其一)
   * @tparam Promise
   */
  template <typename Promise> struct promise_base_type {
    /**
     * @brief 协程开始的hook函数
  　 * 返回一个awaiter对象(需要实现 await_suspend，await_ready await_resume)
     *
     * @return awaiter
     */
    auto initial_suspend() { return suspend_never{}; }
    /**
     * @brief 协程结束的hook函数
  　 * 返回一个awaiter对象(需要实现 await_suspend，await_ready await_resume)
     *
     * @return awaiter
     */
    auto final_suspend() noexcept { return suspend_always{}; }
    /**
     * @brief 协程返回到调用者时的返回内容 （不需要与协程函数的返回类型相同）
     * 这里从自己(promise)返回一个future
     * @return Future
     */
    Future get_return_object() {
      return coroutine_handle<Promise>::from_promise(
          static_cast<Promise &>(*this));
    }
    /**
     * @brief 异常处理
     *
     */
    void unhandled_exception() { std::terminate(); }
  };
  /**
   * @brief 恢复协程
   *
   */
  void resume() {
    if (!get_future().co_handle_.done())
      get_future().co_handle_.resume();
  }

public:
  ~coroutine_base() { get_future().co_handle_.destroy(); }
};

/*
Awaiter

  struct suspend_always
  {
    constexpr bool await_ready() const noexcept { return false; }

    constexpr void await_suspend(coroutine_handle<>) const noexcept {}

    constexpr void await_resume() const noexcept {}
  };

  struct suspend_never
  {
    constexpr bool await_ready() const noexcept { return true; }

    constexpr void await_suspend(coroutine_handle<>) const noexcept {}

    constexpr void await_resume() const noexcept {}
  };


 */