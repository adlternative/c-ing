#include <bits/stdc++.h> /* 万能头 */

using namespace std;

class Cl {

  char c_;
  int a_;
  string b_;

public:
  Cl(char c, int a, const string &b) : c_(c), a_(a), b_(b) {}
  Cl(const Cl &x) : c_(x.c_), a_(x.a_), b_(x.b_) {}

  Cl &operator=(const Cl &x) {
    c_ = x.c_;
    a_ = x.a_;
    b_ = x.b_;
    return *this;
  }
  friend ostream &operator<<(ostream &os, const Cl &cl);
  friend class hash<Cl>;

  bool operator<(const Cl &rhs) const {
    if (c_ < rhs.c_)
      return true;
    else if (c_ == rhs.c_) {
      if (a_ < rhs.a_)
        return true;
      else if (a_ == rhs.a_)
        return b_ < rhs.b_;
    }
    return false;
  }

  bool operator==(const Cl &rhs) const {
    return a_ == rhs.a_ && b_ == rhs.b_ && c_ == rhs.c_;
  }
};

ostream &operator<<(ostream &os, const Cl &cl) {
  os << cl.c_ << " " << cl.a_ << " " << cl.b_;

  return os;
}

namespace std {

template <> struct hash<Cl> {
  size_t operator()(const Cl &cl) const {
    return hash<char>()(cl.c_) ^ hash<int>()(cl.a_) ^ hash<string>()(cl.b_);
  }
};
} // namespace std

int main(int argc, char **argv) {

  map<Cl, int> Cltc;
  unordered_map<Cl, int> Cltc2;
  Cl c1('a', 1, "Ad");
  Cltc[c1] = 1;
  Cltc2[c1] = 1;
  Cl c2('a', 2, "Ad");
  Cltc[c2] = 233;
  Cltc2[c2] = 233;

  for (const auto &c : Cltc) {
    std::cout << "Cl =" << c.first << " cout =" << c.second << std::endl;
  }
  for (const auto &c : Cltc2) {
    std::cout << "Cl =" << c.first << " cout =" << c.second << std::endl;
  }
}