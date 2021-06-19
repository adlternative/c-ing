#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
 
#include<iostream>
class Sales_data{
    //友元函数
    friend struct std::hash<Sales_data>;
    friend std::istream& operator >> ( std::istream&, Sales_data& );
    friend std::ostream& operator << ( std::ostream&, const Sales_data& );
    friend bool operator < ( const Sales_data&, const Sales_data& );
    friend bool operator == ( const Sales_data&, const Sales_data& );
    friend Sales_data add( Sales_data &rhs, Sales_data &lhs );
    friend std::istream& read( std::istream& in, Sales_data &item );
    friend std::ostream& print( std::ostream &out, const Sales_data &rhs );
 
    public:  //构造函数
 /*       Sales_data( const std::string &book, const unsigned units, const double sellingprice, const double saleprice ) :
            bookNo( book ), units_sold( units ), selling_price( sellingprice ), sale_price( saleprice )
            {
                if( selling_price )
                    discount = sale_price / selling_price;
                std::cout << "四个参数的构造函数的函数体" << std::endl;
            }
*/
        //委托构造函数:
 /*       Sales_data(): Sales_data( "", 0, 0, 0 ) { std::cout << "无参数的构造函数的函数体" << std::endl; }
        Sales_data( const std::string &s ) : Sales_data( s, 0, 0, 0 ) { std::cout << "接受字符串的构造函数的函数体" << std::endl; };
        Sales_data( std::istream &is ) : Sales_data() { read( is, *this ); std::cout << "接受输入流的构造函数的函数体" << std::endl; }
*/
        Sales_data() = default;
        Sales_data( const std::string &book ): bookNo( book ) { }
        Sales_data( const std::string &book, const unsigned units, const double sellingprice, const double saleprice );
        Sales_data( std::istream &is ) { is >> *this; }
 
    public:
        Sales_data& operator += ( const Sales_data& );
        std::string isbn() const { return bookNo; }
        Sales_data& combine( const Sales_data &rhs );
 
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double selling_price = 0.0;
        double sale_price = 0.0;
        double discount = 0.0;
};
 
 
inline bool compareIsbn( const Sales_data&lhs, const Sales_data&rhs )
{
    return lhs.isbn() == rhs.isbn();
}
 
Sales_data operator + ( const Sales_data&, const Sales_data& );//声明
 
//友元函数定义
inline bool operator == ( const Sales_data &lhs, const Sales_data &rhs )
{
    return lhs.units_sold == rhs.units_sold && lhs.sale_price == rhs.sale_price &&
            lhs.isbn() == rhs.isbn();
}
 
inline bool  operator != ( const Sales_data &lhs, const Sales_data &rhs )
{
    return !( lhs == rhs );
}
 
inline bool operator<( const Sales_data &lhs, const Sales_data &rhs )
{
    return lhs.bookNo < rhs.bookNo;
}
 
inline Sales_data add( Sales_data &rhs, Sales_data &lhs )
{
    Sales_data sum = rhs;
    sum.combine( lhs );
    return sum;
}
inline std::ostream& print( std::ostream &out, const Sales_data &rhs )
{
    out << rhs.bookNo << " " << rhs.units_sold << " " << rhs.selling_price << " "
        << rhs.sale_price << " " << rhs.discount;
    return out;
}
 
inline std::istream& read( std::istream& in, Sales_data &item )
{
 
 
    in >> item.bookNo >> item.units_sold >> item.selling_price >> item.sale_price;
    return in;
}
 
//构造函数
Sales_data::Sales_data( const std::string &book, unsigned units, double sellingprice, double saleprice )
{
    bookNo = book;
    units_sold = units;
    selling_price = sellingprice;
    sale_price = saleprice;
    if( selling_price != 0 )
        discount = sale_price / selling_price;
}
 
 
 
//成员函数
Sales_data& Sales_data::operator += ( const Sales_data &rhs )
{
    sale_price = ( rhs.sale_price * rhs.units_sold + sale_price * units_sold )
                /( rhs.units_sold + units_sold );
    selling_price = ( rhs.selling_price * rhs.units_sold + selling_price * units_sold )
                /( rhs.units_sold + units_sold );
    units_sold += rhs.units_sold;
 
    if( sale_price != 0 )
        discount = sale_price / selling_price;
 
    return *this;
}
 
 
Sales_data operator + ( const Sales_data &lhs, const Sales_data &rhs )
{
    Sales_data tmp( lhs );
    tmp += rhs;
 
    return tmp;
}
 
 
std::istream& operator >> ( std::istream &in, Sales_data &s )
{
    in >> s.bookNo >> s.units_sold >> s.selling_price >> s.sale_price;
 
    if( in && s.selling_price != 0 )
        s.discount = s.sale_price / s.selling_price;
    else
        s = Sales_data();
 
    return in;
}
 
 
std::ostream& operator << ( std::ostream &out, const Sales_data &s )
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.selling_price << " " << s.sale_price << " " << s.discount;
 
    return out;
}
 
Sales_data& Sales_data::combine( const Sales_data &rhs )
{
    units_sold += rhs.units_sold;
    sale_price = ( units_sold * sale_price + rhs.units_sold * rhs.sale_price )
                / ( units_sold + rhs.units_sold );
    if( selling_price != 0 )
        discount = sale_price / selling_price;
 
    return *this;
}
 
namespace std{
    template <> struct hash<Sales_data>{
        typedef size_t result_type;
        typedef Sales_data argument_type;
 
        size_t operator()( const Sales_data & s ) const;
    };
 
    size_t hash<Sales_data>::operator() ( const Sales_data &s ) const{
        return hash<string>()( s.bookNo ) ^
            hash<unsigned>() ( s.units_sold ) ^
            hash<double>() ( s.selling_price ) ^
            hash<double>() ( s.sale_price );
    }
}
 
#endif // SALES_DATA_H_INCLUDED

