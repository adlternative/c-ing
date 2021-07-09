// senderReceiver.cpp

#include <atomic>
#include <chrono>
#include <coroutine>
#include <functional>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>

void log(std::string_view message, const std::source_location &location =
                                       std::source_location::current()) {
  std::cout << "info:" << location.file_name() << ":" << location.line() << " "
            << location.function_name() << message << '\n';
}

class Event {
public:
  Event() = default;

  Event(const Event &) = delete;
  Event(Event &&) = delete;
  Event &operator=(const Event &) = delete;
  Event &operator=(Event &&) = delete;

  class Awaiter;
  Awaiter operator co_await() const noexcept;

  void notify() noexcept;

private:
  friend class Awaiter;

  mutable std::atomic<void *> suspendedWaiter{nullptr};
  mutable std::atomic<bool> notified{false};
};

class Event::Awaiter {
public:
  Awaiter(const Event &eve) : event(eve) {}

  bool await_ready() const;
  bool await_suspend(std::coroutine_handle<> corHandle) noexcept;
  void await_resume() noexcept {}

private:
  friend class Event;

  const Event &event;
  std::coroutine_handle<> coroutineHandle;
};

bool Event::Awaiter::await_ready() const { // (7)

  // allow at most one waiter
  if (event.suspendedWaiter.load() != nullptr) {
    throw std::runtime_error("More than one waiter is not valid");
  }

  // event.notified == false; suspends the coroutine
  // event.notified == true; the coroutine is executed such as a usual function
  return event.notified;
}
// (8)
bool Event::Awaiter::await_suspend(std::coroutine_handle<> corHandle) noexcept {

  coroutineHandle = corHandle;

  if (event.notified)
    return false;

  // store the waiter for later notification
  event.suspendedWaiter.store(this);

  log("await_suspend");
  return true;
}

void Event::notify() noexcept { // (6)
  notified = true;

  // try to load the waiter
  auto *waiter = static_cast<Awaiter *>(suspendedWaiter.load());

  // check if a waiter is available
  if (waiter != nullptr) {
    // resume the coroutine => await_resume
    waiter->coroutineHandle.resume();
  }
}

Event::Awaiter Event::operator co_await() const noexcept {
  log("co_await");
  return Awaiter{*this};
}

struct Task {
  struct promise_type {
    Task get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
  };
};

Task receiver(Event &event) { // (3)
  auto start = std::chrono::high_resolution_clock::now();
  log("before await");
  co_await event;
  log("after await");
  std::cout << "Got the notification! " << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Waited " << elapsed.count() << " seconds." << std::endl;
}

using namespace std::chrono_literals;

int main() {

  std::cout << std::endl;

  // std::cout << "Notification before waiting" << std::endl;
  // Event event1{};
  // auto senderThread1 = std::thread([&event1] { event1.notify(); }); // (1)
  // auto receiverThread1 = std::thread(receiver, std::ref(event1));   // (4)

  // receiverThread1.join();
  // senderThread1.join();

  std::cout << std::endl;

  std::cout << "Notification after 2 seconds waiting" << std::endl;
  Event event2{};
  auto receiverThread2 = std::thread(receiver, std::ref(event2)); // (5)
  log("in main after create recv threads");
  while (1)
    ;
  auto senderThread2 = std::thread([&event2] {
    std::this_thread::sleep_for(2s);
    event2.notify(); // (2)
  });
  log("in main after create threads");
  receiverThread2.join();
  senderThread2.join();

  std::cout << std::endl;
}