#include "CoroutineUtils.hpp"
#include <coroutine>
#include <iostream>
#include <tuple>

struct FiboFuture : coroutine_base<FiboFuture> {
  /**
   * @brief 每个协程 future 对象必须实现的 promise_type
   * 让子类实现 yield_value, (return_value/return_void 二者选其一)
   * 协程自身的状态信息（形参，局部变量，自带数据，各个阶段点执行点）
   * 会被保存在堆上的Promise对象中
   */
  struct promise_type : promise_base_type<promise_type> {
    int value_;
    /**
     * @brief co_yield 调用
     *　co_yield = co_await promise.yield_value(expression);
     * @param value
     * @return auto
     */
    auto yield_value(int value) {
      value_ = value;
      return std::suspend_always{};
    }

    /**
     * @brief co_return hook调用
     * if (typeof <expr> == void)
     *      co_return <expr> = <expr>; promise.return_void()
     * else
     *      co_return <expr> = promise.return_value(<expr>)
     */
    // int return_value() { return value_ }
    void return_void() {}
  };

  FiboFuture(coroutine_handle<promise_type> handle) : co_handle_(handle) {}
  using coroutine_base::resume;
  /* 为接口提供值 */
  operator int() { return co_handle_.promise().value_; }
  /**
   * @brief 协程句柄
   * @function (static) from_promise 从promise获得一个协程句柄
   * @function address
   * @function from_address
   * @function done　判断协程是否结束
   * @function resume　恢复协程
   * @function destory 销毁协程
   * @function promise 获得其对应的 promise
   */
  coroutine_handle<promise_type> co_handle_{};
};

FiboFuture generate_fibo() {
  int i = 0, j = 1;
  while (true) {
    co_yield j;
    std::tie(i, j) = std::make_pair(j, i + j);
  }
}

int main(int argc, char **argv) {
  for (auto x = generate_fibo(); x < 1000; x.resume()) {
    std::cout << "fibo: " << x << std::endl;
  }

  return 0;
}