#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif
#include <chrono>
#include <coroutine>
#include <iostream>
#include <thread>
using namespace std;

struct my_future {
  struct promise_type;
  using handle = std::coroutine_handle<promise_type>;

  struct promise_type {
    int current_value;
    static auto get_return_object_on_allocation_failure() {
      return my_future{nullptr};
    }
    auto get_return_object() { return my_future{handle::from_promise(*this)}; }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }

    void return_value(int value) { current_value = value; }
    auto yield_value(int value) {
      current_value = value;
      return std::suspend_always{};
    }
  };
  bool move_next() { return coro ? (coro.resume(), !coro.done()) : false; }
  int current_value() { return coro.promise().current_value; }
  void resume() { coro.resume(); };
  my_future(my_future const &) = delete;
  my_future(my_future &&rhs) : coro(rhs.coro) { rhs.coro = nullptr; }
  ~my_future() {
    if (coro)
      coro.destroy();
  }

private:
  my_future(handle h) : coro(h) {}
  handle coro;
};

template <class Rep, class Period>
auto operator co_await(std::chrono::duration<Rep, Period> d) {
  struct awaiter {
    std::chrono::system_clock::duration duration;
    awaiter(std::chrono::system_clock::duration d) : duration(d) {}
    bool await_ready() const {
      std::cout << __func__ << std::endl;
      return duration.count() <= 0;
    }
    int await_resume() {
      std::cout << __func__ << std::endl;
      return 1;
    }
    void await_suspend(std::coroutine_handle<> h) {
      std::cout << __func__ << std::endl;
      std::this_thread::sleep_for(duration);
    }
  };
  return awaiter{d};
}

my_future sleep_coro() {
  printf("Start sleeping\n");
  co_await -1s;
  int ans = co_await 1s;
  printf("End sleeping, return value %d\n", ans);
}

int main() {
  auto h = sleep_coro();
  h.resume();
  h.resume();
}