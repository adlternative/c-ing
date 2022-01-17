#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include <openssl/sha.h>

string sha256(const string str) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);
  stringstream ss;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    ss << hex << setw(2) << setfill('0') << (int)hash[i];
    // printf("%02x", hash[i]);
  }
  return ss.str();
}

void hex_to_sha256_digit(string_view hex, unsigned char *hash) {
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    hash[i] = (unsigned char)stoi(string(hex.substr(2 * i, 2)), nullptr, 16);
  }
}

TEST(sha256, sha256) {
  cout << sha256("test") << endl;

  cout << sha256("test2") << endl;
}

TEST(sha256, sha256hex_to_sha256_digit) {
  unsigned char sha256_digit_[SHA256_DIGEST_LENGTH];

  hex_to_sha256_digit(
      "7e0f4af9e448d1450f4c405ba5d978275cccacfe7c57746a5a0bd65d27d45644",
      sha256_digit_);
  EXPECT_EQ(sha256_digit_[0], 0x7e);
  EXPECT_EQ(sha256_digit_[1], 0x0f);
}
