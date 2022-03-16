#include <bits/stdc++.h>
#include <optional>

using namespace std;

template <typename V, class Lock = std::mutex> class LRU {
public:
  LRU(int max_size) : maxSize(max_size) {}

  void insert(int key, V &&value) {
    lock_guard<Lock> g(m);

    auto iter = k2iter.find(key);
    if (iter != k2iter.end())
      kvs.erase(key);

    kvs.emplace_front(key, std::move(value));
    k2iter[key] = kvs.front();
    // 满了
    if (maxSize <= kvs.size())
      remove();
  }

  optional<V> get(int key) {
    lock_guard<Lock> g(m);

    auto iter = k2iter.find(key);
    if (iter != k2iter.end()) {
      auto value = iter->second->second;
      kvs.erase(key);
      kvs.emplace_front(key, std::move(value));
      k2iter[key] = kvs.front();
      return value;
    } else {
      return nullopt;
    }
  }

private:
  void remove() {
    while (kvs.size() > maxSize) {
      k2iter.erase(kvs.back().first);
      kvs.pop_back();
    }
  }

  Lock m;
  unordered_map<int, typename list<pair<int, V>>::iterator> k2iter;
  list<pair<int, V>> kvs;

  int maxSize;
};
