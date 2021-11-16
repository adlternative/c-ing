#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main() {
  multiset<int> nums;
  std::pair<std::_Rb_tree_const_iterator<int>,
            std::_Rb_tree_const_iterator<int>>
      range;

  nums.insert(1);
  nums.insert(2);
  nums.insert(3);
  nums.insert(4);
  nums.insert(5);

  for (int i = 0; i < 10; i++) {
    nums.insert(2);
    range = nums.equal_range(2);
    for (auto iter = range.first; iter != range.second; iter++) {
      std::cout << &*iter << " ";
    }
    std::cout << std::endl;
  }
}