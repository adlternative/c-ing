#ifndef TASK2_H
#define TASK2_H
#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif

#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <coroutine>
#include <stdexcept>

/**
 * @brief 我们需要思考的是我们的task切出|切入是想要干什么
 * 如果是 read | write 的非阻塞系统调用 去用 epoll 来做异步的
 * 我们是否应该让task 和 co_epoll 耦合

  co_await async_read //epoll监听EPOLLIN|EPOLLONESHOT|... 函数切出
  co_await async_write //epoll监听EPOLLOUT 函数切出

 */

struct task {
  struct promise_type;
  using coro_handle = std::coroutine_handle<promise_type>;
  struct promise_type {
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }
    void return_void() {}
    auto get_return_object() { return task{coro_handle::from_promise(*this)}; }
  };
  task() = default;
  task(task const &rhs) = delete;
  task(task &&rhs) : coro(rhs.coro) { rhs.coro = nullptr; }
  ~task() {
    if (coro)
      coro.destroy();
  }

private:
  task(coro_handle h) : coro(h) {}
  coro_handle coro;
};
#endif