#include <bits/stdc++.h> /* 万能头 */
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(wchar_test, test1) {

  wstring s = L"这是abc";
  EXPECT_EQ(s.size(), 5);
}