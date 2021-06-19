#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
class Person
{
public:
    Person(string name,int age,int height)
    {
        this->m_Age=age;
        this->m_Height=height;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
    int m_Height;
};
void printList(const list<int>&L)
{
    for (list<int>::const_iterator it = L.begin(); it !=L.end() ; it++)
    {
        cout<<*it<<" ";        
    }
    cout<<endl;
}
bool myCompare(int v1,int v2)
{
    return v1>v2;
}
bool myCompare2(Person &p1,Person &p2)
{
    return p1.m_Age!=p2.m_Age?p1.m_Age>p2.m_Age:p1.m_Height>p2.m_Height;
}
int main()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    list<int>L2(L1.begin(),L1.end());
    printList(L2);
    list<int>L3(L2);
    list<int>L4(10,100);
    printList(L4);
    list<int>L5;
    L5=L1;
    list<int>L6;    
    L6.assign(L2.begin(),L2.end());
    list<int>L7; 
    L7.assign(10,100);   
    L1.swap(L4);
    printList(L1);
    printList(L4);
    L4.pop_back();
    L4.pop_front();
    L4.insert(++L4.begin(),1000);
    L4.insert(++L4.begin(),1000);
    printList(L4);
    L4.remove(1000);
    printList(L4);
    L4.reverse();
    printList(L4);
    L4.sort(myCompare);    
    printList(L4);
    list<Person>L;
    Person p1("sda",1,1);
    Person p3("sdsaa",2,3);
    Person p2("sda",5,4);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    for (list<Person>::const_iterator it = L.begin(); it !=L.end() ; it++)
    {
        cout<<it->m_Name<<" "<<it->m_Age<<" "<<it->m_Height<<" "<<endl;        
    }
    cout<<endl;
    L.sort(myCompare2);
    for (list<Person>::const_iterator it = L.begin(); it !=L.end() ; it++)
    {
        cout<<it->m_Name<<" "<<it->m_Age<<" "<<it->m_Height<<" "<<endl;        
    }
}