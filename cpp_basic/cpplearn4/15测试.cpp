#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cstring>
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
// #include"./测试5.cpp"
using namespace std;
using namespace std::placeholders;
using line_no =vector<string>::size_type;
class Quote
{
private:
    string bookNo;
protected:
    double price =0.0;
public:
    Quote()=default;
    Quote(const string &book,double sales_price):bookNo(book),price(sales_price){}
    string isbn()const{return bookNo;}
    virtual Quote*clone()const&{return new Quote(*this);}
    virtual Quote*clone()&&{return new Quote(move(*this));}
    
    virtual double net_price(size_t n)const{return n*price;}
    virtual void func(int i=0){cout<<i;}
    virtual void debug()const{cout<<"bookNo"<<bookNo<<"price"<<price<<endl;}
    virtual ~Quote()=default;
    void naturalfunc(){cout<<"Dad"<<__func__<<endl;}
};



class Dis_quote:public Quote{
public:
pair<size_t,double>discount_policy()const{return{quantity,discount};}
    Dis_quote()=default;
    Dis_quote(const string&book,double price,size_t qty,double disc):
        Quote(book,price),quantity(qty),discount(disc){}
    double net_price(size_t)const =0;
protected:
    size_t quantity=0;
    double discount=0.0;
};
// Quote::Quote()
// {
// }

// Quote::~Quote()
// {
// }
class Bulk_quote:public Dis_quote{
public:
    using Dis_quote::Dis_quote;
    // Bulk_quote()=default;
    // Bulk_quote(const string&book,double p,size_t qty,double disc):Dis_quote(book,p,qty,disc){}
    Bulk_quote*clone()const&{return new Bulk_quote(*this);}
    Bulk_quote*clone()&&{return new Bulk_quote(move(*this));}
    

    double net_price(size_t)const override;
    virtual void debug()const override{Quote::debug();cout<<"min_qty"<<quantity<<"discount"<<discount<<endl;}
    void naturalfunc(){cout<<"sun"<<__func__<<endl;}
private:
};
double Bulk_quote::net_price(size_t cnt )const
{
    if(cnt>=quantity)
        return cnt*(1-discount)*price;
    else    
        return cnt*price;
}
double print_total(ostream&os,const Quote &item,size_t n)
{
    double ret=item.net_price(n);
    os<<"isbn  "<<item.isbn()<<"#sold:"<<n<<"total due:"<<ret<<endl;
    return ret;
}
class Bulk_quote_two:public Dis_quote{
public:
    Bulk_quote_two()=default;
    Bulk_quote_two(const string&book,double p,size_t qty,double disc):Dis_quote(book,p,qty,disc){}
    double net_price(size_t n)const override;
    void func(int i=1){cout<<i<<endl;}
    virtual void debug()const override{Quote::debug();cout<<"max_qty"<<quantity<<"discount"<<discount<<endl;}
    void naturalfunc(){cout<<"sun"<<__func__<<endl;}
private:
};
double Bulk_quote_two::net_price(size_t n)const
{
    if(n<=quantity)
        return (1-discount)*price*n;
    else    
        return price*n;
}
class Bulk_quote3:public Dis_quote{
public:
    Bulk_quote3()=default;
    Bulk_quote3(const  std::string&book,double price,
    size_t qty,double disc):Dis_quote(book,price,qty,disc){}
    double net_price(size_t)const override;
};

class Base{
public:
    int pub_mem(){}
protected:
    int prot_mem=0;
private:
    char priv_mem=0;
};
//子类不可访问父类的private
struct Pub_Derv:public Base{
    void memfcn(Base&b){b=*this;}
    int f(){ pub_mem();}
    int f2(){return prot_mem;}
    // int f3(){return priv_mem;}
};
struct Priv_Derv:private Base{
    void memfcn(Base&b){b=*this;}
    int f(){ pub_mem();}
    int f2(){return prot_mem;}
    // int f3(){return priv_mem;}
};
struct Prot_Derv:protected Base{
    void memfcn(Base&b){b=*this;}
    int f(){pub_mem();}
    int f2(){return prot_mem;}
    // int f3(){return priv_mem;}
};
struct p1:public Pub_Derv{
    void memfcn(Base&b){b=*this;}
    int use_base(){ pub_mem();}
    int use_base2(){return prot_mem;}
    // char use_base3(){return priv_mem;}
};
struct p2:public Priv_Derv{
    // void memfcn(Base&b){b=*this;}
    // int use_base(){ pub_mem();}
    // int use_base2(){return prot_mem;}
    // char use_base3(){return priv_mem;}
};
struct p3:public Prot_Derv{
    void memfcn(Base&b){b=*this;}

    int use_base(){ pub_mem();}
    int use_base2(){return prot_mem;}
    // char use_base3(){return priv_mem;}
};
class graph
{
private:
public:
    graph(double xlen=0,double ylen=0):x(xlen),y(ylen){}
    virtual ~graph();
    virtual double size()=0;
protected:
    double x;
    double y;

};
class graph_2D:public graph
{
private:
public:
    graph_2D(double xlen=0,double ylen=0):graph(xlen,ylen){}
    virtual ~graph_2D();
protected:
};
class graph_3D:public graph
{
private:
public:
    graph_3D(double xlen=0,double ylen=0,double zlen=0):graph(xlen,ylen),z(zlen){}
    virtual ~graph_3D();
protected:
    double z;
};
class ball:graph_3D
{
private:
    double r=0;
public:
    ball(double xlen=0,double ylen=0,double zlen=0,double rlen=0):graph_3D(xlen,ylen,zlen),r(rlen){}
    ~ball();
    virtual double size()override{return 3,14*r*r*r;}
};
class cone:graph_3D
{
private:
    double h=0;
    double r=0;
public:
    cone(double xlen=0,double ylen=0,double zlen=0,double hlen=0,double rlen=0)
    :graph_3D(xlen,ylen,zlen),h(hlen),r(rlen){}
    ~cone();
    virtual double size()override{return 3.13*r*r*h;}
};

class circular:graph_2D
{
private:
    double r=0;
public:
    circular(double xlen=0,double ylen=0,double rlen=0):graph_2D(xlen,ylen),r(rlen){}
    
    ~circular();
    virtual double size()override{return 3.14*r*r;}
};
class square:graph_2D
{
private:
    double sidelen=0;
public:
    square(double xlen=0,double ylen=0,double rlen=0):graph_2D(xlen,ylen),sidelen(rlen){}
    
    ~square();
    virtual double size()override{return sidelen*sidelen;}
};
class Base2{
public:
    virtual int fcn(){cout<<"!";}

};
class D1:public Base2{
public:
    using Base2::fcn;
    void fcn(int a);
    void fcn(int a,int b);
};



class F
{
public:
    F() = default;
    F(const F& f) { cout << "new" << endl; }               //显示定义拷贝构造
    F(const F&& f) { cout << "move" << endl; }             //显示定义移动构造
    F& operator=(const F& f) { cout << "eq" << endl; }
};
class F2
{
public:
    F m_f1;
    // ~F2() { }       //加这行，输出2个new，不加输出new和move
};
F2 test(F2 f) { return f; }
int m()
{
    F2 f1;
    /*F2 &&f3 = */test(f1);
}
class t1{
public:
    t1()=default;
    // t1(const t1&tt)/*=delete;*/{cout<<"拷贝"<<endl;}
    // t1(t1&&ttt)/*=delete;*/{cout<<"移动"<<endl;}
    // ~t1()=delete;
    // ~t1(){};
    virtual ~t1()=default;
};
class t2:t1{
public:
    t2()=default;
    t2(t2&&ttt){}
    // t1 tt(std::move);
};

class t3{
public:

    t3&operator=(const t3&tt){
            c=tt.c;
    }
private :
    int c;
    
};
class t4:public t3{
public:
    t4(const t4&d):t3(d),a(1){}
    t4(t4&&d):t3(std::move(d)),a(0){}
    t4&operator=(const t4&rhs){
        t3::operator=(rhs);
        a=rhs.a;
        return *this;
    }
private:    
    int a;

};
class Basket{
public:
    // void add_item(const shared_ptr<Quote>&sale){item.insert(sale);}
    void add_item(const Quote&sale){item.insert(shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote&&sale){item.insert(shared_ptr<Quote>(move(sale).clone()));}
    double total_receipt(ostream&)const;
private:
    static bool compare(const shared_ptr<Quote>&lhs,
    const shared_ptr<Quote>&rhs){return lhs->isbn()<rhs->isbn();}
    multiset<shared_ptr<Quote>,decltype(compare)*>item{compare};
};
double Basket::total_receipt(ostream&os)const
{
    double sum=0.0;
    for(auto iter=item.cbegin();iter!=item.cend();iter=item.upper_bound(*iter)){
        sum+=print_total(os,**iter,item.count(*iter));
    }
    os<<"total sale:"<<sum<<endl;
}

int main()
{
    Quote q("das",2);
    Bulk_quote e("sad",2,2,0.2);
    // vector<Quote>v;
    // v.push_back(q);
    // v.push_back(e);
    // vector<shared_ptr<Quote>>v2;
    // v2.push_back(make_shared<Quote>(q));
    // v2.push_back(make_shared<Bulk_quote>(e));
    Basket b;
    b.add_item(q);
    b.add_item(std::move(e));
    b.total_receipt(cout);
    // int sum=0;
    // for(auto i:v){
    //     sum+=i.net_price(12);
    // }
    // cout<<sum;
    // sum=0;
    //     for(auto i:v2){
    //     sum+=i->net_price(12);
    // }
    // cout<<sum;

    t1 t;
    t1 ttt(t);
    t1 tttt(std::move(t));

    t2 tt;
    t2 ttttt(std::move(tt));

    m();
D1 d;
d.fcn();
Pub_Derv s;
s.pub_mem();
Base*p=&s;
Prot_Derv s2;
// Base*p=&s2;
// s2.pub_mem();
Priv_Derv s3;
// Base*p=&s3;
// s3.pub_mem();
p1 ppp;
p=&ppp;

ppp.pub_mem();
p2 pppp;
// Base*p=&pppp;

// pppp.pub_mem();
p3  pp;
// pp.pub_mem();//pub被改成proc了那么就类外访问不了
// Base*p=&pp;//根据前一行那么就不可访问了完整的Base区域（proc部分类外访问不到）
pp.use_base();
// pp.pub_mem();
cout<<pp.use_base2();


    // Quote q("sda",10);
    // // Dis_quote qq;
    // Bulk_quote bq("ASD",2,3,22);
    // Bulk_quote bq("sd",3,9,0.8);
    // print_total(cout,q,10);
    // print_total(cout,bq,10);
    // Quote*itemP=&bq;
    // Bulk_quote*bulkP=static_cast<Bulk_quote*>(itemP);
    // Bulk_quote*bulkP=dynamic_cast<Bulk_quote*>(itemP);
    // Bulk_quote bulk;
    // Quote item(bulk);
    // item=bulk;
    // Bulk_quote_two s("sd",3,9,0.8);
    // s.Quote::func();
    // q.func();
    // // Quote&stoq=s;
    // Quote*stoq2=&s;
    // stoq2->func();
    // stoq.func();
    // q.debug();
    // s.debug();
    // q.naturalfunc();
    // s.naturalfunc();
    // Quote&q2=s;
    // q2.naturalfunc();
    // // q2.debug();
    // Quote*q3=&s;
    // q3->naturalfunc();
    // q3->debug();

}