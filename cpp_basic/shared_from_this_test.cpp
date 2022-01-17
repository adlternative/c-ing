#include <iostream>
#include <memory>

class A;

class B {
public:
  B(std::shared_ptr<A> &&a) : a_(std::move(a)) {}
  B() = default;
  void Print() { std::cout << "B" << std::endl; }

private:
  std::shared_ptr<A> a_;
};

class A : public std::enable_shared_from_this<A> {
public:
  A() = default;
  ~A() = default;
  void Print() { std::cout << "A" << std::endl; }
  B ToB() { return B(shared_from_this()); }
};

int main(int argc, char *argv[]) {
  // A *a = new A;
  std::shared_ptr<A> a_ptr = std::make_shared<A>();
  // a_ptr.reset(a);
  a_ptr->Print();
  auto B = a_ptr->ToB();
  B.Print();
}