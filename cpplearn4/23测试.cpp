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
// #include"./测试5.cpp"
#include<tuple>
#include<regex>
using namespace std;
using namespace std::placeholders;
void exercise(int*b,int*e)
{
    vector<int>v(b,e);
    int*p=new int[v.size()];
    auto s=shared_ptr<int>(p);
    try
    {
       ifstream in("ints");
       if(!in)throw runtime_error("open error");
     /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        // exit(EXIT_FAILURE);
        // delete[]p;
        // cout<<"p没重复释放吗"<<endl;
    }
    
}
// namespace Ex{
//         int i=3;
//         double d=3;
// };
//     int i=0;
// void m()
// {
//     using namespace Ex;
//     // using Ex::d;
//     // using Ex::i;
//     cout<<i<<" "<<d<<endl;
//     // int i=0;
//     // double d=0;
//     // cout<<i<<" "<<endl;   
// }
 class sss{
public:
    static const string sss::*data(){return &sss::a;}
    int as=0;
    int qs(int a)const{return a;}
    const string sss::*pdata=sss::data();
    sss(const string &s):a(s){}
private:
    string a;
} ;
using action= int (sss::*)(int a)const ;
sss&aa(sss&f,action ssss=&sss::qs){
    (f.*ssss)(2);
    return f;
}
class screen{
public:
    using Action =screen&(screen::*)();
    screen&home();
    screen&forward();
    screen&back();
    screen&up();
    screen&down();
    enum Directions{HOME,FORWORD,BACK,UP,DOWN};
    screen&move(Directions);
private:
    static Action Menu[];
};
screen& screen::move(Directions cm)
{
        return (this->*Menu[cm])();
}
screen::Action screen::Menu[]={&screen::home,&screen::forward,&screen::back,
    &screen::up,&screen::down};
int main()
{
    screen myscreen;
    myscreen.move(screen::HOME);
    action get=&sss::qs;
    auto pqs=&sss::qs;   
    int sss::*ipata;
    ipata=&sss::as;
    sss s("da"),*ps=&s;
    aa(s,get);
    cout<<(s.*get)(1);
    // cout<<s.*ipata;
    // printf("%p",s.*ipata);
    // printf("%p",ps->*ipata);
    // int sss::as
    // auto pp=&sss::as;
    
    // printf("%p",    pp);
    // cout<<(s.pdata)<<endl;
    // auto p=s.pdata;
    // cout<<*p;
    // m();
    // cout<<i<<" "<<d<<endl;
    // int b[]={1,2,3,4,5};
    // exercise(begin(b),end(b));
    // cout<<"ok"<<endl;
    // range_error r("error");// what():  error
    // // throw r;
    // exception*p=&r;// what():  std::exception
    // throw *p;

    // string pattern("[^c]ei");
    // pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    // regex r(pattern);
    // // regex r2;
    // try{
    // smatch result2;
    //  string sss("a.cpp b.cpp c.cc d.cxx");
    // regex r2("([[:alnum:]]+)\\.(cpp|cxx|cc)$",regex::icase);
    // //Unexpected end of character class.
    // if(regex_search(sss,result2,r2))
    // cout<<result2.str(0)<<"  ";
    // cout<<result2.str(1)<<"  ";
    // cout<<result2.str(2)<<"  ";

    // }catch(regex_error e)
    // {cout<<e.what()<<"\ncode:"<<e.code()<<endl;}
    // regex r3("[[:alnum:]]+\\.(cpp|cxx|cc)$",regex::icase);
    
    // smatch result;
    // string test_str="receipt freind freind fweind  theif receive";
    // if(regex_search(test_str,result,r))
    //     cout<<result.str()<<endl;
    //     cout<<result.length(0);
    //     cout<<result.size();
    //     cout<<result.str(0)<<endl;
    //     cout<<result.str(1)<<endl;
    //     cout<<result.str(2)<<endl;
    // for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_;it!=end_;++it)
    // {
    //     auto pos=it->prefix().length();
    //     pos=pos>40?pos-40:0;
    //     cout<<it->prefix().str().substr(pos)
    //     <<"\n\t\t>>>"<<it->str()<<"<<<\n"<<it->suffix().str().substr(0,40)<<endl;

    // }
    // tuple<size_t,size_t,size_t>threeD;
    // tuple<string,vector<double >,int,list<int>>somVal("constants",{3.14,2},42,{0,1,2,3,4});
    // auto item=make_tuple("sda",2,1,1);
    // auto book=get<0>(item);
    // auto cnt=get<1>(item);
    // auto price=get<2>(item)/cnt;
    // get<2>(item)*=0.8;
    // typedef decltype(item)trans;
    // size_t sz=tuple_size<trans>::value;
    // tuple_element<1,trans>::type  cnt=get<1>(item);
    // tuple<int,int,int>t{10,20,30};
    // vector<string>vs(20,"DAS");
    // tuple<string,vector<string>,pair<string,int>>tt{"DAS",vs,make_pair<string,int>("DAS",1)};
    

    return 0;
}
