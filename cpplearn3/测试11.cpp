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
class StrVec
{
private:
    /*static*/ allocator<string>alloc;
    void chk_n_alloc(){if(size()>=capacity())reallocate();}
    pair<string*,string*>alloc_n_copy(const string*,const string*);
    void free();
    void reallocate();
    string*elements;
    string*first_free;
    string*cap;
public:
    void reserve(string::size_type);
    void resize(string::size_type);
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    StrVec&operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size()const {return first_free-elements;}
    size_t capacity()const {return cap-elements;}
    string*begin()const{return elements;}
    string *end()const {return first_free;}

};
pair<string*,string*>StrVec::alloc_n_copy(const string*b,const string*e)
{
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}
void StrVec::free()
{
    if(elements){
        for(auto p=first_free;p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements,cap-elements);
    }
}
StrVec::StrVec(const StrVec &s)
{
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
StrVec&StrVec::operator=(const StrVec&rhs)
{
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
StrVec::~StrVec(){free();}
void StrVec::push_back(const string&s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
void StrVec::reallocate()
{
    auto newcapacity=(size()>0)?size()*2:1;
    // cout<<size()<<" "<<newcapacity<<endl;
    auto newdata=alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0;i!=size();i++)
        alloc.construct(dest++,std::move(*elem++));
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}
void StrVec::reserve(string::size_type n)
{
    
    if(n<=capacity()){
        if(n<0){
            throw("std::length_error");
            // exit(1);
        }
        else
            return ;
    }
    auto newcapacity=n;
    auto newdata=alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0;i!=size();i++)
        alloc.construct(dest++,std::move(*elem++));
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}
void StrVec::resize(string::size_type n)
{
    if(n<size()){
        if(n<0){
            throw("std::length_error");
            // exit(1);
        }
        first_free=elements+n;
    }else{
        while(n>capacity()){
            auto newcapacity=(capacity()>0)?capacity()*2:1;
            auto newdata=alloc.allocate(newcapacity);
            auto dest=newdata;
            auto elem=elements;
            for(size_t i=0;i!=size();i++)
                alloc.construct(dest++,std::move(*elem++));
            free();
            elements=newdata;
            first_free=dest;
            cap=elements+newcapacity;
        }
        while(size()<n){
                alloc.construct(first_free++,string());
        }
    }
}


int main()
{
    StrVec s;
    s.push_back("da");
    s.push_back("da");
    cout<<s.size()<<s.capacity()<<endl;
    s.reserve(10);
    cout<<s.size()<<s.capacity()<<endl;
    s.resize(11);
    cout<<s.size()<<s.capacity()<<endl;
    // vector<int>v(5,10);
    // v.resize(0);   
    // // v.reserve(9);
    // cout<<v.size()<<v.capacity()<<endl;
}