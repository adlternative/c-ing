#include<iostream>
#include<queue>
using namespace std;
class Person
{
public:
    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
};
int main()
{
    queue<Person >p;
    Person p1("唐僧",30);
    Person p2("1",3);
    Person p3("2",10);
    Person p4("3",320);
    p.push(p1);
    p.push(p2);
    p.push(p3);
    p.push(p4);
    cout<<"队列的大小"<<p.size()<<endl;
    while(!p.empty()){
        cout<<"name"<<p.front().m_Name<<"age"<<p.front().m_Age<<endl;
        cout<<"name"<<p.back().m_Name<<"age"<<p.back().m_Age<<endl;
        p.pop();
    }
cout<<"队列的大小"<<p.size()<<endl;
}