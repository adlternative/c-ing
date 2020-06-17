//
// Created by adl on 2020/6/17.
//

#include "Screen.h"



Screen::Screen( Screen::pos ht, Screen::pos wd, char c):height(ht),width(wd),contents(ht*wd,c) {}


Screen &Screen::move(Screen::pos r, Screen::pos c) {
    pos row=r*width;
    cursor=row+c;
    return *this;
}

char Screen::get(Screen::pos r, Screen::pos c) const {
    pos row = r * width;
    return contents[row+c];
}

void Screen::some_member() const {
    ++access_ctr;
}


Screen::Screen(Screen::pos ht, Screen::pos wd)
:height(ht),width(wd),contents(ht*wd,' '){}
