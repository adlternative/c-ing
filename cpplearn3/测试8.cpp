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
#include"./测试5.cpp"
using namespace std;
using namespace std::placeholders;
int q=0;
static int s=0;
class Employee{
public:
    Employee():name(""),no(s++){}
    Employee(string sname):name(sname),no(s++){}
    Employee&operator=(const Employee&rhs){name=rhs.name;no=s++;}
    Employee(const Employee&rhs):name(rhs.name),no(s++){}
    void getNo(){cout<< no;}
private:
    string name;
    int no;
};
class HasPtr{
        friend void swap(HasPtr&lhs,HasPtr&rhs);

public:
    HasPtr(HasPtr&&p)noexcept:ps(p.ps),i(p.i){p.ps=nullptr;}
    HasPtr(const string&s=string()):i(0),ps(new string(s)){}
    HasPtr(const HasPtr&rhs):i(rhs.i),ps(new string(*(rhs.ps))){}
    HasPtr&operator=(HasPtr rhs){
       puts("operator=(HasPtr rhs)");
       this->swap(rhs);
        return *this;
    }
    // HasPtr&operator=(HasPtr&&rhs){
    //     puts("operator=(HasPtr&&rhs)");
    //     delete(ps);
    //     ps=std::move(rhs.ps);
    //     i=rhs.i;
    //     rhs.ps=nullptr;
    //     return *this;
    // }
    void swap(HasPtr&rhs){
            using std::swap;
            swap(i,rhs.i);
            swap(ps,rhs.ps);
            cout<<"swap2"<<endl;
    }
    bool operator<(const HasPtr&rhs){
        cout<<__func__<<endl;
        return *rhs.ps>*ps?true:rhs.i>i?true:false;
    }
    ~HasPtr(){cout<<__func__<<*ps<<endl; delete ps;}
    string&getPs()const{
        return *ps;
    }
private:
    string*ps;
    int i;
};
void swap(HasPtr&lhs,HasPtr&rhs){
    using std::swap;
    swap(lhs.i,rhs.i);
    swap(lhs.ps,rhs.ps);
    cout<<"swap1"<<endl;
}
void f( HasPtr*h1,HasPtr h2)
{
    HasPtr h3(*h1),h4(h2);
    
}
struct X
{
    
    X(string s=""):ps(new string(s)){cout<<__func__<<"none"<<endl;}
    X(const X&x):ps(new string(*(x.ps))),a(x.a){cout<<__func__<<"const X&"<<endl;}
    ~X(){delete(ps);cout<<__func__<<"none"<<endl;}
    X&operator=(const X&x){
        a=x.a;
        delete(ps);
        ps=new string(*(x.ps));
        cout<<__func__<<endl;
    }
    int a;
    string *ps;
};
X func(X*x1,X&x2,const X&x3,const X*x4,X x5){return *x1;}

class numberd
{
friend  void ff(const numberd &s);
private:
    int mysn;
public:
    numberd(int m=-1):mysn(m){}
    numberd(const numberd &rhs):mysn(q++){}
    ~numberd() {}
    numberd&operator=(const numberd&m){mysn=1+m.mysn;return *this;}
};
void ff(const numberd &s){cout<<s.mysn<<endl;}

int main()
{
    HasPtr h1("sad");
    HasPtr h2("s");
    HasPtr h3("a");
    vector<HasPtr>vh{h1,h2,h3};
    sort(vh.begin(),vh.end());
    for_each(vh.begin(),vh.end(),[](const HasPtr&h){cout<<h.getPs();});
    // Employee s;
    // Employee s1(s);
    // auto s2=s1;
    // s.getNo();
    // s1.getNo();
    // s2.getNo();

    // numberd a(3),c=a;
    // numberd b(2);
    //  b=a;
    // // numberd d=c;
    // ff(a);
    // ff(b);
    // ff(c);

    // X x("sad");
    // X x2(x);
    // x=x2;
    // func(&x,x,x,&x,x);
    // auto h1=HasPtr("sad"),h2=HasPtr("sad");
    // f(&h1,h2);
    // while(1);
}