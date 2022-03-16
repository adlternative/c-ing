#include <bits/stdc++.h> /* 万能头 */
#include <unistd.h>
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

template <class T = milliseconds> class Timer {
public:
  Timer(const function<void()> &fn) : fn_(fn) {}
  Timer(function<void()> &&fn) noexcept : fn_(std::move(fn)) {}

  void operator()(ostream &os) {
    auto start = steady_clock::now();
    fn_();
    auto end = steady_clock::now();
    auto duration = duration_cast<T>(end - start);
    os << duration.count() << DurationTraits<T>::kText << endl;
  }

  function<void()> fn_;
};

int main() {

  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(rand() % 10000);

  Timer t([&]() {
    int count = 0;
    int lens = v.size();
    for (int i = 0; i < lens; i++) {
      if (v[i] > 5000) {
        count++;
      }
    }
  });
  t(cout);
}
