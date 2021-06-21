#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <coroutine>
#include <iostream>
#include <utility>

template <class T> struct task {
  struct promise_type;
  using handle = std::coroutine_handle<promise_type>;

  struct promise_type {
    auto get_return_object() { return task(handle::from_promise(*this)); }
    auto initial_suspend() { return std::suspend_always{}; }
    struct final_awaiter {
      bool await_ready() noexcept { return false; }
      void await_resume() noexcept {}
      /* 回到上一层的协程 */
      std::coroutine_handle<> await_suspend(handle h) noexcept {
        auto previous = h.promise().previous;
        if (previous) {
          return previous;
        } else {
          return std::noop_coroutine();
        }
      }
    };
    auto final_suspend() noexcept { return final_awaiter{}; }
    void unhandled_exception() { throw; }
    void return_value(T value) { result = std::move(value); }
    T result;
    /* 前一个协程 */
    std::coroutine_handle<> previous;
  };

  task(handle h) : coro(h) {}
  task(task &&t) = delete;
  ~task() { coro.destroy(); }

  struct awaiter {
    bool await_ready() { return false; }
    T await_resume() { return std::move(coro.promise().result); }
    /* h是当前协程的句柄 */
    auto await_suspend(std::coroutine_handle<> h) {
      coro.promise().previous = h;
      return coro;
    }
    handle coro;
  };
  awaiter operator co_await() { return awaiter{coro}; }
  T operator()() {
    coro.resume();
    return std::move(coro.promise().result);
  }

private:
  handle coro;
};

task<int> get_random() {
  std::cout << "in get_random()\n";
  co_return ::rand();
}

task<int> test() {
  task<int> v = get_random();
  task<int> u = get_random();
  std::cout << "in test()\n";
  int x = (co_await v + co_await u);
  co_return x;
}

int main() {
  task<int> t = test();
  int result = t();
  std::cout << result << '\n';
}