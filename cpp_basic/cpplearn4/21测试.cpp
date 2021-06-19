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
#define _CRT_SECURE_NO_WARNINGS 1
// #include<iostream>
// using namespace std;
//为解决文件指针
struct Fclose
{
    void operator()(FILE*& fp)
    {
        cout<< "Fclose()" << endl;
        fclose(fp);
        fp = NULL;
    }
};
//为解决malloc开辟的空间
template<class T>
struct Free
{
    void operator()(T*& p)
    {
        free(p);
        p = NULL;
    }
};
//一般情况下（使用new动态开辟的空间）
template<class T>
class Delete
{
public :
    void operator()(T*& p)
    {
        delete p;
        p = NULL;
    }
};
template<class T, class Destory = Delete<T> >
class SharedPtr
{
public :
    SharedPtr(T* ptr = 0)//构造函数
        :_ptr(ptr)
        ,_pCount(NULL)
    {
        if (_ptr)
        {
            _pCount = new int(1);
        }
    }
    SharedPtr(const SharedPtr<T>& sp)//拷贝构造函数
        :_ptr(sp._ptr)
        , _pCount(sp._pCount)
    {
        if (_ptr)
        {
            ++GetRef();
        }
    }
    //sp1 = sp2
    SharedPtr<T>& operator=(const SharedPtr<T>& sp)
    {
        //可有三种情况：①sp1._ptr = NULL  ②sp1的引用计数为1  ③sp1的引用计数大于1
        if (this != &sp)
        {
            Release();
            _ptr = sp._ptr;
            _pCount = sp._pCount;
            ++GetRef();
        }
        return *this;
    }
    //辅助函数
    void Release()
    {
        if (_ptr && --GetRef() == 0)
        {
            Destory()(_ptr);
            delete _pCount;
            _pCount = NULL;
        }
    }
 //析构函数
    ~SharedPtr()
    {
        Release();
    }
 
    int& GetRef()
    {
        return *_pCount;
    }
private:
    T* _ptr;
    int* _pCount;
};
void Test2()
{
    FILE* sp1 = fopen("test.txt", "rb");
    SharedPtr<FILE, Fclose> sp2(sp1);
 
    int* sp3 = (int*)malloc(sizeof(int));
    SharedPtr<int, Free<int> >sp4(sp3);
 
    int* sp5 = new int(1);
    SharedPtr<int> sp6(sp5);
}
 
int main()
{
    Test2();
    return 0;
}