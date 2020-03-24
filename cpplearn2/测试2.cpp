#include <iostream>
#include <string>
#include<cassert>
#include <vector>
#include"Screen.h"
#include"Sales_data.h"
using namespace std;
class A{
public: 
    A(int a,int c):constNum(a),c(c){}
private:
    const int c;
    static int staticNum;
    const int constNum;
};
int A::staticNum =100;

class B{
public:
    const static int num1;
    const static int num2=12;
};
const int B::num1=12;
const int B::num2;
// class A{}
// static const int vecSize;
// class Example{
// public:
//     Example(int B):b(B){}
//     static int a;
//     const int b;
//     static const double rate;
//     static const  int vecSize;
//     static void print(const int &s){}
//     void prints(const int &s){}
//     // static vector<double>vec(vecSize);
// };
// const double Example::rate=10;
// const  int Example::vecSize=10;
// // vector<double> Example::vec;
// class Bar{
// public:
// private:
//     static Bar mem1;
//     Bar *mem2;
//     // Bar mem3;
// };


// class Account{
// public:
//     void calculate(){amount+=amount*interestRate;}
//     static double rate(){return interestRate;}
//     static void rate(double);
//     void func(const int &);
// private:
//     std::string owner;
//     double amount;
//     static double interestRate;
//     static double initRate();
//     static constexpr int period=30;
//     double daily_tb1[period];
// };
// constexpr int Account::period;
// void Account::func(const int &i){}

// void Account::rate(double newRate)
// {
//     interestRate=newRate;
// }

// class Debug{
// public:
//     constexpr Debug(bool b=true):hw(b),io(b),other(b){}
//     constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}
//     constexpr bool any(){return hw||io||other;}
//     void set_io(bool b){io=b;}
//     void set_hw(bool b){hw=b;}
//     void set_other(bool b){other=b;}
// private:
//     bool hw;
//     bool io;
//     bool other;
// };


// class qq{
// public:
//     qq(int r=0):a(r){}
//     // qq(int i):a(i){}
//     qq(const std::string&str):s(str){}
// private:
//     int a;
//     string s;    
// };
// vector<qq>vec(10);
// struct pp{
//     qq q;
// };
// pp p;
// struct bb{
//     bb(){}
//     qq qqq;
// private :
//     int a;
// };
int main()
{
    cout<<(B::num2)<<endl;
//         Account a;
//         a.func(Account::period);
//     // constexpr int Account::period;
//     Example::print(Example::rate);
//     Example e;
//     e.prints(Example::rate);
//     double r;
//     r=Account::rate();
//     Account ac1;
//     // ac1.func(Account::period);
//     Account *ac2=&ac1;
//     r=ac1.rate();
//     r=ac2->rate();

//      Debug io_sub(false,true,false);
//     if(io_sub.any())
//         cerr<<"print appropriate error messages"<<endl;
//      Debug prod(false);
//     if(prod.any()){
//         cerr<<"print an error message"<<endl;
//     }
    // Sales_data s;
    // Screen scr(1,2,'c');
    // scr.display(cout);
    // cout<<s.isbn();
    // vector<int >a(10);
    // string nullbook="000";
    // Sales_data item;
    // // item.combine(nullbook);
    // // item.combine("asd");
    // // item.combine(string("9"));
    // // item.combine(nullbook="9");
    // item.combine(Sales_data("9"));
    // // item.combine(cin);
    // item.combine(Sales_data(nullbook));
    // item.combine(static_cast<Sales_data>(cin));
    
    return 0;
}