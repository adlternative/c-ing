#include<iostream>
#include"Sales_item.h"
#include<vector>
#include<string>
using namespace std;
int a()
{return 1;}
int main()
{
    int s[a()];
    // vector<int>v1(10);
    // vector<int>v2{10};
    // vector<string>v3{"as"};
    // // vector<string>v3("as");
    // vector<string>v4(10,"sad");
    // vector<vector<int>>ivec;
    // // vector<string>svec=ivec;
    // vector<string>sevc(10,"null");
    // string s;
    // while(cin>>s){
    //     sevc.push_back(s);
    // }
    // for (auto &i : sevc)
    // {
    //     i+="asd";
    // }
    // for (auto i : sevc)
    // {
    //     cout<<i<<endl;
    // }
    // // sevc==sevc;
    // // sevc==v1;
    // vector<Sales_item>a;
    // vector<Sales_item>b;
    // if(a==b){cout<<" ..";};
    // string str;
    // vector<string>vs(3);
    // while(cin>>str){
    //     vs.push_back(str);
    // }
    // for (decltype(vs.size()) i = 0; i !=vs.size(); i++)
    // {
    //     for (auto &c : vs[i])
    //     {
    //         c=toupper(c);
    //     }
        
    // }
    // for (decltype(vs.size()) i = 0; i !=vs.size(); i++)
    // {
    //     cout<<vs[i]<<endl;
    // }
    // for (decltype(vs.begin()) it = vs.begin(); it < vs.end(); it++)
    // {
    //     cout<<(*it)[1]<<endl;   
    // }
    // for (auto it = vs.cbegin(); it!=vs.cend()&&!it->empty(); it++)
    // {
    //     cout<<*it<<"?"<<endl;
    // }
    // vector<string>::iterator it1=vs.begin();
    // vector<string>::iterator it2=vs.end();
    // vector<string>::iterator it =it1+it2;
    // auto dif=it1-it2;
    // int int_arr[]={1,2,3};
    // vector<int> ivec(begin(int_arr),end(int_arr));
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // for (const auto &row : arr)
    // {
    //     for(auto col:row)
    //         cout<<col<<endl;        
    // }
    // int j;
    // double s=static_cast<double>(j);
    // int d;
    // void*p=&d;
    // double *dp=static_cast<double*>(p);
    // const char*pc;
    // char *p=const_cast<char*>(pc);
    // const char*cp;
    // // char*q=static_cast<char*>(cp);
    // static_cast<string>(cp);
    // int *ip;
    // char*pc=reinterpret_cast<char*>(ip);
    // const_cast<string>(cp);
    // int i=12;
    // double d=3.3;
    // i*=static_cast<int>(d);
    // cout<<i;
    int i;double d;const string *ps;char*pc;void*pv;
    // pv=static_cast<void*>(ps);
    // pv=reinterpret_cast<void*>(ps);
    pv = static_cast<void*>(const_cast<string*>(ps));//需要先去掉const再用static 转型
    i=static_cast<int>(*pc);
    pv= static_cast<void*>(&d);

    
    pc=static_cast<char*>(pv);
    pc=reinterpret_cast<char*>(pv);
}   