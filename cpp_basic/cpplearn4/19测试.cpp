#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED
 
#include<memory>
#include<initializer_list>
#include<utility>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
template <typename T> class Vec{
public:
    //构造函数
    Vec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec( std::initializer_list<T> );
    Vec(  std::size_t n ,const T &val );
 
    //拷贝构造函数
    Vec( const Vec& );
    //拷贝赋值运算符
    Vec& operator=( const Vec& );
    //移动构造函数
    Vec( Vec&& ) noexcept;
    //移动赋值运算符
    Vec& operator=( Vec&& ) noexcept;
    ~Vec();
 
    //公共接口
    template<class...Args>
    inline void emplace_back(Args&&...args)
    {
        chk_n_alloc();
        alloc.construct(first_free++,std::forward<Args>(args)...);
    }
    bool empty() const { return elements == first_free; }
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
 
    T* begin() const { return elements; }
 
    T* end() const { return first_free; }
 
    void push_back( const T& );
    void push_back( T&& );
    void pop_back();
 
    T& operator[]( std::size_t );
    const T& operator[]( std::size_t ) const;
private:
    //数据成员
    static std::allocator<T> alloc;//空间分配器
    T *elements;
    T *first_free;
    T *cap;
 
    //辅助函数
    std::pair<T*, T*>
        alloc_n_copy( const T*, const T* );
    void chk_n_alloc();
    void free();
    void reallocate();
};
 
//静态成员的类外定义(默认值初始化)
template <typename T> std::allocator<T> Vec<T>::alloc;
 
template <typename T>
inline
std::pair<T*,T*>
Vec<T>::alloc_n_copy( const T *b, const T *e )
{
    auto data = alloc.allocate( e - b );
    return { data, std::uninitialized_copy( b, e, data ) };
}
 
template <typename T>
inline
void Vec<T>::chk_n_alloc(){
    if( first_free == cap )
        reallocate();
}
 
template <typename T>
inline
void Vec<T>::free(){
    //不能给deallocate传递一个空指针
    if( elements ){
        for( auto q = first_free; q != elements; )
            alloc.destroy( --q );
        alloc.deallocate( elements, cap - elements );
    }
}
 
template <typename T>
inline
void Vec<T>::reallocate(){
    auto newcapacity = size()? 2*size(): 1;
    auto first = alloc.allocate( newcapacity );
    auto dest = first;
    auto elem = elements;
 
    for( size_t i = 0; i != size(); ++i )
        alloc.construct( dest++, std::move( *elem++ ) );
 
    free();
 
    elements = first;
    first_free = dest;
    cap = elements + newcapacity;
}
 
template <typename T>
inline
Vec<T>::Vec( std::initializer_list<T> lst){
    auto data = alloc_n_copy( lst.begin(), lst.end() );
    elements = data.first;
    cap = first_free = data.second;
}
 
 
template <typename T>
inline
Vec<T>::Vec( std::size_t n,const T &val ){
    auto data = alloc.allocate( n );
    elements = data;
    std::uninitialized_fill_n( data, n, val );
    cap = first_free = elements + n;
}
 
 
template <typename T>
inline
Vec<T>::Vec( const Vec &v ){
    auto data = alloc_n_copy( v.begin(), v.end() );
    elements = data.first;
    cap = first_free = data.second;
}
 
template <typename T>
inline
Vec<T>& Vec<T>::operator=( const Vec &v ){
    auto newdata = alloc_n_copy( v.begin(), v.end() );
    free();
    elements = newdata.first;
    cap = first_free = newdata.second;
 
    return *this;
}
 
template <typename T>
inline
Vec<T>::Vec( Vec &&v ) noexcept:
    elements( v.elements ), first_free( v.first_free ), cap( v.cap )
{
    std::cout << "move constructor version" << std::endl;
    v.elements = v.first_free = v.cap = nullptr;
}
 
 
template <typename T>
inline
Vec<T>& Vec<T>::operator=( Vec &&v ) noexcept{
    if( this != &v ){
        free();
        elements = v.elements;
        first_free = v.first_free;
        cap = v.cap;
        v.elements = v.first_free = v.cap = nullptr;
    }
    return *this;
}
 
template <typename T>
inline
Vec<T>::~Vec(){
    free();
}
 
 
template <typename T>
inline
void Vec<T>::push_back( const T &val ){
    chk_n_alloc();
    alloc.construct( first_free++, val );
}
 
template <typename T>
inline
void Vec<T>::push_back( T &&val ){
    std::cout << "move push_back version" << std::endl;
    chk_n_alloc();
    alloc.construct( first_free++, std::move( val ) );
}
 
template <typename T>
inline
void Vec<T>::pop_back(){
    if( !empty() )
        alloc.destroy( --first_free );
}
 
template <typename T>
inline
T& Vec<T>::operator[]( std::size_t i ){
    return elements[i];
}
 
template <typename T>
inline
const T& Vec<T>::operator[]( std::size_t i ) const{
    return elements[i];
}
#endif // VEC_H_INCLUDED
 
int main()
{
    Vec<string> v(10,"sad");
    v.emplace_back(string("das"));
    
    for_each(v.begin(),v.end(),[&](const string&s){cout<<s;});
} 
