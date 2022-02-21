#include <chrono>
#include <functional>
#include <ostream>

using namespace std;
using namespace std::chrono;

template <class T> struct DurationTraits;
template <> struct DurationTraits<milliseconds> {
  static constexpr auto kText = "ms"sv;
};
template <> struct DurationTraits<seconds> {
  static constexpr auto kText = "s"sv;
};

template <> struct DurationTraits<microseconds> {
  static constexpr auto kText = "mis"sv;
};

template <> struct DurationTraits<nanoseconds> {
  static constexpr auto kText = "ns"sv;
};

template <class T = seconds> class Timer {
public:
  Timer(const function<void()> &fn) : fn_(fn) {}
  Timer(function<void()> &&fn) : fn_(std::move(fn)) {}

  void operator()(ostream &os) {
    auto start = system_clock::now();
    fn_();
    auto end = system_clock::now();
    auto duration = duration_cast<T>(end - start);
    os << duration.count() << DurationTraits<T>::kText << endl;
  }

private:
  function<void()> fn_;
};
