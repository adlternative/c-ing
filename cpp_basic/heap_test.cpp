#include <bits/stdc++.h>
using namespace std;

void test1() { // Initializing a vector
  vector<int> v1 = {20, 30, 40, 25, 15};

  // Converting vector into a heap
  // using make_heap()
  make_heap(v1.begin(), v1.end());

  // Displaying the maximum element of heap
  // using front()
  cout << "The maximum element of heap is : ";
  cout << v1.front() << endl;

  // using push_back() to enter element
  // in vector
  v1.push_back(50);

  // using push_heap() to reorder elements
  push_heap(v1.begin(), v1.end());

  // Displaying the maximum element of heap
  // using front()
  cout << "The maximum element of heap after push is : ";
  cout << v1.front() << endl;

  // using pop_heap() to delete maximum element
  pop_heap(v1.begin(), v1.end());
  v1.pop_back();

  // Displaying the maximum element of heap
  // using front()
  cout << "The maximum element of heap after pop is : ";
  cout << v1.front() << endl;
}

void test2() {
  vector<int> v1 = {20, 30, 40, 25, 15};

  // Converting vector into a heap
  // using make_heap()
  make_heap(v1.begin(), v1.end());

  while (v1.size()) {
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();
  }
}

void test3() {
  vector<int> v1 = {20, 30, 40, 25, 15};

  // Converting vector into a heap
  // using make_heap()
  make_heap(v1.begin(), v1.end());

  auto len = v1.size();
  while (len) {
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
    pop_heap(v1.begin(), v1.begin() + len);
    len--;
  }
}

int main() {
  test3();
  return 0;
}
