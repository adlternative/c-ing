#include <bits/stdc++.h> /* 万能头 */

using namespace std;
inline void EncodeFixed32(char *dst, uint32_t value) {
  uint8_t *const buffer = reinterpret_cast<uint8_t *>(dst);

  // Recent clang and gcc optimize this to a single mov / str instruction.
  buffer[0] = static_cast<uint8_t>(value);
  buffer[1] = static_cast<uint8_t>(value >> 8);
  buffer[2] = static_cast<uint8_t>(value >> 16);
  buffer[3] = static_cast<uint8_t>(value >> 24);
}

void PutFixed32(std::string *dst, uint32_t value) {
  char buf[sizeof(value)];
  EncodeFixed32(buf, value);
  dst->append(buf, sizeof(buf));
}

inline uint32_t DecodeFixed32(const char *ptr) {
  const uint8_t *const buffer = reinterpret_cast<const uint8_t *>(ptr);

  // Recent clang and gcc optimize this to a single mov / ldr instruction.
  return (static_cast<uint32_t>(buffer[0])) |
         (static_cast<uint32_t>(buffer[1]) << 8) |
         (static_cast<uint32_t>(buffer[2]) << 16) |
         (static_cast<uint32_t>(buffer[3]) << 24);
}

int main(int argc, char **argv) {
  std::string s;
  for (uint32_t v = 0; v < 20; v++) {
    PutFixed32(&s, v);
  }
  const char *p = s.data();
  for (uint32_t v = 0; v < 20; v++) {
    uint32_t actual = DecodeFixed32(p);
    std::cout << actual << std::endl;
    p += sizeof(uint32_t);
  }

  // std::cout << s << std::endl;
}