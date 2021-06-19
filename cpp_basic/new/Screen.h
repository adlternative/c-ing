//
// Created by adl on 2020/6/17.
//

#ifndef UNTITLED_SCREEN_H
#define UNTITLED_SCREEN_H


#include <string>

class Screen {
public:
//    typedef std::string::size_type pos;
    using pos = std::string::size_type;

    Screen() = default;

    Screen(pos height, pos width);

    Screen(pos height, pos width, char c);

    char get() const {
        return contents[cursor];
    }

    inline Screen&set(char);
    inline Screen&set(pos,pos,char);
    Screen&display(std::ostream&os){do_display(os);return *this;}
    const Screen&display(std::ostream&os)const{do_display(os);return *this;}
    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    void some_member() const;

private:
    void do_display(std::ostream&os)const{os<<contents;}
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::set(char c) {
    contents[cursor]=c;
    return *this;
}

inline Screen &Screen::set(Screen::pos r, Screen::pos col, char ch) {
    contents[r*width+col]=ch;
    return *this;
}


#endif //UNTITLED_SCREEN_H
