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
class HasPtr{
public:
    HasPtr(const string&s=string()):i(0),ps(new string(s)),use(new size_t(1)){}
    HasPtr(const HasPtr&rhs):i(rhs.i),ps(rhs.ps),use(rhs.use){++*use;}
    HasPtr&operator=(const HasPtr&rhs){
        ++*rhs.use;
        if(--*use==0){
            delete ps;
            delete use;
        }
        ps=rhs.ps;
        i=rhs.i;
        use=rhs.use;
        return *this;
    }
    ~HasPtr(){
        if(--*use==0){
            delete ps;
            delete use;
        }
    }   

private:
    string*ps;
    int i;
    size_t *use;
};

class TreeNode{
public:
//string s=string("")会出错了
    TreeNode(string s=string()):count(new int(1)),left(nullptr),right(nullptr){}
    TreeNode(const TreeNode&rhs):value(rhs.value),left(rhs.left),right(rhs.right),count(rhs.count){++*count;}    
    ~TreeNode(){
        if(--*count==0){
            delete count;
            delete left;
            delete right;
        }
    }
    TreeNode&operator=(const TreeNode&rhs){
        if(--*count==0){
            delete count;
            delete left;
            delete right;
        }
        ++*rhs.count;
        count=rhs.count;
        left=rhs.left;
        right=rhs.right;
        value=rhs.value;
    }

private:
    string value;
    int *count;
    TreeNode*left;
    TreeNode*right;
};
int main()
{

}