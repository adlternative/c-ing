#include <bits/stdc++.h> /* 万能头 */
#include <queue>

using namespace std;
class A {

public:
  A(int a) : a_(a) {}

  int GetA() const { return a_; }

private:
  int a_;
};
struct Cmp {
  bool operator()(const A &lhs, const A &rhs) {
    return lhs.GetA() > rhs.GetA();
  }
};

int main(int argc, char **argv) {
  priority_queue<A, vector<A>, Cmp> pq;
  pq.emplace(1);
  pq.emplace(2);
  pq.emplace(3);
  while (!pq.empty()) {
    std::cout << pq.top().GetA() << std::endl;
    pq.pop();
  }
}