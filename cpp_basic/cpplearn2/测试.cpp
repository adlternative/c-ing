#include <iostream>
#include <string>
#include<cassert>
#include <vector>
#include"Screen.h"
#include"Sales_data.h"
using namespace std;

class ConstRef{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(ii){}
typedef int Type;
class Exercise{
public:
    typedef double Type;
    Type setVal(Type);
    Type intitVal();
private:
    Type val;
};
Exercise::Type Exercise::intitVal(){ val=1;return val;}

Exercise::Type Exercise::setVal(Type parm)
{
        val=parm+intitVal();
        return val;
}
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it !=v.end(); it++){
        cout<<*it;
    }
    cout<<endl;
}
bool str_has_upper(const string &s){
    for (decltype(s.size()) c = 0; c !=s.size(); c++)
    {
        if(isupper(c)){
            return true;
        }   
    }
    return false;
    
}
string&str_to_lower(string &s){
    for(string::size_type c=0;c!=s.size();c++){
        tolower(c);
    }
    return s;
}
bool compare(const string&a,const string&b)
{
    return a.at(0)>b.at(0);
}
vector<int>::iterator change_val(int n,vector<int>::iterator &it)
{
    *it=0;
    return it;
}


int constexpr size()
 {return /*rand()*/1;
/*expression must have a consta
nt value -- cannot call non-constexpr
 function "rand" (declared at line 453 
 of "/usr/include/stdlib.h"
*/}
//     int j=0;
//     constexpr int i=42;
//     constexpr const int *p=&i;
//     constexpr int *p1=&j;
//    constexpr int null=0;
//     constexpr const int *p=&null;
// auto func(int i)->int(*)[10];
// int odd[]={1,22,3,4,5};
// int even[]={1,23,3,4,5};
// decltype(odd)*arrPtr(int i)
// {
//     return (i%2)?&odd:&even;
// }
// string s[10]={"a","a""a""a""a""a""a""a""a""a""a"};
// string(&funn(int i))[10];
// decltype(s)&funcc(int i);
// auto funccc(int i)->string(&)[10];
// typedef string::size_type sz;
// // string screen(sz ht=24,sz wid=80 ,char);

// string screen(sz ht=24,sz wid=80 ,char backgrnd = '*');
// // string sscreen(sz wid=80 ,char backgrnd = ' ');
// string screen(sz ht,sz wid ,char backgrnd ){cout<<ht<<" "<<wid<<" "<<backgrnd<<endl;
// return  string("sda");}
// sz ht(){return 0;}
// sz wd=80;
// char def= '!';
// int add(int a,int b){return a+b;}
// int divv(int a,int b){return a/b;}
// int cheng(int a,int b){return a*b;}
// int sub(int a,int b){return a-b;}
// using fun=int(*)(int ,int);
// vector<fun>v;

// vector<decltype(add)*>v2={add,divv,cheng,sub};
// class x;
// class y;
// class x
// {
//     y*b;
// };
// class y
// {
//     x a;
// };
int main()
{
    // Sales_data first_item(cin);
    // Sales_data next;
    // Sales_data s(string("SD"));
    // Sales_data s1(cin);
    Sales_data s2(cin);
    
    // Screen myScreen(5,5,'x');
    // const Screen myScreen2(5,5,'q');
    // myScreen.move(4,0).set('#').display(cout);
    // cout<<"\n";
    // myScreen.display(cout).move(5,1);
    // cout<<"\n";
    // myScreen2.display(cout);
    // cout<<"\n";

    // for (auto &i : v2)
    // {
    //     cout<<i(1,2)<<endl;
    // }
    
    // char def='a';
    // def='a';
    // // sz wd=100;
    // string screen(sz=ht(),sz=wd,char=def);
    // string window; 
    // sz wd=100;//如果在默认实参声明之后的局部变量wd
    //不会影响默认实参的值 wd=80
    
    // assert(string("sad")=="sad");
    // window=screen();
    // window=screen(66);
    // window=screen(66);
    // window=screen(66,256);
    // window=screen(66,256,'#');
    // // window=screen(,,'?');
    // window=screen('?');//?-->63
    
    // initializer_list<int>li{3,4,5};
    // vector<int >v{3,4,5};
    // int sum=0;
    // for(auto it=li.begin();it!=li.end();it++){
    //     sum+=*it;
    // }
    // cout<<sum<<endl;
    // const int ci=42;
    // int i=ci;
    // int*const p=&i;
    // *p=0;
    // printf("%d",i);
    // cout<<ci;
    // double a,b;
    // cin>>a>>b;
    // try{
    //     if(b==0){
    //     throw(runtime_error("a ha/ 0"));
    //     }
    //     cout<<a/b<<endl;
    // }catch(runtime_error err){
    //     printf("!!!");
    // }
    // int ia[]={1,2,3,4,4};
    // auto ia2(ia);
    // printf("%d\n",*ia2);
    // int*beg=begin(ia);
    // int i=0,&r=i;
    // auto a=r;
    // const int ci=i,&cr=ci;
    // auto b=ci;
    // auto c=cr;
    // long double ld=3.14159;
    // int c(ld);/*int s{ld};*/
    // int s{1};//如果用ld则错
    // string a;//空串
    // int i={3};
    // int j=(3.14);
    // double e;
    // double r=e=9.9;
    // // int b=d=1;
    // cout<<r<<e<</*s*<<*/endl;
    
    // using sas = int;
    // int i=0;
    // const int ci=i,&cr=ci;
    // const auto &j=42;
    // auto k=ci,&l=i;
    // auto &m=ci,*p=&ci;
    // // auto &n=i,*p2=&ci;
    // int i=0,&r=i;
    // auto a=r;
    // auto b=ci;
    // auto c=cr;
    // auto d=&i;
    // auto e=&ci;
    // auto g=ci;
    // a=42;
    // b=42;
    // c=42;
    // // d=42;
    // // e=42;
    // g=42;
    // int i;
    // const int ci=0,&cj=ci;
    // decltype(ci)x=0;
    // decltype(cj)y=x;
    // decltype(cj)z;
    // decltype((i))d;//引用
    // int a=3,b=4;
    // decltype(a) c=a;
    // decltype((b))d=a;
    // ++c;
    // ++d;
    // cout<<a;
    // int a=2,b=4;
    // decltype(a)c=a;
    // decltype(a=b)d=a;//表达式返回引用且a=b不做运算
    // d++;
    // cout<<a<<d;
    // constexpr int *p=nullptr;
    // const int *p=nullptr;

    // constexpr int mf=20;
    // constexpr int limit =mf+1;
    // constexpr int sz=size();
    // constexpr int *np=nullptr;
    // int reused=0;
    // int p=::reused;
    // cout<<::reused<<p<<endl;
    // extern double pi=3.14;//an initializer is not allowed on a local declaration of an extern variable
    // int  q;
    // cout<<q<<str;
    // // int &i=1;
    // double d=0,&r2=d;
    // r2=3.13;
    // int z=0,&r1=z; 
    // r2=r1;
    // r1=d;
    // int *p1=nullptr;
    // int *p2=0;
    // int *p3=NULL;
    // void*p;
    // printf("%p",p);
    // int *ip,i,&r=i;
    // const int i=512;
    // const int &r2=42;
    // int &r2=43;
    // int &s=d;
    // double dval=3.14;
    // const int &ri=dval;//等于以下操作
    // const int temp=dval;
    // const int &ri=temp;//绑定临时量
    // inr &rp=dval;可见这样会引发编译错误
    //如果ri没有const则会导致ri绑定在临时量而非dval上，且可改变，
    //然而const的情况下大家都const不可以改变所以是允许的！
    // cout<<ri;
    // // int &r=0;
    // int i2=1;
    // int * const p2=&i2;
    // const int i=-1,&r=0;
    // const int *const p3=&i2;
    // const int *p1=&i2;
    // // const int &const r2=i2;
    // const int i3=i,&rr=i;

    // int *const cp/*=&i2*/;
    // const int ic/*=0*/,&r=ic;
    // const int *const p3/*=&i3*/;
    // const int *p/*=&i2*/;
    // int i=0;
    // int *const p1=&i;
    // const int ci=42;
    // const int *p2=&ci;
    // const int *const p3=p2;
    // const int &r=ci;
    // const int v2=0;int v1=v2;//顶层
    // int*p1=&v1,&r1=v1;//
    // const int *p2=&v2;//底层
    // int i;
    // const int*const p3=&i;//底层和顶层
    // const int&r2=v2;//底层
    // r1=v2;
    // p1=p2;//错
    // p2=p1;
    // p1=p3;//错
    // p2=p3;

    // int i=42;
    // int &    
    // string str("hhello");
    // str.insert(1,"111");
    // cout<<str<<endl;
    // str.erase(1,3);
    // cout<<str<<endl;
    // string st("hello");
    // int pos1=str.find(st);
    // if(pos1==-1){
    //     cout<<"没找到"<<endl;
    // }
    // int pos2=str.rfind("lo");
    // cout<<pos1<<endl;
    // cout<<pos2<<endl;
    // str.replace(1,3,"0000");//4个
    // cout<<str<<endl;
    // str+=st;
    // cout<<str<<endl;
    // str.append(st,1,3);
    // cout<<str<<endl;

    // cout<<"字符串大小"<<st.size()<<endl;
    // string::size_type size =st.size();//不用int 是为了保证在字符串很大的时候能正确输出
    // if(!st.empty()){
    //     cout<<"feikong";
    // }
    // string s1=st;
    // if(s1.compare(st)==0){
    //     cout<<"s1=st"<<endl;
    // }
    // cout<<s1;
    // string s3=s1+st;
    // cout<<s3;
    // // string s4="hello"+",";
    // for (string::size_type x = 0; x !=s3.size(); x++){
    //     cout<<s3[x]<<' ';
    // }
    // for (string::size_type x = 2; x !=s3.size(); x++){
    //     s3[x]='*';
    // }
    // cout<<s3<<endl;
    // string subStr=s3.substr(1,3);
    // cout<<"subStr="<<subStr<<endl;
    // string email="zhangsan@qq.com";
    // int  pos=email.find("@");
    // cout<<pos<<endl;
    // cout<<email.substr(0,pos)<<endl;

    // cout<<size<<endl;
    // string name;
    // cout<<"your name"<<endl;
    // getline(cin,name);
    // cout<<name<<endl;
    // int count=0;
    // while(cin>>name){
    //     cout<<name<<endl;
    //     if(++count==3)
    //     break;
    // }
    // while(getchar()!='\n'){
    //     cout<<"!";
    //     continue;
    // }
    // string str1("Sad");
    // string str5;
    // cout<<str5.assign("helloc++",5);
    // str5=str1;
    // vector<int> v1;
    // for (int  i = 0; i < 10; i++){
    //     v1.push_back(i);
    // }
    // vector<int>v2(v1);
    // printVector(v1);
    // printVector(v2);
    // vector<int>v3(++v1.begin(),v1.end());
    // printVector(v3);
    // v1=v3;
    // printVector(v1);
    // v3.assign(++v1.begin(),v1.end());
    // v3.assign(10,100);
    //     vector<int>v4;
    // if(!v1.empty()){
    //     cout<<"feikong"<<endl;
    //     cout<<v1.capacity()<<endl;
    //     cout<<v1.size()<<endl;
    // }
    // v1.resize(15);//默认填充0
    // printVector(v1);
    // v1.resize(5);
    // printVector(v1);
    // v1.pop_back();
    // printVector(v1);
    // v1.insert(v1.begin(),100);
    // printVector(v1);
    // v1.insert(v1.begin(),2,1000);
    // v1.insert(v1.end(),2,1000);
    // v1.erase(v1.begin());
    // printVector(v1);
    // v1.erase(v1.begin(),v1.end());
    // printVector(v1);
    // v1.clear();
    // printVector(v1);
    // cout<<v1[1];
    // cout<<v1.at(2);
    // cout<<v1.front();
    // cout<<v1.back()<<endl;
    // v1.swap(v2);
    // printVector(v1);
    // printVector(v2);
    // for (int i = 0; i < 10000; i++)
    // {
    //     v1.push_back(i);
    // }
    // cout<<v1.capacity()<<endl;
    // cout<<v1.size()<<endl;
    // v1.resize(3);
    // cout<<v1.capacity()<<endl;
    // cout<<v1.size()<<endl;
    // vector<int>(v1).swap(v1);//前面匿名对象,容器交换,匿名自动销毁
    // cout<<v1.capacity()<<endl;
    // cout<<v1.size()<<endl;
    // v1.reserve(10000);
    // int*p=NULL,num=0;
    // for (int i = 0; i < 10000; i++)
    // {
    //     v1.push_back(i);
    //     if(p!=&v1[0]){
    //         p=&v1[0];
    //         num++;
    //     }
    // }
    // int s,d;
    // cin>>s;
    // cout<<num<<endl;
    /*
    cin>>d;
    */
//    std::cout<<"/*";
//     cout<<"*/";
//     (++s)++;//左值
    // (s++)++;//右值

    // cout>>/*"*/"*/;
    // // cout<</*"*/"/*"*/;
    // return 0;*/
    // 测试.cpp:151:15: error: expected primary-expression before ‘/’ token
    //  return 0;*/
    // int sum=0,value=0;
    // while(cin>>value){
    //     sum+=value;
    // }
    // cout<<sum<<endl;
    // bool b=42;
    // int i=b;
    // cout<<i<<endl;
    // L'a';//(wchar_t)L'\x61'
    // u8"hi";
    // 42ULL;
    // 1E-3F;
    // 3.13L;
    // 'a';
    // L'a';
    // "a";
    // L"a";//(const wchar_t [2])L"a"
    // 10u;
    // 10uL;
    // 012;
    // 0XC;
    // 3.14L;
    // 10u;
    // 10.;
    // 10e-2;
    // /*int month=09;*/int day=07;
    // cout<<("F\145rgus?\012");//10换行
    // cout<<"??";//145=64+8*4+5=101;
    // 3.14e1L;
    // 1024.0f;
    // 3.14L;
    // printf("2\tM\n");
}