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
friend bool operator==(const StrVec&,const StrVec&);
friend bool operator!=(const StrVec&,const StrVec&);
friend bool operator<(const StrVec&,const StrVec&);
friend bool operator>(const StrVec&,const StrVec&);

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
    template<class...Args>
    inline void emplace_back(Args&&...args)
    {
        chk_n_alloc();
        alloc.construct(first_free++,std::forward<Args>(args)...);
    }
    void reserve(string::size_type);
    void resize(string::size_type);
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(StrVec&&s)noexcept;
    StrVec(initializer_list<string>ls):elements(nullptr),first_free(nullptr),cap(nullptr){
        // for(auto i:ls){
        //     push_back(i);
        // }
        auto data=alloc_n_copy(ls.begin(),ls.end());
        elements=data.first;
        first_free=data.second;
        first_free=cap=data.second;
    }
    StrVec&operator=(initializer_list<string>il);
    StrVec&operator=(const StrVec&);
    StrVec&operator=(StrVec &&rhs)noexcept;
    string&operator[](vector<string>::size_type n){return elements[n];}
    const string&operator[](vector<string>::size_type n)const{return elements[n];}
    ~StrVec();
    void push_back(const string&);
    void push_back(string&&);
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
        // for(auto p=first_free;p!=elements;)
        //     alloc.destroy(--p);
        
        for_each(elements,first_free,[&](const string p){alloc.destroy(&p);});
        alloc.deallocate(elements,cap-elements);
    }
}
StrVec::StrVec(StrVec&&s)noexcept:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
    s.elements=s.first_free=s.cap=nullptr;
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
StrVec&StrVec::operator=(initializer_list<string>il)
{
    auto data=alloc_n_copy(il.begin(),il.end());
    free();
    elements=data.first;
    first_free=data.second;
    first_free=cap=data.second;
    return *this;
}
StrVec&StrVec::operator=(StrVec &&rhs)noexcept
{
    if(this!=&rhs){
        free();
        elements=rhs.elements;
        first_free=rhs.first_free;
        cap=rhs.cap;
        rhs.elements=rhs.first_free=rhs.cap=nullptr;
    }
    return *this;
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
void  StrVec::push_back(string&&s)
{
    puts("StrVec::push_back( string&&s)");
    chk_n_alloc();
    alloc.construct(first_free++,std::move(s));
}

void StrVec::push_back(const string&s)
{
    puts("StrVec::push_back(const string&s)");
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
void StrVec::reallocate()
{
    auto newcapacity=(size()>0)?size()*2:1;
    // cout<<size()<<" "<<newcapacity<<endl;
    auto newdata=alloc.allocate(newcapacity);
    // auto dest=newdata;
    // auto elem=elements;
    // for(size_t i=0;i!=size();i++)
    //     alloc.construct(dest++,std::move(*elem++));
    auto dest=uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),newdata);
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
                alloc.construct(first_free++,string());
        }
    }else{
        while(size()<n){
                    alloc.construct(first_free++,string());
            }
    }
}
 bool operator==(const StrVec&lhs,const StrVec&rhs)
 {
    if(lhs.size()!=rhs.size())
        return false;
    for(auto i=lhs.begin(),j=rhs.begin();i!=lhs.end(),j!=rhs.end();i++,j++){
        if((*i)!=(*j)) 
            return false;
    }
    return true;

 }
 bool operator!=(const StrVec&lhs,const StrVec&rhs)
 {
     return !(lhs==rhs);
 }
bool operator<(const StrVec&lhs,const StrVec&rhs)
{
    auto i=lhs.begin(),j=rhs.begin();
    for(;i!=lhs.end(),j!=rhs.end();i++,j++){
        if((*i)>=(*j)) 
            return false;    
    }
    if(j==rhs.end())//lhs更长
        return false;
    return true;

}
bool operator>(const StrVec&lhs,const StrVec&rhs)
{
    auto i=lhs.begin(),j=rhs.begin();
    for(;i!=lhs.end(),j!=rhs.end();i++,j++){
        if((*i)<=(*j)) 
            return false;    
    }
    if(j==lhs.end())//rhs更长
        return false;
    return true;

}

int main()
{
    StrVec vec;
    StrVec vec2;
    string s="Sad";
    vec.push_back(s);
    vec.push_back("dsa");
    vec2.push_back(s);
    vec2.push_back("dsa");
    if(vec==vec2)cout<<"=="<<endl;
}
// int main()
// {
//     StrVec s;
//     s.push_back("da");
//     s.push_back("da");
//     cout<<s.size()<<s.capacity()<<endl;
//     s.reserve(10);
//     cout<<s.size()<<s.capacity()<<endl;
//     s.resize(11);
//     cout<<s.size()<<s.capacity()<<endl;
//     vector<int>v(2,2);
//     cout<<v.size()<<v.capacity()<<endl;
//    v.reserve(10);
//     cout<<v.size()<<v.capacity()<<endl;
//     v.resize(11);   
//     cout<<v.size()<<v.capacity()<<endl;
// }