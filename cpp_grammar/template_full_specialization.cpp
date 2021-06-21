#include <bits/stdc++.h> /* 万能头 */
#ifndef __cpp_impl_coroutine
#define __cpp_impl_coroutine true
#endif
#if __cplusplus < 202002L
#undef __cplusplus
#define __cplusplus 202002L
#endif
using namespace std;

template <typename T = void> class FO {};
template <> class FO<int> {
public:
  FO() { std::cout << "全特化构造函数" << std::endl; }
};
template <> class FO<void> {
public:
  FO() { std::cout << "全特化构造函数" << std::endl; }
};

auto func(FO<> f) { std::cout << "???" << std::endl; }

int main(int argc, char **argv) {
  FO<int> f;
  // func(f);
}