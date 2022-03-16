#include <bits/stdc++.h> /* 万能头 */
#include <gtest/gtest.h>

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

template <class T = microseconds> class Timer {
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

  function<void()> fn_;
};

TEST(bp, t1) {
  vector<int> v;
  for (int i = 0; i < 1000000; i++)
    v.push_back(rand() % 10000);
  Timer([&]() {
    int count = 0;
    int lens = v.size();
    for (int i = 0; i < lens; i++) {
      if (v[i] > 5000) {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t2) {
  vector<int> v;
  for (int i = 0; i < 1000000; i++)
    v.push_back(rand() % 10000);
  sort(v.begin(), v.end());
  Timer([&]() {
    int count = 0;
    int lens = v.size();
    for (int i = 0; i < lens; i++) {
      if (v[i] > 5000) {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t3) {
  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(rand() % 10000);
  Timer([&]() {
    int lens = v.size();
    int count = 0;
    for (int i = 0; i < lens; i++) {
      if (v[i] > 10000) [[likely]] {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t4) {
  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(rand() % 10000);
  Timer([&]() {
    int lens = v.size();
    int count = 0;
    for (int i = 0; i < lens; i++) {
      if (v[i] > 10000) [[unlikely]] {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t5) {
  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(rand() % 10000);
  Timer([&]() {
    int lens = v.size();
    int count = 0;
    for (int i = 0; i < lens; i++) {
      if (v[i] > 10000) {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t6) {
  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(i);
  Timer([&]() {
    int lens = v.size();
    int count = 0;
    for (int i = 0; i < lens; i++) {
      if (v[i] == 50000000) [[unlikely]] {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t7) {
  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(i);
  Timer([&]() {
    int lens = v.size();
    int count = 0;
    for (int i = 0; i < lens; i++) {
      if (v[i] == 50000000) [[likely]] {
        count++;
      }
    }
  })(cout);
}

TEST(bp, t8) {
  vector<int> v;
  for (int i = 0; i < 100000000; i++)
    v.push_back(i);
  Timer([&]() {
    int lens = v.size();
    int count = 0;
    for (int i = 0; i < lens; i++) {
      if (v[i] == 50000000) {
        count++;
      }
    }
  })(cout);
}