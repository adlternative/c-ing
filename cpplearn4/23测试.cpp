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
#include<tuple>
using namespace std;
using namespace std::placeholders;

int main()
{
    tuple<size_t,size_t,size_t>threeD;
    tuple<string,vector<double >,int,list<int>>somVal("constants",{3.14,2},42,{0,1,2,3,4});
    auto item=make_tuple("sda",2,1,1);
    auto book=get<0>(item);
    auto cnt=get<1>(item);
    auto price=get<2>(item)/cnt;
    get<2>(item)*=0.8;
    typedef decltype(item)trans;
    size_t sz=tuple_size<trans>::value;
    tuple_element<1,trans>::type  cnt=get<1>(item);
    tuple<int,int,int>t{10,20,30};
    vector<string>vs(20,"DAS");
    tuple<string,vector<string>,pair<string,int>>tt{"DAS",vs,make_pair<string,int>("DAS",1)};
    

    return 0;
}
