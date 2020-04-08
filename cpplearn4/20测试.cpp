// #pragma once
#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
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
using namespace std;
using namespace std::placeholders;
template<typename T/*=int*/,typename Q/*=less<T>*/>
int cmp(const T&v1,const T&v2,Q f=Q())
{
    if(f(v1,v2))return -1;
    if(f(v2,v1))return 1;
    return 0;
}
template<typename T>
int cmp2(const T&v1,const T&v2, less<T>f=less<T>())
{
    if(f(v1,v2))return -1;
    if(f(v2,v1))return 1;
    return 0;
}
typedef char Ctype;

template <typename Ctype> Ctype f5( Ctype a ){return a;}
template<typename T>void func(T&t)
{
    // for(typename T::size_type it=0;it!=t.size();it++)
    // {cout<<t[it];}
    for(typename T::iterator it=t.begin();it!=t.end();it++)
        cout<<*it;    
}
class DebugDelete{
public:
    DebugDelete(ostream&s=cerr):os(s){}
    template<typename T>void operator()(T*p)const
        {os<<"deleting unique_ptr"<<endl;delete p;}
private:
    ostream&os;
};
int main()
{
double *p=new double();
double *p2=new double(8.0);
double *p3=new double;
DebugDelete d;
d(p3);
int*ip=new int;
// d(ip);
DebugDelete()(ip);
unique_ptr<int,DebugDelete>pp(new int ,DebugDelete());

unique_ptr<string,DebugDelete>sp(new string ,DebugDelete());

    vector<int >v(19,2);
    func(v);
    // cout<<f5("sda");
    // cout<<"sad"[0];
    less<string>s;
    // cmp<>(1,2);
    // cmp<>("asd","sd");
    // less<string>s;
    // cmp<string>("1","2",    less<string>());
    cmp2<string>("AS","DAS",s);
    cmp<string,less<string>>("!","@");

    return 0;
}