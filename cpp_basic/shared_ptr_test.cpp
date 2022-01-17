#include <gtest/gtest.h>
#include <iostream>
#include <memory>

class T1 {
public:
  explicit T1(int i) : i_(i) {}
  int i_;
  int getI() { return i_; }
};
using namespace std;

TEST(shared_ptr, null) {
  auto t = make_shared<T1>(1);
  EXPECT_EQ(t->getI(), 1);
  shared_ptr<T1> t2 = nullptr;
  shared_ptr<T1> t3 = t2;
  if (t2.use_count() > 0) {
    EXPECT_EQ(t2.use_count(), 2);
  }
  EXPECT_FALSE(t3);
}