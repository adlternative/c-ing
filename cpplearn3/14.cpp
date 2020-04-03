#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cstring>
#include<cassert>
#include <vector>
#include"../cpplearn2/Sales_data.h"
#include"../cpplearn2/Sales_item.h"
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
class SmallInt{
    friend SmallInt operator+(const SmallInt&l,const SmallInt&r);
public:
    SmallInt(int s=0):val(s){}
    operator int()const{return val;}
private:
    std::size_t val;
};
SmallInt operator+(const SmallInt&l,const SmallInt&r)
{
    SmallInt sum;
    sum.val=l.val+r.val;
    return sum;
}
struct LongDouble{
    LongDouble operator+(const SmallInt&){}
};


class PrintString{
public:
    PrintString(ostream &o=cout,char c=' '):os(o),sep(c){}
    void operator()(const string &s)const {os<<s<<sep;}
private:
    ostream &os;
    char sep;
};
class IF_THEN_ELSE{
public:
    // IF_THEN_ELSE();
    int operator()(int a,int b,int c){if(a){return b;}else return c;}
private:
};
class GetString{
public:
    GetString(istream&i=cin):is(i){}
    string operator()(){string str; if(getline(is,str))return str;return string();}
private:
    string str;
    istream &is;
};
class Foo{
public:
    Foo&operator=(const Foo&)&;
};
Foo&Foo::operator=(const Foo&)&
{
    return *this;
}

struct X{
    int i;
    std::string s;
};
struct hasX{
    X mem;
};
struct Y{
    Y(){}
    Y(const Y&yy):y(new int(*yy.y)){}
    Y(Y&&yy)noexcept:y(yy.y){}
    int* y;
};
struct hasY{
    hasY()=default;
    hasY(hasY&&)=default;
    hasY(const hasY&ha):s(ha.s){}
    Y mem;
    int s;
};
hasY hy,hy2=std::move(hy);
// auto hy3(hy);
int f(){return 1;}
int main()
{
    SmallInt si;
    LongDouble ld;
    // ld=si+ld;
    ld=ld+si;
    double d=static_cast<double>(si)+3.13;
    auto d=si+static_cast<SmallInt>(3.13);
    // IF_THEN_ELSE ite;
    // cout<<ite(1,2,3);
    // string s1="ASD",s2="sad";
    // auto s3=(s1+s2);
    // s1+s2="ssad";
    // auto ff=(s1+s2).find('a');
    // cout<<(s1+s2)[ff];
    // cout<<ff<<endl;
    // X x,x2=std::move(x);
    // hasX hx,hx2=std::move(hx);
    // vector<int >vi(100);
    // int &&r1=f();
    // int &r2=vi[0];
    // int &r3=r1;
    // int &&r4=vi[0]*f();
    GetString gs;
    vector<string>svec;
    string ss;
    while((ss=gs())!=string())
        svec.push_back(ss);
    for_each(svec.begin(),svec.end(),PrintString(cout,'\n'));
    // Sales_data s1,s2;
    // cin>>s1>>s2;
    // cout<<s1<<endl<<s2<<endl;
}