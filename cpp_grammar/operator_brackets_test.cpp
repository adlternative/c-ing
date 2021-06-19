#include <bits/stdc++.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

template <typename T, std::size_t ROWS, std::size_t COLS> struct Matrix {
  T data[ROWS][COLS];

  T operator()(int x, int y) const { return data[x][y]; }

  T &operator()(int x, int y) { return data[x][y]; }

  template <typename... Args> auto get(Args &&...args) const {
    return this->operator()(std::forward<Args>(args)...);
  };
};

int main(int argc, char const *argv[]) {
  Matrix<int, 10, 20> m;

  m(5, 5) = 10;
  std::cout << m.get(5, 5) << std::endl;
  std::cout << m(5, 5) << std::endl;
  return 0;
}
