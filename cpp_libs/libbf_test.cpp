#include <bf/all.hpp>
// #include <gtest/gtest.h>
#include <bf/bitvector.hpp>
#include <iostream>
#include <string.h>
#include <string>

struct bf_test_case {
  std::string input;
  std::string output;
};

int main() {

  bf::basic_bloom_filter b(0.8, 100);

  // Add two elements.
  b.add("foo");
  b.add("4242");
  b.add("42");
  b.add("422");
  b.add("442");

  // bf_test_case bt;
  // b.add(bt);

  // Test set membership
  // // Remove all elements.
  std::cout << "-----" << std::endl;
  std::cout << b.lookup("foo") << std::endl; // 1
  std::cout << b.lookup(42) << std::endl;    // 0
  std::cout << "-----" << std::endl;
  const auto &v = b.storage().get_bits();
  char *storage = new char[v.size() * sizeof(size_t)];
  memcpy(storage, v.data(), v.size() * sizeof(size_t));
  for (size_t i = 0; i < v.size() * sizeof(size_t); i++) {
    std::cout << (int)storage[i] << std::endl;
  }

  bf::bitvector v2;
  std::vector<bf::bitvector::block_type> vv;


  v2.set_bits(storage, v.size() * sizeof(size_t));
  return 0;
}
