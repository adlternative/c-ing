#include <bits/stdc++.h> /* 万能头 */
#include <fcntl.h>
#include <unistd.h>

using namespace std;

struct Fd {
  Fd(const Fd &) = delete;
  Fd &operator=(const Fd &) = delete;
  explicit Fd(int fd) : fd_(fd) {}

  Fd(Fd &&rhs) noexcept { fd_ = std::exchange(rhs.fd_, -1); }
  Fd &operator=(Fd &&rhs) noexcept {
    if (this != &rhs)
      fd_ = std::exchange(rhs.fd_, -1);
    return *this;
  }
  Fd &operator=(int fd) noexcept {
    if (fd_ != -1)
      close();
    fd_ = fd;
    return *this;
  }

  ~Fd() {
    if (fd_ != -1) {
      close();
    }
  }
  operator int() { return fd_; }
  int get_fd() { return fd_; }

protected:
  void close() {
    if (fd_ != -1)
      ::close(fd_);
  }
  int fd_ = -1;
};

int main(int argc, char **argv) {
  try {
    int fd;
    if ((fd = open("/tmp/a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
      throw std::system_error(errno, std::system_category(), "open");
    }
    Fd fd_(fd);
    int ret = write(fd_, "hello", 5);
    if (ret == -1)
      throw std::system_error(errno, std::system_category(), "write");
  } catch (std::system_error &e) {
    std::cout << e.what() << std::endl;
  } catch (std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}