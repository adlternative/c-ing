#ifndef BLOB_H_INCLUDED
#define BLOB_H_INCLUDED
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
 
#include<vector>
#include<memory>
#include<initializer_list>
#include<stdexcept>
#include<iterator>
 using namespace std;
using namespace std::placeholders;

//模板前置声明
 
template<typename> class Blob;
 
template <typename T>
bool operator==( const Blob<T>&, const Blob<T>& );
 
template <typename> class BlobPtr;
 
template <typename T> class Blob{
    //友元声明
    friend class BlobPtr<T>;
    friend bool operator==<T>( const Blob<T>&, const Blob<T>& );
public:
    typedef typename std::vector<T>::size_type size_type;
    //构造函数
    
    Blob():
        data( std::make_shared<std::vector<T>>() ) { }
    Blob( std::initializer_list<T> lst ):
        data( std::make_shared<std::vector<T>>( lst ) ) { }
    
    template <typename It>
    Blob( It b, It e ):
        data( std::make_shared<std::vector<T>>( b, e ) ) { }
 
    Blob( T *p, size_t n ):
        data( std::make_shared<std::vector<T>>( p, p + n ) ) { }
 
 
    //公共接口
    bool empty() const { return data->empty(); }
    size_type size() const { return data->size(); }
 
    //先搁置
    BlobPtr<T> begin() { return BlobPtr<T>( *this, 0 ); }
    BlobPtr<T> end() { return BlobPtr<T>( *this, data->size() ); }
 
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
 
    T& at( size_type );
    const T& at( size_type ) const;
 
    void push_back( const T &val ) { data->push_back( val ); }
    void push_back( T &&val ) { data->push_back( std::move( val ) ); }
 
    void pop_back();
 
    //重载运算符
    T& operator[]( size_type i );
    const T& operator[]( size_type i ) const;
private:
    //数据成员
    std::shared_ptr<std::vector<T>> data;
    //辅助函数
    void check( size_type, const std::string& ) const;
};
 
template <typename T>
void Blob<T>::check( size_type n, const std::string &msg ) const{
    if( n >= size() )
        throw std::out_of_range( msg );
}
 
template <typename T>
T& Blob<T>::front() {
    check( 0, "front on empty Blob" );
    return data->front();
}
 
template <typename T>
const T& Blob<T>::front() const{
    check( 0, "front on empty Blob" );
    return data->front();
}
 
template <typename T>
T& Blob<T>::back() {
    check( 0, "back on empty Blob" );
    return data->back();
}
 
template <typename T>
const T& Blob<T>::back() const{
    check( 0, "back on empty Blob" );
    return data->back();
}
 
template <typename T>
void Blob<T>::pop_back(){
    check( 0, "pop_back on empty Blob" );
    data->pop_back();
}
 
template <typename T>
T& Blob<T>::at( size_type i ){
    check( i, "subscript out of range" );
    return ( *data )[ i ];
}
 
template <typename T>
const T& Blob<T>::at( size_type i ) const{
    check( i, "subscript out of range" );
    return ( *data )[ i ];
}
 
template <typename T>
T& Blob<T>::operator[]( size_type i ){
    check( i, "subscript out of range" );
    return ( *data )[ i ];
}
 
template <typename T>
const T& Blob<T>::operator[]( size_type i ) const{
    check( i, "subscript out of range" );
    return ( *data )[ i ];
}
 
 
//友元运算符定义
template <typename T>
bool operator==( const Blob<T> &lhs, const Blob<T> &rhs ){
    if( lhs.size() != rhs.size() )
        return false;
    for( size_t i = 0; i != lhs.size(); ++i )
        if( lhs[i] != rhs[i] )
            return false;
    return true;
}
 
template <typename T>
    bool operator==( const BlobPtr<T>&, const BlobPtr<T>& );
 
template <typename T> class BlobPtr{
    friend bool operator==<T>( const BlobPtr<T>&, const BlobPtr<T>& );
public:
    BlobPtr():
        curr( 0 ) { }
    BlobPtr( Blob<T> &a, std::size_t sz = 0 ):
        wptr( a.data ), curr( sz ) { }
 
    //公共接口
    T& operator[]( std::size_t i ){
        auto ret = check( i, "subscript out of range" );
        return ( *ret )[ i ];
    }
 
    const T& operator[]( std::size_t i ) const{
        auto ret = check( i, "subscript out of range" );
        return ( *ret )[ i ];
    }
 
    T& operator*() const{
        auto ret = check( curr, "dereference past end" );
        return ( *ret )[ curr ];
    }
 
    T* operator->() const{
        return & this->operator*();
    }
 
 
    BlobPtr& operator++();
    BlobPtr& operator--();
 
    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    //数据成员
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
    //辅助函数
    std::shared_ptr<std::vector<T>> check( std::size_t, const std::string& ) const;
};
 
template <typename T>
bool operator==( const BlobPtr<T> &lhs, const BlobPtr<T> &rhs )
{
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() && lhs.curr == rhs.curr;
}
 
template <typename T>
bool operator!=( const BlobPtr<T> &lhs, const BlobPtr<T> &rhs )
{
    return !( lhs == rhs );
}
 
template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check( std::size_t i, const std::string &msg ) const
{
    auto ret = wptr.lock();
    if( !ret )
        throw std::runtime_error( "unbound BlobPtr" );
    if( i >= ret->size() )
        throw std::out_of_range( msg );
    return ret;
}
 
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    check( curr, "increment past end" );
    ++curr;
    return *this;
}
 
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
    --curr;
    check( curr, "decrement past begin" );
    return *this;
}
 
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}
 
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}
template<typename T>class Foo{
public:
    static size_t count(){return ++ctr;}
private:
    static size_t ctr;
 };
template<typename T>size_t Foo<T>::ctr=1;

// size_t Foo<int>::ctr=1;
#endif // BLOB_H_INCLUDED
int main()
{
    Foo<string>fs;
    Foo<string>fs2;
    Foo<int>fi,fi2,fi3;
    cout<<fs.count();
    cout<<fs2.count();
    cout<<fi.count();
    cout<<fi2.count();
    cout<<fi3.count();
    cout<<Foo<int>::count();
    Blob<string> bb({"sad","SDA"});
    Blob<string> bc({"sad","SDA"});
    Blob<string> bd({"ad","SDA"});
    if(bc==bb){
        cout<<"!"<<endl;
        BlobPtr<string>bp(bb,0);
        BlobPtr<string>bp2(bb,0);
        if(bp2==bp){
            cout<<"!"<<endl;
        }
    }
}
