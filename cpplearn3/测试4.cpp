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
#include<unordered_set>
#include<unordered_map>
#include<memory>
#include<cstring>
using namespace std;
using namespace std::placeholders;
vector<int>*funcc(){
    return new vector<int>;
}
shared_ptr<vector<int>>fun(){
    return make_shared<vector<int>>();
}
shared_ptr<vector<int>>funnnn(shared_ptr<vector<int>>v)
{
     int i;
    while(cin>>i){
        // cout<<">";
        if(i==-1)
            break;
        else{ 
            v->push_back(i);
            // cout<<i;
        }
    }
    return v;   
}
vector<int>*funcccc(vector<int>*v)
{
    int i;
    while(cin>>i){
        if(i==-1)
            break;
        else 
            v->push_back(i);
    }
    return v;
}
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

size_t hasher(const Sales_data&sd)
{
    return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data&lhs,const Sales_data&rhs)
{
    return lhs.isbn()==rhs.isbn();
}
using SD_multimet =unordered_multiset<Sales_data,decltype(hasher)*,decltype(eqOp)*>;
void process(shared_ptr<int>ptr)
{
    cout<<"process"<<ptr.use_count()<<endl;
    cout<<*ptr<<endl;
}

int main()
{
    int n=4;
    // allocator<string>alloc;
    // auto const p=alloc.allocate(n);
    // auto q=p;
    // alloc.construct(q++);
    // alloc.construct(q++,10,'c');
    // alloc.construct(q++,"hi");
    // // q=p;
    // // cout<<*q++;    
    // cout<<*p<<endl;
    // // string* p=new string[3];
    // while(q!=p)
    //     alloc.destroy(--q);

    string s;
    allocator<string>a;
    auto const p=a.allocate(n);
    auto q=p;
    while(cin>>s&&q!=p+n){
        *q++=s;
    }
    const size_t size=q-p;
    q=p;
    for(size_t i=0;i<size;i++){
        cout<<*q++;
    }
    
    // string*q=p;
    // while(cin>>s&&q!=p+3){
    //     *q++=s;
    // }
    // const size_t size=q-p;
    // q=p;
    // for(size_t i=0;i<size;i++){
    //     cout<<*q++;
    // }
    // delete[]p;
    // allocator<int>alloc;
    // // auto const p=alloc.allocate(4);
    // vector<int>vi(3,3);
    // auto p=alloc.allocate(vi.size()*2);
    // auto q=uninitialized_copy(vi.begin(),vi.end(),p);
    // uninitialized_fill_n(q,vi.size(),42);
    // for(int i=0;i<3;i++){
    //     cout<<*p++<<endl;
    // }
    // auto q=p;
    // alloc.construct(q++,10,'s');
    // // cout<<*(q--)<<endl;
    // alloc.construct(q++,10,'c');
    // // cout<<*q--<<endl;
    // alloc.construct(q++,"hi");
    // // cout<<*q--<<endl;
    // while(q!=p)
    //     alloc.destroy(--q);
    // alloc.deallocate(p,4);
    
    // cout<<*p<<endl;
    // string s1="Sad",s2="BOy";
    // char s3[]="sad",s4[]="boy";
    // int  l3=strlen(s3);int l4=strlen(s4);
    // int len=strlen(s3)+strlen(s4)+1;
    // char *p=new char[len];
    // p=strcat(s3,s4);
    // printf("%s",p);
    // string*pp=new string[1];
    // string str;
    // cin>>str;
    // // cout<<str.size();
    
    // char*pp=new char[str.size()+1];
    // strcpy(pp,str.c_str());
    // printf("%s",pp);

    // auto p=make_shared<int>(42);
    // // weak_ptr<int>wp(p);
    // weak_ptr<int>wp;
    // if(shared_ptr<int>np=wp.lock()){
    //     cout<<"!"<<*p;
    // }else{
    //     cout<<"?";
    //     np.reset(new int(12));
    //     wp=np;
    //     cout<<wp.use_count()<<endl;
    //     cout<<wp.expired();
        
    // }
    // int*x(new int(1024));
    // process(shared_ptr<int>(x));
    // // cout<<"process"<<x.use_count()<<endl;
    // cout<<*x;

    // shared_ptr<int>p(new int(42));
    // process(shared_ptr<int>(p));
    // cout<<"process"<<p.use_count()<<endl;
    // delete p.get();

    // shared_ptr<int>pp(new int(42));
    // process(shared_ptr<int>(pp.get()));

    // cout<<"process"<<p.use_count()<<endl;
    // cout<<*p<<endl;
    // auto a=new auto(1);
    // int *p2=new(nothrow)int;
    // auto p=make_shared<int>(42);
    // weak_ptr<int>wp(p);
    // if(shared_ptr<int>np=wp.lock()){

    // }
    // int *q=new int(42),*r=new int(100);
    // r=q;
    // auto q2=make_shared<int>(42),
    // r2=make_shared<int>(100);
    // r2=q2;
    // shared_ptr<double>p1;
    // shared_ptr<int>p2(new int(42));
    // vector<int>*pivec=funcc();
    // auto f=funcccc(pivec);
    // auto pivecc=fun();
    // auto ff=funnnn(pivecc);
    // for(auto&i:*ff){
    //     cout<<i<<endl;
    // }
    // delete f;
    // int*pi=new int(1024);
    // string *ps=new string(10,'9');
    // vector<int>*pv=new vector<int>{0,1,2,3,4,5,6,7,8,9};
    // string*ps1=new string;
    // int*pi1=new int;
    // int*pi2=new int();
    // int obj;
    // // auto p2=new auto{1,2,3};
    // // const int(0);
    // int*p(new int(42));
    // auto q=p;
    // delete p;
    // p=nullptr;
    // int *p1=new int;
    // int *p2=new(nothrow)int;
    // // delete p1;
    // const int *pci=new const int(1024);
    // const string *pcs=new const string;
    // auto p1=new auto(obj);
    // int i,*pi1=&i,*pi2=nullptr;
    // double* pd=new double (33),*pd2=pd;
    // StrBlob b1;
    // {
    //     StrBlob b2={"a","b","c"};
    //     b1=b2;
    //     b2.push_back("about");
    //     cout<<b2.size()<<" "<<b1.size()<<endl;
    // }
    // cout<<" "<<b1.size()<<endl;

    // shared_ptr<string>p1;
    // shared_ptr<list<int>>p2;
    // if(p1&&p1->empty())
    //     *p1="hi";
    // shared_ptr<int>p3=make_shared<int>(42);
    // shared_ptr<string>p4=make_shared<string>(10,'9');
    // shared_ptr<int>p5=make_shared<int>();
    // auto p6=make_shared<vector<string>>();
    // auto p=make_shared<int>(42);
    // auto q(p);
    //     shared_ptr<int> r;
    //     r=make_shared<int>(41);
    //     cout<<r.use_count()<<" "<<*r<<" ";
    //           // r=q;
    
    // cout<<r.use_count()<<" "<<*r<<" ";
    // cout<<q.use_count()<<" "<<*q<<" ";
    // cout<<p.use_count()<<" "<<*p<<" ";
    // SD_multimet bookstore(42,hasher,eqOp);
    // map<string,vector<int>>m;
    // m["DSA"]={1,2,4};
    // auto kk=m.insert({"ads",{1,2,3}});
    // auto s=kk.first->first;
    // auto size=m.erase(string("DSA"));
    // auto pp=m.erase(kk.first);
    // auto ppp=m.erase(m.begin(),m.end());
    // for(const auto& i:m){
    //     for(const auto& p:i.second)
    //         cout<<p<<" ";
    // }
    // vector<string>v;
    // multiset<string>c;
    // set<string>ss;
    // auto p=ss.insert(string("ss"));
    // auto sss=ss.insert(ss.begin(),{"s"});    
    // map<string,string>m;
    // auto r=m.insert({"ss","ss"});
    // auto s=c.insert(c.begin(),{"s"});
    // auto q=m.insert(m.begin(),{"s","S"});
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