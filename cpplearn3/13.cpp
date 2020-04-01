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
class String
{
private:
    using size_type =size_t;
    allocator<char>alloc;
    void chk_n_alloc(){if(size()>=capacity())reallocate();/*cout<<size()<<" "<<capacity()<<endl;*/}
    pair<char*,char*>alloc_n_copy(const char*,const char*);
    void free();
    void reallocate();
    char*elements;
    char*first_free;
    char*cap;
public:   
    void reserve(String::size_type);
    void resize(String::size_type);
    String():elements(nullptr),first_free(nullptr),cap(nullptr){}
    String(const char*cc):elements(nullptr),first_free(nullptr),cap(nullptr){
        for(size_type i=0;i!=strlen(cc);i++){
            // cout<<"!"<<endl;
            push_back(cc[i]);
        }
    }
    String(const String&);
    String(initializer_list<char>ls):elements(nullptr),first_free(nullptr),cap(nullptr){
        for(auto i:ls)
            push_back(i);
    }
String&operator=(const String&);
~String();
void push_back(const char&);
size_t size()const{return first_free-elements;}
size_t capacity()const{return cap-elements;}
char* begin()const{return elements;}
char* end()const{return first_free;}
};
pair<char*,char*>String::alloc_n_copy(const char*b,const char*e)
{
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}

void String::free()
{
    if(elements){
        for_each(elements,first_free,[&](const char p){alloc.destroy(&p);});
        alloc.deallocate(elements,cap-elements);
    }
}
String::String(const String&s)
{
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
    cout<<"拷贝构造"<<endl;    
}

String&String::operator=(const String &rhs)
{
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    cout<<"拷贝赋值"<<endl;
    return *this;
}
String::~String(){free();}
void String::push_back(const char&c)
{
    chk_n_alloc();
    alloc.construct(first_free++,c);
}

void String::reallocate()
{
    auto newcapacity=(size()>0)?size()*2:1;
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
void String::reserve(String::size_type n)
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
void String::resize(String::size_type n)
{
    if(n<size()){
        if(n<0){
            throw("std::length_error");
            // exit(1);
        }
        first_free=elements+n;
    }else if(n>capacity()){
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
        while(size()<n){
                alloc.construct(first_free++,0);
        }
    }else{
        while(size()<n){
                    alloc.construct(first_free++,0);
            }
    }
}

ostream&operator<<(ostream& os,const String&s){
    for(auto i:s){
        os<<i;
    }
    return os;
}
int main()
{
    String  s("sad");
    String  s1("ssad");
    String  s2("ssad");
    // s.push_back('c');
    vector<String>v;
    v.push_back(s);
    v.push_back(s1);    
    v.push_back(s2);    
    v.push_back(s2);    
    v.push_back(s2);    
    v.push_back(s2);    
}