#include<iostream>
#include<string>
using namespace std;
class Sales_data
{
friend std::ostream&operator<<(std::ostream&os,const Sales_data&item);
friend std::istream&operator>>(std::istream&is,Sales_data&item);
friend bool operator==(Sales_data&rhs,Sales_data&lhs);
friend bool operator!=(Sales_data&rhs,Sales_data&lhs);

friend std::ostream&print(std::ostream&os,const Sales_data&item);
friend std::istream&read(std::istream&is,Sales_data&item);
friend Sales_data add(const Sales_data&lhs,const Sales_data&rhs);
friend Sales_data operator+(const Sales_data&lhs,const Sales_data&rhs);

public:
    Sales_data(const std::string &s,unsigned n,double p):
    bookNo(s),units_sold(n),revenue(p*n){/*std::cout<<"0\n";*/}

    Sales_data():Sales_data(" ",0,0){/*std::cout<<"1\n";*/};
    explicit Sales_data(std::string s):Sales_data(s,0,0){/*std::cout<<"2\n";*/}
    // Sales_data(const std::string &s):bookNo(s){}
    explicit Sales_data(std::istream&is):Sales_data(){/*std::cout<<"3\n";*/read(is,*this);}
    // Sales_data(const std::string&s,unsigned n,double p)
    // {
    //     revenue=p*n;
    //     bookNo=s;
    //     units_sold=n;
    // }
    std::string isbn()const{return bookNo;}
    Sales_data&combine(const Sales_data&);
    Sales_data&operator+=(const Sales_data&rhs);
private:
    double avg_price()const;
    double revenue=0.0;
    unsigned units_sold=0;
    string bookNo;
};
Sales_data&Sales_data::operator+=(const Sales_data&rhs)
{
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}
bool operator==(Sales_data&rhs,Sales_data&lhs)
{
    return lhs.isbn()==rhs.isbn()&&lhs.units_sold==rhs.units_sold&&lhs.revenue==rhs.revenue;
}
bool operator!=(Sales_data&rhs,Sales_data&lhs)
{
    // return lhs.isbn()!=rhs.isbn()||lhs.units_sold!=rhs.units_sold||lhs.revenue==rhs.revenue;
    return !(rhs==lhs);
}

Sales_data add(const Sales_data&lhs,const Sales_data&rhs)
{
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}
std::ostream&print(std::ostream&os,const Sales_data&item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

std::istream&read(std::istream&is,Sales_data&item)
{
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}

double Sales_data::avg_price()const
{
    if(units_sold)
        return revenue/units_sold;
    else
        return -1;
}
Sales_data& Sales_data::combine(const Sales_data&rhs)
{
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}
Sales_data operator+(const Sales_data&lhs,const Sales_data&rhs)
{
    Sales_data ret=lhs;
    ret+=rhs;
    return ret;
}
std::ostream&operator<<(std::ostream&os,const Sales_data&item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}
std::istream&operator>>(std::istream&is,Sales_data&item)
{
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    if(is)
        item.revenue=price*item.units_sold;
    else
        item=Sales_data();
    return is;
}





