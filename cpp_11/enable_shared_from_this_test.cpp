#include <bits/stdc++.h> /* 万能头 */
// #include <gtest/gtest.h>
#include <memory>
using namespace std;
class A : public enable_shared_from_this<A> {
public:
  A() {}
  shared_ptr<A> func() { return shared_from_this(); }
};

int main() {
  // TEST(shared_ptr, enable_shared_from_this) {
  auto a = make_shared<A>();
  if (a->func() == a)
    printf("ok");
}
