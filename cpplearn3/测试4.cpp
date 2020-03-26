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
#include<map>
#include<set>
#include<utility>
using namespace std;
using namespace std::placeholders;
pair<string,int>process(vector<string>&v){
    if(!v.empty()){
        // return {v.back(),v.back().size()};
        // return pair<string,int>(v.back(),v.back().size());
        return make_pair(v.back(),v.back().size());
    }else{
        return pair<string,int>();
    }
}
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
    vector<string>v;
    multiset<string>c;
    map<string,string>m;
    auto s=c.insert(c.begin(),{"s"});
    auto q=m.insert(m.begin(),{"s","S"});
    // copy(v.begin(),v.end(),inserter(c,c.end()));
    // // copy(v.begin(),v.end(),back_inserter(c));
    // copy(c.begin(),c.end(),inserter(v,v.end()));
    // copy(c.begin(),c.end(),back_inserter(v));
    // map<string,int>::iterator map_it;
    // map<string,int>::value_type map_it2;
    // map<int,int>m;
    // m[5]=2;
    // m[3]=1101010;
    // m[4]=3;
    // // for(map<int,int>::iterator)
    // auto map_it=m.begin();
    // while(map_it!=m.end()){
    //     map_it++;
    //     if(map_it->first==4){
    //         map_it->second=4;
    //     }
    // }
    // for(const auto& a:m){
    //     cout<<a.second<<endl;
    // }
    // vector<pair<string,int>>v;
    // string str;
    // while(cin>>str){
    //     v.push_back(make_pair(str,str.size()));
    // }
    
    // list<int>lll(10,2);
    // map<vector<int>::iterator,int>m1;
    // map<list<int>::iterator,int>m2;
    // for(list<int>::iterator it=lll.begin();it!=lll.end();it++){
    //     m2[it]=*it;
    // }
    
    // string str;int number;
    // map<string,list<int>>m;
    // while(cin>>str){
    //     while(cin>>number&&number!=9999){
    //         m[str].push_back(number);
    //     }
    // }
    // for(const auto&mm:m){
    //     cout<<mm.first;
    //     for(const auto&i:mm.second){
    //         cout<<i<<" ";
            
    //     }
    //     cout<<endl;
    // }
    // using funcc=bool(*)(const Sales_item &lhs, const Sales_item &rhs);
    // multiset<Sales_data,funcc>bs(compareIsbn);
    // multiset<Sales_data,decltype(compareIsbn)*>bookstore(compareIsbn);
    // map<string,vector<pair<string,string>>>familys;
    // string first_name;
    // while(cin>>first_name){
    //     string numb;string birthday;
    //     while(cin>>numb&&numb.compare("#")&&cin>>birthday)
    //         familys[first_name].push_back(make_pair(numb,birthday));
    // }
    // for(const auto&f:familys){
    //         cout<<"姓"<<f.first;
    //         for(const auto&pai:f.second){
    //             cout<<"名"<<pai.first<<"生日"<<pai.second;
    //         }
    //         cout<<endl;
    // }
    
    // map<string ,size_t>word_count;
    // string word;
    // while(cin>>word){
    //     ++word_count[word];
    // }
    // for(const auto &w:word_count){
    //     cout<<w.first<<"  occurs"<<w.second<<((w.second>1)?"Times":"time")<<endl;
    // }
    // map<string,string>authors={{"a","b"},{"a","b"},{"a","d"}};
    // vector<int>ivec;
    // for(vector<int>::size_type i=0;i!=10;++i){
    //     ivec.push_back(i);
    //     ivec.push_back(i);
    // }
    // set<int>iset(ivec.begin(),ivec.end());
    // multiset<int>miset(ivec.begin(),ivec.end());
    // cout<<iset.size()<<endl;
    // cout<<miset.size()<<endl;
    // list<int >l1{3,4,5,6,7,89,0,2,13,5,7,3,5,7,3,56,7};
    
    // l1.sort();
    // l1.unique();
    // // unique();
    // for_each(l1.begin(),l1.end(),[](int i){cout<<i<<" ";});

    // vector<int>v1{1,2,3,4,5,6,7,8,9,10};
    // // auto b=v1.begin()+2;
    // // auto c=v1.begin()+7;
    // auto b=v1.rend()-7;
    // auto c=v1.rend()-1;
    // list<int>ll;
    // copy(b,c,inserter(ll,ll.begin()));
    // for_each(ll.begin(),ll.end(),[](int i){cout<<i<<" ";});
    // istream_iterator<int> in(cin),eof;
    // ifstream iff("a.txt");
    
    // ofstream of1("1.txt",ios::out);
    // ofstream of2("2.txt",ios::out);
    // ostream_iterator<int>out1(of1," ");
    // ostream_iterator<int>out2(of2,"*");
    // while(in!=eof){
    //     int get=*in++;
    //     if(get%2){
    //         out1=get;
    //     }else{
    //         out2=get;
    //     }
    // }

    // vector<int>vec;
    // istream_iterator<int> in(cin),eof;
    // ostream_iterator<int>out(cout," ");
    // copy(in,eof,inserter(vec,vec.begin()));
    // sort(vec.begin(),vec.end());
    // unique_copy(vec.begin(),vec.end(),out);
    // ifstream iff("a.txt");
    // istream_iterator<string>s_iter(iff),eof;
    // string s;vector<string>v;
    // while(s_iter!=eof){
    //     v.push_back(*s_iter++);

    // }
    //     for_each( v.begin(),v.end(),[](string i){cout<<i<<" ";});

    // istream_iterator<int>in_iter(cin),eof,eof2;
    // // if(*in_iter==*inter2){    puts("?");}
    // // puts("!");

    // // // if(eof==eof2){return 0;}
    // vector<int>vec(in_iter,eof);
    // // for_each(vec.begin(),vec.end(),[](int i){cout<<i<<" ";});
    // // cout<<endl;
    // ostream_iterator<int>out_iter(cout," ");
    // copy(vec.begin(),vec.end(),out_iter);
    // vector<int>vec1;
    // // istream_iterator<int>int_it(cin);
    // istream_iterator<int>int_eof;
    // ifstream in("b.txt");
    // istream_iterator<string>str_it(in);
    // istream_iterator<int >in_iter(cin);
    // istream_iterator<int>eof;
    // while(in_iter!=eof)
    //     vec1.push_back(*in_iter++);
    // for_each(vec1.begin(),vec1.end(),[](int i){cout<<i<<" ";});
    
//     list<int >lst={1,2,3,4};
//     list<int >lst2,lst3;
//     auto fi=front_inserter(lst2);
//     *fi=1;*fi=2;
//     auto ist=inserter(lst2,lst.begin());
//     *ist=1;*ist=2;
     
//     copy(lst.cbegin(),lst.cend(),front_inserter(lst2));
//     vector<string>words{"dsadsa","asasaads","aaaadas","eee","eeee","qa","aaaaae"};
//     cout<<count_if(words.begin(),words.end(),[](string&str)->bool{
//         if(str.size()>6)return true;
//         else return false;
//     })<<endl;
//     cout<<count_if(words.begin(),words.end(),bind(big_than_five,_1,6));
//     int s=1;
//     auto aa=[&]()->bool{
//         if(--s==0)
//             return true;
//         else 
//             return false;
//     };

//     auto end_of_true=partition(words.begin(),words.end(),bind(big_than_five,_1,6));
//      string::size_type sz=5;
//     auto end_of_true2=partition(words.begin(),words.end(),[sz](const string&s){return s.size()>sz;});   
//     auto end_of_true3=stable_partition(words.begin(),words.end(),[sz](const string&s){return s.size()>sz;});   
    
//     for(vector<string>::iterator it=words.begin();it!=end_of_true;it++){
//         cout<<*it<<endl;
//     }
//     sort(words.begin(),words.end(),isShorter);
//         for(auto &i:words){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     stable_sort(words.begin(),words.end(),isShorter);
//     stable_sort(words.begin(),words.end(),[](const string &a,const  string &b){return a.size()<b.size();});
//    for(auto &i:words){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     vector<string>svec(10,"sda");
//     elimDups(svec);
//     for(auto &i:svec){
//         cout<<i<<" ";
//     }
//     cout<<endl;    
//     cout<<endl;    
//     cout<<endl;    
//     cout<<endl;    
//     vector<int>vec={1,2,3,4,5,6,7,8,9};
//     string bs("sadadl");
//     cout<<*find_if(vec.begin(),vec.end(),bind(big,_1,ref(bs)))<<endl;
//     vec.reserve(10);
//     fill_n(vec.begin(),10,2);
//     auto it=back_inserter(vec);
//     *it=42;
//     fill_n(back_inserter(vec),10,1);

//     for(auto &i:vec){
//         cout<<i<<" ";
//     }
//     cout<<endl;

//     vector<int>v{12,3,4,1,23,31,1,2,3,1,3};
//     sort(v.begin(),v.end());
//     list<int>ll;
//     // unique_copy(v.cbegin(),v.cend(),inserter(ll,ll.begin()));
//        unique_copy(v.cbegin(),v.cend(),back_inserter(ll));

//     for(auto &i:ll){
//         cout<<i<<" "<<"?";
//     }
//     cout<<"ok"<<endl;
//     vector<int>v10{1,2,3,4,5,6,7,8,9};
//     list<int >l4,l5,l3;
//     copy(v10.begin(),v10.end(),inserter(l4,l4.begin()));
//         for(auto &i:l4){
//         cout<<i<<" "<<"?";
//     }
//     cout<<"ok"<<endl;
// copy(v10.begin(),v10.end(),back_inserter(l5));
//      for(auto &i:l5){
//         cout<<i<<" "<<"?";
//     }
//     cout<<"ok"<<endl;

//     copy(v10.begin(),v10.end(),front_inserter(l3));
//         for(auto &i:l3){
//         cout<<i<<" "<<"?";
//     }
//     cout<<"ok"<<endl;



//     replace_copy(v.cbegin(),v.cend(),back_inserter(vec),10,4);
//     fill_n(v.begin(),10,0);
//         for(auto &i:vec){
//         cout<<i<<" ";
//     }
//     cout<<endl;

//     for(auto &i:v){
//         cout<<i<<" ";
//     }
//     list<string>ls(10,"dsa");
//     cout<<count(v.begin(),v.end(),3)<<endl;
//     cout<<count(ls.begin(),ls.end(),"dsa")<<endl;
//     int sum=accumulate(v.begin(),v.end(),0);
//     string str=accumulate(ls.begin(),ls.end(),string(""));
//     vector<double>vd(8,3.8);
//     double d=accumulate(vd.begin(),vd.end(),0.0);
//     cout<<d<<endl;
//     // cout<<str;
//     char str1[10]="Sad";
//     char str2[10]="Sad";
//     if(equal(str1,str1+9,str2)){
//         cout<<"!!";
//     }
//     if(equal(begin(str1),end(str1),begin(str2)))
//         cout<<"!";
//     for_each(v.begin(),v.end(),[](int &i){cout<<i<<" ";});
//     auto l1=[](int a,int b){return a+b;};
//     int ppp=0;
//     ++(++(++ppp));
//     auto l2=[ppp](int qqq){return qqq+ppp;};
}