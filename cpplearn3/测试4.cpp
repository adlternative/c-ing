#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cassert>
#include <vector>
#include"../cpplearn2/Sales_data.h"
#include"../cpplearn2/Sales_item.h"
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
using namespace std;
using namespace std::placeholders;
bool big(int i,const string &s)
{
    return i>s.size()?true:false;
}
void elimDups(vector<string>&words)
{
    sort(words.begin(),words.end());
    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
bool isShorter(const string &s1,const string &s2)
{
    return s1.size()<s2.size();
}
bool big_than_five(const string&s,int sz)
{
    if(s.size()>=sz){
        return true;
    }
    return false;
}

int main()
{
    list<int >lst={1,2,3,4};
    list<int >lst2,lst3;
    auto fi=front_inserter(lst2);
    *fi=1;*fi=2;
    auto ist=inserter(lst2,lst.begin());
    *ist=1;*ist=2;
     
    copy(lst.cbegin(),lst.cend(),front_inserter(lst2));
    vector<string>words{"dsadsa","asasaads","aaaadas","eee","eeee","qa","aaaaae"};
    cout<<count_if(words.begin(),words.end(),[](string&str)->bool{
        if(str.size()>6)return true;
        else return false;
    })<<endl;
    cout<<count_if(words.begin(),words.end(),bind(big_than_five,_1,6));
    int s=1;
    auto aa=[&]()->bool{
        if(--s==0)
            return true;
        else 
            return false;
    };

    auto end_of_true=partition(words.begin(),words.end(),bind(big_than_five,_1,6));
     string::size_type sz=5;
    auto end_of_true2=partition(words.begin(),words.end(),[sz](const string&s){return s.size()>sz;});   
    auto end_of_true3=stable_partition(words.begin(),words.end(),[sz](const string&s){return s.size()>sz;});   
    
    for(vector<string>::iterator it=words.begin();it!=end_of_true;it++){
        cout<<*it<<endl;
    }
    sort(words.begin(),words.end(),isShorter);
        for(auto &i:words){
        cout<<i<<" ";
    }
    cout<<endl;
    stable_sort(words.begin(),words.end(),isShorter);
    stable_sort(words.begin(),words.end(),[](const string &a,const  string &b){return a.size()<b.size();});
   for(auto &i:words){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<string>svec(10,"sda");
    elimDups(svec);
    for(auto &i:svec){
        cout<<i<<" ";
    }
    cout<<endl;    
    cout<<endl;    
    cout<<endl;    
    cout<<endl;    
    vector<int>vec={1,2,3,4,5,6,7,8,9};
    string bs("sadadl");
    cout<<*find_if(vec.begin(),vec.end(),bind(big,_1,ref(bs)))<<endl;
    vec.reserve(10);
    fill_n(vec.begin(),10,2);
    auto it=back_inserter(vec);
    *it=42;
    fill_n(back_inserter(vec),10,1);

    for(auto &i:vec){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int>v{12,3,4,1,23,31,1,2,3,1,3};
    sort(v.begin(),v.end());
    list<int>ll;
    // unique_copy(v.cbegin(),v.cend(),inserter(ll,ll.begin()));
       unique_copy(v.cbegin(),v.cend(),back_inserter(ll));

    for(auto &i:ll){
        cout<<i<<" "<<"?";
    }
    cout<<"ok"<<endl;
    vector<int>v10{1,2,3,4,5,6,7,8,9};
    list<int >l4,l5,l3;
    copy(v10.begin(),v10.end(),inserter(l4,l4.begin()));
        for(auto &i:l4){
        cout<<i<<" "<<"?";
    }
    cout<<"ok"<<endl;
copy(v10.begin(),v10.end(),back_inserter(l5));
     for(auto &i:l5){
        cout<<i<<" "<<"?";
    }
    cout<<"ok"<<endl;

    copy(v10.begin(),v10.end(),front_inserter(l3));
        for(auto &i:l3){
        cout<<i<<" "<<"?";
    }
    cout<<"ok"<<endl;



    replace_copy(v.cbegin(),v.cend(),back_inserter(vec),10,4);
    fill_n(v.begin(),10,0);
        for(auto &i:vec){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto &i:v){
        cout<<i<<" ";
    }
    list<string>ls(10,"dsa");
    cout<<count(v.begin(),v.end(),3)<<endl;
    cout<<count(ls.begin(),ls.end(),"dsa")<<endl;
    int sum=accumulate(v.begin(),v.end(),0);
    string str=accumulate(ls.begin(),ls.end(),string(""));
    vector<double>vd(8,3.8);
    double d=accumulate(vd.begin(),vd.end(),0.0);
    cout<<d<<endl;
    // cout<<str;
    char str1[10]="Sad";
    char str2[10]="Sad";
    if(equal(str1,str1+9,str2)){
        cout<<"!!";
    }
    if(equal(begin(str1),end(str1),begin(str2)))
        cout<<"!";
    for_each(v.begin(),v.end(),[](int &i){cout<<i<<" ";});
    auto l1=[](int a,int b){return a+b;};
    int ppp=0;
    ++(++(++ppp));
    auto l2=[ppp](int qqq){return qqq+ppp;};
}