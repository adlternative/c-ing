#include <gtest/gtest.h>
#include <string_view>

TEST(string_view, string1) {

  std::string_view s1 = "Hello";
  std::string_view s2 = "World";
  std::string_view s3 = "Hello World";

  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s2.size(), 5);
  EXPECT_EQ(s3.size(), 11);

  EXPECT_EQ(s1.length(), 5);
  EXPECT_EQ(s2.length(), 5);
  EXPECT_EQ(s3.length(), 11);

  EXPECT_EQ(s1.data(), "Hello");
  EXPECT_EQ(s2.data(), "World");
  EXPECT_EQ(s3.data(), "Hello World");

  EXPECT_EQ(s1.substr(0, 2), "He");
  EXPECT_EQ(s2.substr(0, 2), "Wo");
  EXPECT_EQ(s3.substr(0, 2), "He");

  EXPECT_EQ(s1.substr(2, 2), "ll");
  EXPECT_EQ(s2.substr(2, 2), "rl");
  EXPECT_EQ(s3.substr(2, 2), "ll");

  EXPECT_EQ(s1.substr(4, 2), "o");
  EXPECT_EQ(s2.substr(4, 2), "d");
  EXPECT_EQ(s3.substr(4, 2), "o ");

  EXPECT_EQ(s1.substr(5, 2), "");
  EXPECT_EQ(s2.substr(5, 2), "");
  EXPECT_EQ(s3.substr(5, 2), " W");

  EXPECT_EQ(s1.substr(0, 0), "");
  EXPECT_EQ(s2.substr(0, 0), "");
  EXPECT_EQ(s3.substr(0, 0), "");
}

TEST(string_view, string2) {
  constexpr std::wstring_view wcstr_v = L"xyzzy"; // overload (4)
  std::cout << "wcstr_v.size(): " << wcstr_v.size() << '\n';

  char array[3] = {'B', 'a', 'r'};
  std::string_view array_v(array, std::size(array)); // overload (3)
  std::cout << "array_v: " << quoted(array_v) << '\n';

  std::string cppstr = "Foo";
  std::string_view cppstr_v(cppstr); // (4), after string::operator const char*
  std::cout << "cppstr_v: " << quoted(cppstr_v) << '\n';

  std::array ar = {'P', 'u', 'b'};
  std::string_view ar_v(ar.begin(), ar.end()); // (5), C++20
  std::cout << "ar_v: " << quoted(ar_v) << '\n';

  //  std::string_view ar_v2{ar}; // (6), OK in C++23
  //  std::cout << "ar_v2: " << quoted( ar_v2 ) << '\n'; // ar_v2: "Pub"

  const char *one_0_two = "One\0Two";

  std::string_view one_v{one_0_two}; // (4)
  std::cout << "one_v: " << quoted(one_v) << ", one_v.size(): " << one_v.size()
            << '\n';

  std::string_view one_two_v{one_0_two, 7}; // (3)
  std::cout << "one_two_v: \"";
  for (char c : one_two_v) {
    std::cout << (c != '\0' ? c : '?');
  }
  std::cout << "\", one_two_v.size(): " << one_two_v.size() << '\n';
}