#include <bits/stdc++.h> /* 万能头 */
#include <unordered_map>
using namespace std;
struct A {
  int a;
  string s;
  // A() = default;
  A(int aa, const string &ss) : a(aa), s(ss) {}
  bool operator==(const A &aa) const { return aa.a == a && aa.s == s; }
};

namespace std {

template <> // function-template-specialization
class hash<A> {
public:
  size_t operator()(const A &h) const {
    return hash<string>()(h.s) ^ hash<int>()(h.a);
  }
};
}; // namespace std

int main(int argc, char **) {
  unordered_map<A, int> mapp;
  mapp.insert(make_pair(A(1, "a"), 1));

  mapp.find(A(1, "a"));
}