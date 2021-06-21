#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif

#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif

#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>

struct ReturnObject {
  struct promise_type {
    ReturnObject get_return_object() { return {}; }
    std::suspend_never initial_suspend() {
      /* 永不挂起 */
      return {};
    }
    std::suspend_never final_suspend() noexcept {
      /* 永不挂起 */
      return {};
    }
    void unhandled_exception() {}
  };
};

struct Awaiter {
  std::coroutine_handle<> *hp_;
  /* 告诉 co_await 自己好了没（好了就不用挂起了） */
  bool await_ready() const noexcept {
    std::cout << __func__ << std::endl;
    return false;
  }
  /* 可以返回 void, bool, std::coroutine_handle<P> 之一
   * 如果是 std::coroutine_handle<P> 这意味着暂停本协程的时候,
   * 可以恢复另一个协程（通过 resume）
   * 如果是 bool, 这意味着 await_suspend return false 就恢复自己 (不挂起)
   * 如果是 void 那么再 suspend 之后挂起本协程
   */
  void await_suspend(std::coroutine_handle<> h) {
    std::cout << __func__ << std::endl;
    *hp_ = h;
  }
  /* 告诉 co_await 挂起结束了该咋办 */

  /* await_resume这里的方法返回void，但如果它返回一个值，则该值将是co_await表达式的值。*/
  void await_resume() const noexcept { std::cout << __func__ << std::endl; }
};

ReturnObject counter(std::coroutine_handle<> *continuation_out) {
  std::cout << __func__ << std::endl;
  Awaiter a{continuation_out};
  for (unsigned i = 0;; ++i) {
    /* 挂起 */
    co_await a;
    std::cout << "counter: " << i << std::endl;
  }
}

void main1() {
  /* 这是一个协程句柄 */
  std::coroutine_handle<> h;
  /* 这是一个协程函数 */
  counter(&h);
  for (int i = 0; i < 10; ++i) {
    std::cout << "In main1 function\n";
    /* 协程恢复 */
    h();
  }
  /* 协程销毁 */
  h.destroy();
}

struct ReturnObject2 {
  struct promise_type {
    /* 将 promise 和 future 关联起来 */
    ReturnObject2 get_return_object() {
      return {// Uses C++20 designated initializer
              .h_ = std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };
  /* 将协程句柄放到 future 对象中 */
  std::coroutine_handle<promise_type> h_;
  operator std::coroutine_handle<promise_type>() const { return h_; }
  // A coroutine_handle<promise_type> converts to coroutine_handle<>
  operator std::coroutine_handle<>() const { return h_; }
};

ReturnObject2 counter2() {
  for (unsigned i = 0;; ++i) {
    co_await std::suspend_always{};
    std::cout << "counter2: " << i << std::endl;
  }
}

void main2() {
  /* 返回协程对应的句柄 */
  std::coroutine_handle<> h = counter2();
  for (int i = 0; i < 3; ++i) {
    std::cout << "In main2 function\n";
    h();
  }
  h.destroy();
}

struct ReturnObject3 {
  struct promise_type {
    unsigned value_;

    ReturnObject3 get_return_object() {
      return ReturnObject3{
          .h_ = std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };

  std::coroutine_handle<promise_type> h_;
  operator std::coroutine_handle<promise_type>() const { return h_; }
};

template <typename PromiseType> struct GetPromise {
  PromiseType *p_;
  bool await_ready() { return false; } // says yes call await_suspend
  bool await_suspend(std::coroutine_handle<PromiseType> h) {
    p_ = &h.promise();
    /* 不挂起 让 awaiter 获取 coroutine_handle*/
    return false; // says no don't suspend coroutine after all
  }
  PromiseType *await_resume() {
    /* 返回 promise (注意我们通过 await 来获得 协程的 coroutine_handle ) */
    return p_;
  }
};

ReturnObject3 counter3() {
  /* 注意我们在协程函数内部获得了协程 handle */
  auto pp = co_await GetPromise<ReturnObject3::promise_type>{};

  for (unsigned i = 0;; ++i) {
    pp->value_ = i;
    co_await std::suspend_always{};
  }
}

void main3() {
  /* 注意我们在协程函数调用获得了协程 handle */
  std::coroutine_handle<ReturnObject3::promise_type> h = counter3();
  ReturnObject3::promise_type &promise = h.promise();
  for (int i = 0; i < 3; ++i) {
    std::cout << "counter3: " << promise.value_ << std::endl;
    h();
  }
  h.destroy();
}

struct ReturnObject4 {
  struct promise_type {
    unsigned value_;

    ReturnObject4 get_return_object() {
      return {.h_ = std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
    std::suspend_always yield_value(unsigned value) {
      value_ = value;
      return {};
    }
  };

  std::coroutine_handle<promise_type> h_;
};

ReturnObject4 counter4() {
  for (unsigned i = 0;; ++i)
    co_yield i; // co yield i => co_await promise.yield_value(i)
}

void main4() {
  auto h = counter4().h_;
  auto &promise = h.promise();
  for (int i = 0; i < 3; ++i) {
    std::cout << "counter4: " << promise.value_ << std::endl;
    h();
  }
  h.destroy();
}

struct ReturnObject5 {
  struct promise_type {
    unsigned value_;

    ~promise_type() { std::cout << "promise_type destroyed" << std::endl; }
    ReturnObject5 get_return_object() {
      return {.h_ = std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
    std::suspend_always yield_value(unsigned value) {
      value_ = value;
      return {};
    }
    void return_void() {}
  };

  std::coroutine_handle<promise_type> h_;
};

ReturnObject5 counter5() {
  for (unsigned i = 0; i < 3; ++i)
    co_yield i;
  // falling off end of function or co_return; => promise.return_void();
  // (co_return value; => promise.return_value(value);)
}

void main5() {
  auto h = counter5().h_;
  auto &promise = h.promise();
  /* true if the coroutine is suspended at its final suspend point,
   * false if the coroutine is suspended at other suspend points. */
  while (!h.done()) { // Do NOT use while(h) (which checks h non-NULL)
    std::cout << "counter5: " << promise.value_ << std::endl;
    h();
  }
  h.destroy();
}

template <typename T> struct Generator {
  struct promise_type;
  using handle_type = std::coroutine_handle<promise_type>;

  struct promise_type {
    T value_;
    std::exception_ptr exception_;

    Generator get_return_object() {
      return Generator(handle_type::from_promise(*this));
    }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() { exception_ = std::current_exception(); }
    template <
        std::convertible_to<T> From> // C++20 concept 表示 From 可以转换成 T
    std::suspend_always yield_value(From &&from) {
      value_ = std::forward<From>(from);
      return {};
    }
    void return_void() {}
  };

  handle_type h_;

  Generator(handle_type h) : h_(h) {}
  ~Generator() { h_.destroy(); }

  /* 通过 if (future) 来抛出填充结果，
并返回协程是否在 final 挂起 */
  explicit operator bool() {
    fill();
    return !h_.done();
  }
  /* 通过 future() 来获取填充的数据并返回 */
  T operator()() {
    fill();
    full_ = false;
    return std::move(h_.promise().value_);
  }

private:
  bool full_ = false;

  void fill() {
    if (!full_) {
      /* 恢复协程 */
      h_();
      /* 如果出现了异常，抛出 */
      if (h_.promise().exception_)
        std::rethrow_exception(h_.promise().exception_);
      full_ = true;
    }
  }
};

Generator<unsigned> counter6() {
  for (unsigned i = 0; i < 3;)
    co_yield i++;
}

void main6() {
  auto gen = counter6();
  while (gen)
    std::cout << "counter6: " << gen() << std::endl;
}

int main() {
  // main1();
  // main2();
  // main3();
  // main4();
  // main5();
  main6();
}
