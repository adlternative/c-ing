#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cstring>
#include<cassert>
#include <vector>
// #include"../cpplearn2/Sales_data.h"
// #include"../cpplearn2/Sales_item.h"
#include<list>
#include<deque>
#include<array>
#include<forward_list>
#include<unistd.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<unordered_set>
#include<unordered_map>
#include<memory>
#include"./测试5.cpp"
using namespace std;
using namespace std::placeholders;
using line_no =vector<string>::size_type;
int f(){return 1;}
int main()
{
    vector<int >vi(100);
    int &&r1=f();
    int &r2=vi[0];
    int &r3=r1;
    int &&r4=vi[0]*f();
}