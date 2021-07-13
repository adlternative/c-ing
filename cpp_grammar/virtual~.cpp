#include <iostream>
#include <memory>
#include <vector>
namespace T1 {
struct A {
  A() { std::cout << "A" << std::endl; }
  ~A() { std::cout << "~A" << std::endl; }
};

struct Base {
  ~Base() { std::cout << "~Base" << std::endl; }
};

struct Derived : Base {
  A a;
  ~Derived() { std::cout << "~Derived" << std::endl; }
};
} // namespace T1

namespace t2 {
#include <iostream>
#include <memory>
#include <vector>

struct A {
  A() { std::cout << "A" << std::endl; }
  ~A() { std::cout << "~A" << std::endl; }
};

struct Base {
  ~Base() { std::cout << "~Base" << std::endl; }
};

struct Derived : Base {
  A a;
  ~Derived() { std::cout << "~Derived" << std::endl; }
};

} // namespace t2
int main() {
  std::unique_ptr<T1::Base> ptr(new T1::Derived);
  std::shared_ptr<t2::Base> ptr2(new t2::Derived);
}