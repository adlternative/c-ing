#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>

using namespace std;
void stream_copy(std::ostream &dst, std::istream &src) { dst << src.rdbuf(); }
// Return a named file's contents as a string
std::string load_file(char const *filepath) {
  std::ifstream src(filepath);
  std::ostringstream buf;
  buf << src.rdbuf();
  return buf.str();
}

// Stream redirecter.
class redirecter {
public:
  // Constructing an instance of this class causes
  // anything written to the source stream to be redirected
  // to the destination stream.
  redirecter(std::ostream &dst, std::ostream &src)
      : src(src), srcbuf(src.rdbuf()) {
    src.rdbuf(dst.rdbuf());
  }
  // The destructor restores the original source stream buffer
  ~redirecter() { src.rdbuf(srcbuf); }

private:
  std::ostream &src;
  std::streambuf *const srcbuf;
};
void hello_world() { std::cout << "Hello, world!\n"; }
#include <streambuf>

class teebuf : public std::streambuf {
public:
  // Construct a streambuf which tees output to both input
  // streambufs.
  teebuf(std::streambuf *sb1, std::streambuf *sb2) : sb1(sb1), sb2(sb2) {}

private:
  // This tee buffer has no buffer. So every character "overflows"
  // and can be put directly into the teed buffers.
  virtual int overflow(int c) {
    if (c == EOF) {
      return !EOF;
    } else {
      int const r1 = sb1->sputc(c);
      int const r2 = sb2->sputc(c);
      return r1 == EOF || r2 == EOF ? EOF : c;
    }
  }

  // Sync both teed buffers.
  virtual int sync() {
    int const r1 = sb1->pubsync();
    int const r2 = sb2->pubsync();
    return r1 == 0 && r2 == 0 ? 0 : -1;
  }

private:
  std::streambuf *sb1;
  std::streambuf *sb2;
};
class teestream : public std::ostream {
public:
  // Construct an ostream which tees output to the supplied
  // ostreams.
  teestream(std::ostream &o1, std::ostream &o2);

private:
  teebuf tbuf;
};

teestream::teestream(std::ostream &o1, std::ostream &o2)
    : std::ostream(&tbuf), tbuf(o1.rdbuf(), o2.rdbuf()) {}
int main(int argc, char **argv) {
  // stream_copy(cout, cin);
  // std::cout << load_file("./mutable_lambda.cpp") << std::endl;
  // std::ofstream log("hello-world.log");
  // redirecter redirect(log, std::cout);

  // std::ofstream log("oops.log");
  // std::cout.rdbuf(log.rdbuf());
  // std::cout << "Oops!\n";

  std::ofstream log("hello-world.log");
  teestream tee(std::cout, log);
  tee << "Hello, world!\n";
  return 0;
  // hello_world();
}