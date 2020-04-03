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
    virtual double net_price(size_t n)const{return n*price;}
    virtual ~Quote()=default;
};
class Bulk_quote_two:public Quote{
public:
    Bulk_quote_two()=default;
    Bulk_quote_two(const string&book,double p,size_t qty,double disc)
        :Quote(book,p),max_qty(qty),discount(disc){}
    double net_price(size_t n)const override;

private:
    size_t max_qty=0;
    double discount=0.0;
};
double Bulk_quote_two::net_price(size_t n)const
{
    if(n<=max_qty)
        return (1-discount)*price*n;
    else    
        return price*n;
}

class Bulk_quote:public Quote{
public:
    Bulk_quote()=default;
    Bulk_quote(const string&book,double p,size_t qty,double disc):Quote(book,p),min_qty(qty),discount(disc){}
    double net_price(size_t)const override;
private:
    size_t min_qty=0;
    double discount=0.0;
};
double Bulk_quote::net_price(size_t cnt )const
{
    if(cnt>=min_qty)
        return cnt*(1-discount)*price;
    else    
        return cnt*price;
}

// Quote::Quote()
// {
// }

// Quote::~Quote()
// {
// }

double print_total(ostream&os,const Quote &item,size_t n)
{
    double ret=item.net_price(n);
    os<<"isbn  "<<item.isbn()<<"#sold:"<<n<<"total due:"<<ret<<endl;
    return ret;
}



int main()
{
    Quote q("sda",10);
    Bulk_quote bq("sd",3,9,0.8);
    print_total(cout,q,10);
    print_total(cout,bq,10);
    Quote*itemP=&bq;
    Bulk_quote*bulkP=static_cast<Bulk_quote*>(itemP);
    Bulk_quote*bulkP=dynamic_cast<Bulk_quote*>(itemP);
    Bulk_quote bulk;
    Quote item(bulk);
    item=bulk;
}