#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
    Person()=default;
    Person(const string n,const string adr):name(n),address(adr){}
    explicit Person(const string n):name(n){}
    explicit Person(const string adr):address(adr){}
    Person(istream&is){setval(*this,is)}
    string getName()const{return name;}
    string getAddress()const{return address;}
    void  setName(){cin>>name;}
    void  setAddress(){cin>>address;}
    void setval(Person&,istream&);
private:
    string name;
    string address;
}; 
void Person::setval(Person&p,istream&is)
{
    is>>p.name>>p.address;
}
