#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int >s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
while(!s.empty()){
    cout<<"栈顶"<<s.top()<<endl;
    s.pop();
}
cout<<"栈的大小"<<s.size()<<endl;
}