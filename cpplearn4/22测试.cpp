#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cstring>
#include<cassert>
#include <vector>
#include"../cpplearn2/Sales_data.h"
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
// #include"./测试5.cpp"
#include<type_traits>
using namespace std;
using namespace std::placeholders;
template<typename T>void f(T){cout<<"fT"<<endl;}
template<typename T>void f(const T*){cout<<"fconstT"<<endl;}
template<typename T>void g(T){cout<<"gT"<<endl;}
template<typename T>void g(T*){cout<<"gT*"<<endl;}

void fl(int v1,int &v2)
{
    cout<<v1<<" "<<++v2<<endl;
}
void gl(int &&v1,int &v2)
{
    cout<<++v1<<" "<<++v2<<endl;
}
template<typename G,typename F,typename T1,typename T2>
void flip2(G g,F f,T1&&t1,T2&&t2)
{
    f(t2,t1);
    g(std::forward<T2>(t2),std::forward<T1>(t1));
    cout<<t1;
    // g(std::move(t2),t1);
}
template<typename T>
auto f(T i,T j)->decltype(j+i)
{
    return i+j;
}
template<typename It>
auto fcn(It beg,It end)->
typename remove_reference< decltype(*beg)>::type
{
    return *beg;
}
template<typename s,typename ... Args>void g(s a,Args ... args)
{cout<<sizeof ...(Args)<<endl;cout<<sizeof ...(args)<<endl;}
template<typename T>ostream&print(ostream&os,T&&t)
{
    return os<<t;
}
template<typename T,typename... Args>ostream&print(ostream&os,T&&t,Args&&...rest)
{
     os<<t<<",";
    return print(os,std::move(rest)...);
}
template<typename T>string debug_rep(const T&t)
{
    ostringstream ret;
    ret<<t;
    return ret.str();
}
template<typename T>string debug_rep(T*p)
{
    ostringstream ret;
    ret<<"pointer:"<<p;
    if(p)
        ret<<" "<<debug_rep(*p);
    else 
        ret<<"null pointer";
    return ret.str();
}
template<>
string debug_rep(const string &s)
{
    return '"'+s+'"';
}
template<>
string debug_rep(char*p)
{
    return debug_rep(string(p));
}
template<>
string debug_rep(const char*p)
{
    return debug_rep(string(p));
}
template<typename...Args>
ostream&errorMsg(ostream&os,const Args&...rest)
{
    return print(os,debug_rep(rest)...);
}
template<typename...Args>
void fun(Args&&...args)
{
    print(cout,std::forward<Args>(args)...);
}
template<typename T>
typename vector<T>::size_type count_vec(const vector<T>&v,typename vector<T>::value_type s)
{
    typename vector<T>::size_type count=0;
    for(auto i:v)
    {
        if(i==s)
        count++;
    }
    return count;
}
template<>
vector<const char*>::size_type count_vec(const vector<const char*>&v,vector<const char*>::value_type s)
{
    vector<const char*>::size_type count=0;
    for(const auto& i:v)
    {
        if(strcmp(i,s)==0)
            count++;
    }
    return count;
}

int main()
{
    
    vector<const char*>v(10,"SAd");
    // vector<const char*>::value_type
    cout<<count_vec(v,"SAd");
    unordered_multiset<Sales_data> SDset;
    Sales_data obj1( "C++Primer",  128, 68 );
    Sales_data obj2("sda",2,2);
    Sales_data obj3( obj1 );
    Sales_data obj4( obj2 );
    Sales_data obj5("sda",3,2);
 
    SDset.insert( obj1 );
    SDset.insert( obj2 );
    SDset.insert( obj3 );
    SDset.insert( obj4 );
    SDset.insert( obj5 );
 
    for( const auto &sd : SDset )
        cout << sd << endl;

    
    // auto a2=make_shared<int>(a);
    // fun("dsa","SAD");
    // errorMsg(cerr,"ASD","sda",1);
    // cout<<endl;
    // string s("hi");
    // cout<<debug_rep(s)<<endl;
    // print(cout,string("sad"),1,"sda",2,3,string("das"));
    // g("sad",1,2,3);
    // int i=42,*p=&i;
    // const int ci=0,*p2=&ci;
    
    // g(42);g(p);g(ci);g(p2);
    // f(42);f(p);f(ci);f(p2);

    // int j=1;
    // flip2(gl,fl,j,12);
    return 0;
}
