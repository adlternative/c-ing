#include<iostream>
#include<string>
#include<vector>
using namespace std;
// int height;
struct Screen
{
    friend class Window_mgr;
public:
    using pos= std::string::size_type;
    Screen()=default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
    Screen(std::istream&is);
    char get()const{return contents[cursor];}
    inline char get(pos ht,pos wd)const;
    // void setHeight(pos);
    pos size()const;
    Screen &move(pos r,pos c);
    Screen&set(char);
    Screen&set(pos,pos,char);
    Screen&clear(char=bkground);
    Screen&display(std::ostream &os)
        {do_display(os);return *this;}
    const Screen&display(std::ostream &os)const
        {do_display(os);return *this;}
    void some_member()const;
private:
    static const char bkground;
    void do_display(std::ostream &os)const{os<<contents;}
    mutable size_t access_ctr;
    pos cursor =0;
    pos height =0;pos width=0;
    std::string contents;
};
// Screen::pos verify(Screen::pos);
// void Screen::setHeight(pos var){
//     height=verify(var);
// }
class Window_mgr
{
public:
    using ScreenIndex =std::vector<Screen>::size_type;
    ScreenIndex addScreen(const Screen&);
    void clear(ScreenIndex);
private:
    std::vector<Screen>screens{Screen(24,80,' ')};
};
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen&s)
{
    screens.push_back(s);
    return screens.size()-1;
}
Screen::pos Screen::size()const
{
    return height*width;
}
void Window_mgr::clear(ScreenIndex i)
{
    Screen&s=screens[i];
    s.contents=string(s.height*s.width,' ');
}
inline Screen& Screen::set(char c)
{
    contents[cursor]=c;
    return *this;
}
inline Screen&Screen::set(pos r,pos col,char ch)
{
    contents[r*width+col]=ch;
    return *this;
}
void Screen::some_member()const
{
    ++access_ctr;
}

inline
Screen &Screen::move(pos r,pos c)
{
    pos row=r*width;
    cursor=row+c;
    return *this;
}
char Screen::get(pos r,pos c)const
{
    pos row =r*width;
    return contents[row+c];
}

Screen::Screen(std::istream&is)
{
    is>>height>>width;
    contents=height*width;
}

