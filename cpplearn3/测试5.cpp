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
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob;
class StrBlob{
public:
    friend bool operator==(StrBlob&rhs,StrBlob&lhs);
    friend bool operator!=(StrBlob&rhs,StrBlob&lhs);
    friend bool operator<(StrBlob&rhs,StrBlob&lhs);
    friend bool operator>(StrBlob&rhs,StrBlob&lhs);
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob():data(make_shared<vector<string>>()){}
    StrBlob(initializer_list<string>i1):data(make_shared<vector<string>>(i1)){}
    StrBlob(const StrBlob&rhs):data(make_shared<vector<string>>(*rhs.data)){}
    string& operator[](size_type n){return (*data)[n];}
    const string&operator[](size_type n)const{return (*data)[n];}
    size_type size()const {return data->size();}
    bool empty()const {return data->empty();}
    void  push_back(const string &t){data->push_back(t);}
    void push_back(string&&t){data->push_back(t);}
    void pop_back(){ 
        check(0,"pop_back on empty StrBlob");
        data->pop_back();
    }
    string &front(){    
        check(0,"front on empty StrBlob");
        return data->front();
    }
    string &back(){
        check(0,"back on empty StrBlob");
        return data->back();

    }
    const string &front()const{
        check(0,"front on empty StrBlob");
            return data->front();
    }
    const string &back()const{
        check(0,"back on empty StrBlob");
            return data->back();
    }
    // StrBlobPtr begin(){
    //     return StrBlobPtr(*this);
    // }
    // StrBlobPtr end(){
    //     auto ret=StrBlobPtr(*this,data->size());
    //     return ret;
    // }

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr  cbegin()const;
    ConstStrBlobPtr  cend()const;
    StrBlob&operator=(const StrBlob&rhs){
        data=make_shared<vector<string>>(*rhs.data);
        return *this;
    }
private:

    void check(size_type i,const string&msg)const{
        if(i>=data->size())
            throw out_of_range(msg);
    }
    shared_ptr<vector<string>>data;
};
class ConstStrBlobPtr{
public:
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr(const StrBlob &a,std::size_t sz = 0):wptr(a.data),curr(sz){}
    //返回当前指向的vertor的第curr个元素
    std::string& deref(){
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    //重载！运算符，使其对StrBlobPtr对象的curr对象进行判断
    bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
   const string&operator*()const{
        auto p=check(curr,"dereference past end");
        return (*p)[curr];
    }
    const string*operator->()const{return & this->operator*();}

    //前缀递增：返回递增后的对象的引用
    ConstStrBlobPtr& incr(){
        //如果curr已经指向容器的为尾后位置，就不能递增
        check(curr,"incerement past of StrBlolPte");
        ++curr;
        return *this;
    }
//weak_ptr的lock方法是类要求访问安全的核心
private:
    //同样有个检查方法,检查指针指向的vector是否还存在,存在则返回该智能指针
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string & msg) const{
        auto ret = wptr.lock();//vector是否还有关联
        if(!ret){
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if(i>=ret->size()){
            throw std::out_of_range(msg);
        }
        return ret;
    }
    //保存一个weak_ptr，意味着底层的vector可能会被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    //保存数组当前的位置
    std::size_t curr;
};
// StrBlobPtr StrBlob::begin(){
//         return StrBlobPtr(*this);
//     }
//     StrBlobPtr StrBlob::end(){
//         auto ret=StrBlobPtr(*this,data->size());
//         return ret;
//     }

class StrBlobPtr{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a,std::size_t sz = 0):wptr(a.data),curr(sz){}
    //返回当前指向的vertor的第curr个元素
    std::string& deref(){
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    //重载！运算符，使其对StrBlobPtr对象的curr对象进行判断
    friend bool operator==(const StrBlobPtr&lhs,const StrBlobPtr&rhs);/*{return lhs.curr == rhs.curr; }*/    
    friend bool operator!=(const StrBlobPtr&lhs,const StrBlobPtr&rhs);/*{ return !(lhs == rhs); } */   
    friend bool operator<(const StrBlobPtr&lhs,const StrBlobPtr&rhs);/*{return lhs.curr == rhs.curr; }*/    
    friend bool operator>(const StrBlobPtr&lhs,const StrBlobPtr&rhs);/*{ return !(lhs == rhs); } */   
    auto& operator[](std::size_t n){   
        auto ret=check(n," out end of StrBlobPtr");
        return (*ret)[n];
    }
    const auto&operator[](std::size_t n)const{   
        auto ret=check(n," out begin of StrBlobPtr");
        return (*ret)[n];
    }
    string&operator*()const{
        auto p=check(curr,"dereference past end");
        return (*p)[curr];
    }
    string*operator->()const{return & this->operator*();}
    // bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    StrBlobPtr& operator+(std::size_t n){curr+=n;check(curr," out end of StrBlobPtr");return *this;}
    StrBlobPtr& operator-(std::size_t n){curr-=n;check(curr," out begin of StrBlobPtr");return *this;}
    // std::string&operator*(){return deref();}
    //前缀递增：返回递增后的对象的引用
    StrBlobPtr&operator++();
    StrBlobPtr&operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    
    StrBlobPtr& incr(){
        //如果curr已经指向容器的为尾后位置，就不能递增
        check(curr,"incerement past of StrBlolPte");
        ++curr;
        return *this;
    }

private:
    //同样有个检查方法,检查指针指向的vector是否还存在,存在则返回该智能指针
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string & msg) const{
        auto ret = wptr.lock();//vector是否还有关联,返回shared_ptr
        if(!ret){
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if(i>=ret->size()){
            throw std::out_of_range(msg);
        }
        return ret;
    }
    //保存一个weak_ptr，意味着底层的vector可能会被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    //保存数组当前的位置
    std::size_t curr;
};
StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
    auto ret=StrBlobPtr(*this,data->size());
    return ret;
}

ConstStrBlobPtr StrBlob::cbegin()const{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend()const {
        auto ret=ConstStrBlobPtr(*this,data->size());
        return ret;
}
bool operator==(StrBlob&rhs,StrBlob&lhs){return(*rhs.data)==(*lhs.data);}
bool operator!=(StrBlob&rhs,StrBlob&lhs){return !(rhs==lhs);}
bool operator<(StrBlob&rhs,StrBlob&lhs){return (*rhs.data)<(*lhs.data);}
bool operator>(StrBlob&rhs,StrBlob&lhs){return (*rhs.data)>(*lhs.data);}

bool operator==(const StrBlobPtr&lhs,const StrBlobPtr&rhs){return lhs.curr == rhs.curr;}    
bool operator!=(const StrBlobPtr&lhs,const StrBlobPtr&rhs){return !(lhs==rhs);} /*{ return !(lhs == rhs); } */   
bool operator<(const StrBlobPtr&lhs,const StrBlobPtr&rhs){return lhs.curr<rhs.curr;}/*{return lhs.curr == rhs.curr; }*/    
bool operator>(const StrBlobPtr&lhs,const StrBlobPtr&rhs){return lhs.curr>rhs.curr;}/*{ return !(lhs == rhs); } */   

StrBlobPtr&StrBlobPtr::operator++()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr&StrBlobPtr::operator--()
{
    --curr;
    check(curr,"increment past end of StrBlobPtr");
    return *this;
}StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret=*this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret=*this;
    --*this;
    return ret;
}
// int main()
// {
//     StrBlob a1={"as","ad","dsa"};
//     StrBlobPtr p(a1);
//     *p="ok";
//     // p.operator->()->size;
//     cout<<p->size()<<endl;
//     cout<<(*p).size()<<endl;
// }

// int main()
// {
//     const StrBlob sb{"a","b","C"};
//     for(auto b=sb.cbegin();b!=sb.cend();b.incr()){
//         cout<<b.deref()<<endl;
//     }
//     StrBlob sb2;
//     string str,s;
//     ifstream is("a.txt");
//     while(getline(is,str)){
//         stringstream ss(str);
//         while(ss>>s){
//             sb2.push_back(s);
//         }
//     }   
//     for(auto b=sb2.cbegin();b!=sb2.cend();b.incr()){
//         cout<<b.deref()<<endl;
//     }
// }