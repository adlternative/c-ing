#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
 
#include<string>
#include<stdexcept>
#include<iostream>
 
//前置声明
template <unsigned H, unsigned W> class Screen;
 
template <unsigned H, unsigned W>
std::ostream& operator<<( std::ostream&, Screen<H, W>& );
 
template <unsigned H, unsigned W>
std::istream& operator>>( std::istream&, Screen<H,W>& );
 
template <unsigned H, unsigned W> class Screen{
    //友元声明
    friend std::ostream& operator<< <H,W>( std::ostream&, Screen<H, W>& );
    friend std::istream& operator>> <H,W>( std::istream&, Screen<H,W>& );
public:
    typedef std::string::size_type pos;
 
    Screen( char c = ' ' ):
        cursor( 0 ),contents( H * W, c ) { }
 
    //接口成员
    char get() const { return contents[ cursor ]; }
    char get( pos row, pos col ) const
        { auto ret = check( row, col ); return contents[ret]; }
 
 
    Screen& set( char ch ) { contents[cursor] = ch; return *this; }
    Screen& set( pos row, pos col, char ch )
        { auto ret = check( row, col ); contents[ret] = ch; return *this; }
 
    Screen& move( pos row, pos col ) { cursor = check( row, col ); return *this; }
 
    Screen& display( std::ostream &os ) { do_display(os); return *this; }
    const Screen& display( std::ostream &os ) const { do_display(os); return *this; }
private:
    pos cursor;
    std::string contents;
    //辅助函数
    pos check( pos row, pos col ) const{//检查下标是否越界。
        if( row >= H )
            throw std::out_of_range( "invalid row" );
        if( col >= W )
            throw std::out_of_range( "invalid column" );
        return row * W + col;
    }
    void do_display( std::ostream &os ) const{
        for( auto i = 0; i < H; ++i ){
            for( auto j = 0; j < W; ++j )
                os << contents[ i * W + j ];
            os << std::endl;
        }
    }
};
 
 
template <unsigned H, unsigned W>
std::ostream& operator<<( std::ostream &os, Screen<H,W> &scr ){
    scr.do_display( os );
    return os;
}
 
template <unsigned H, unsigned W>
std::istream& operator>> ( std::istream &is, Screen<H,W> &scr ){
    std::string tmp;
    is >> tmp;
    scr.contents = tmp.substr( 0, H*W );
    return is;
}
 
#endif // SCREEN_H_INCLUDED
#include<iostream>
// #include"Screen.h"
 
using namespace std;
 
int main()
{
    Screen<5, 5> myScreen( 'X' );
    myScreen.move( 4, 0 ).set( '#' );
    cout << myScreen.get( 4, 0 ) << "\n\n";
 
    myScreen.display( cout );
 
    return 0;
}