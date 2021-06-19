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
using line_no =vector<string>::size_type;
class QueryResult;
class TextQuery
{
public:
    TextQuery(ifstream&is):file(new vector<string>)//初始化空的向量容器
    {   
        string text;
        while(getline(is,text)){
            file->push_back(text);//读入每一行写入file
            int n=file->size()-1;
            istringstream line(text);
            string word;
            while(line>>word){
                auto &lines=wm[word];//lines为一个指针
                if(!lines)//可能为空指针，需要shared_ptr的reset去绑定动态内存
                    lines.reset(new set<line_no>);//在每个单词的map对应的set插入行号
                lines->insert(n);
            }
        }
    }
    QueryResult query(const string& to_find)const;

    
private:
    shared_ptr<vector<string>>file;
    map<string,shared_ptr<set<line_no>>>wm;
};
class QueryResult{
friend ostream&print(ostream&,const QueryResult& );
public:
QueryResult(string s,shared_ptr<set<line_no>>p,shared_ptr<vector<string>>f):
sought(s),lines(p),file(f){};
private:
    string sought;
    shared_ptr<set<line_no>>lines;//该类绑定行号和文章的每一行（用了指针），通过print函数查询打印
    shared_ptr<vector<string>>file;
};
QueryResult TextQuery::query(const string& to_find)const{
        static shared_ptr<set<line_no>>nodata(new set<line_no>);
        auto loc=wm.find(to_find);//可见map的find失败是end
        if(loc==wm.end())
            return QueryResult(to_find,nodata,file);//传递nodata则print的for循环进不去
        else
            return QueryResult(to_find,loc->second,file);
    }
ostream&print(ostream&os,const QueryResult& qr)
{
    os<<qr.sought<<"occurs"<<qr.lines->size()<<"time"<<endl;
    for(auto num:*qr.lines){
        os<<"\t(line"<<num+1<<")"<<*(qr.file->begin()+num)<<endl;//利用vector迭代器去寻找每一行
    }
    return os;    
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    
    while(1){
        cout<<"enter word to look for ,q quit"<<endl;
        string s;
        if(!(cin>>s)||s=="q")break;
        print(cout,tq.query(s));
    }
}
int main()
{
    ifstream ifs("a.txt");
    runQueries(ifs);
}