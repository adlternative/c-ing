#include <functional>
#include <iostream>

using namespace std;

class Funs {

public:
  void Add(function<int(int)> &&f) { funs.push_back(std::move(f)); }
  void Do(int i) {
    for (auto &f : funs) {
      cout << f(i) << endl;
    }
  }

  vector<function<int(int)>> funs;
};

class C {
public:
  int Eat(int i) { return i; }

  void Add() {
    f.Add([this](int i) -> int { return Eat(i); });
  }
  void Do(int i) { f.Do(i); }
  Funs f;
  C() = default;
  C(const C &) = delete;
  C &operator=(const C &) = delete;
};

int main(int argc, char *argv[]) {
  C c;
  c.Add();
  c.Add();
  c.Do(1);
  return 0;
}