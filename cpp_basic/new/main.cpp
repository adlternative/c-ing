#include <iostream>
#include<iostream>
#include<string>
#include<vector>
#include"Screen.h"
using namespace std;

int main() {
    
    Screen myScreen(5,3);
    const Screen    blank(5,3);
    myScreen.set('q').display(cout);
    blank.display(cout);
//    char ch=myScreen.get();
//    ch=myScreen.get(0,0);
//    myScreen.move(4,0).set('#');

//    vector<Person>v;
//
//    creatPerson(v);
//    setScore(v);
//    showScore(v);
    return 0;
}