#include <bits/stdc++.h> /* 万能头 */
#include <gtest/gtest.h>

using namespace std;

TEST(map, erase_and_iter_fail) {
  map<int, int> m;
  for (int i = 0; i < 10; i++)
    m[i] = i;

  for (auto iter = m.begin(); iter != m.end();) {
    if (iter->second == 4) {
      iter = m.erase(iter);
    } else {
      iter++;
    }
  }

  for (auto iter = m.begin(); iter != m.end(); iter++)
    EXPECT_NE(iter->first, 4);
}

TEST(multimap, erase_and_iter_fail) {
  multimap<int, int> m;
  for (int i = 0; i < 10; i++)
    m.emplace(i, i);

  for (auto iter = m.begin(); iter != m.end();) {
    if (iter->second == 4) {
      iter = m.erase(iter);
    } else {
      iter++;
    }
  }
  for (auto iter = m.begin(); iter != m.end(); iter++)
    EXPECT_NE(iter->first, 4);
}
