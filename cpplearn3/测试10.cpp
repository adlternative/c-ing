#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include<cassert>
#include <vector>
// #include"../cpplearn2/Sales_data.h"
// #include"../cpplearn2/Sales_item.h"
#include<list>
#include<deque>
#include<array>
#include<forward_list>
#include<unistd.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<unordered_set>
#include<unordered_map>
#include<memory>
#include"./测试5.cpp"
using namespace std;
using namespace std::placeholders;
class Folder;
class Message
{
friend void swap(Message &lhs,Message&rhs);
friend class Folder;
private:
    string contents;
    set<Folder*>folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
public:
    explicit Message(const string &str=""):contents(str){}
    Message(const Message&);
    Message&operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder*f);
    void remFolder(Folder*f);
    void getContents(){cout<<contents<<endl;}
};




class Folder
{
friend class Message; 
public:
    Folder(){}
    Folder(const Folder&);
    Folder&operator=(const Folder);
    ~Folder();
    void remMsg(Message*);
    void addMsg(Message*);
    void print(){
        for_each(Mes.begin(),Mes.end(),[](auto m){
            m->getContents();
        });
    }
private:
    set<Message*>Mes;
    void addAllMsg()
    {
        for(auto&m:Mes){
            m->save(*this);
        }
    }
    void removeAllMsg()
    {
        for(auto&m:Mes){
            m->remove(*this);
        }
    }
};
void Message::save(Folder&f)
{
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder&f)
{
    folders.erase(&f);
    f.remMsg(this);
}
void Message::add_to_Folders(const Message&m)
{
    for(auto f:m.folders)
        f->addMsg(this);
}
Message::Message(const Message&m):contents(m.contents),folders(m.folders)
{
    add_to_Folders(m);
}
void Message::remove_from_Folders()
{
    for(auto f:folders)
        f->remMsg(this);
}


Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message&rhs)
{
    remove_from_Folders();
    contents=rhs.contents;
    folders=rhs.folders;
    add_to_Folders(rhs);
    return *this;
}
void Folder::addMsg(Message*m)
{
    if(Mes.find(m)==Mes.end())
        Mes.insert(m);
    if(m->folders.find(this)==m->folders.end())
        m->save(*this);
}
void Folder::remMsg(Message*m)
{
    if(Mes.find(m)!=Mes.end())
        Mes.erase(m);
    if(m->folders.find(this)!=m->folders.end())
        m->remove(*this);
}
Folder::Folder(const Folder &f)
{
    Mes=f.Mes;
    addAllMsg();   
}
Folder&Folder::operator=(const Folder f)
{
    removeAllMsg();
    Mes=f.Mes;
    addAllMsg();
    return *this;
}
Folder::~Folder()
{
    removeAllMsg();
}
void Message::remFolder(Folder*f)
{
    if(folders.find(f)!=folders.end())
        folders.erase(f);
    if(f->Mes.find(this)!=f->Mes.end())
        f->remMsg(this);
}

void Message::addFolder(Folder*f)
{
    if(folders.find(f)==folders.end())
        folders.insert(f);
    if(f->Mes.find(this)==f->Mes.end())
        f->addMsg(this);
}

void swap(Message &lhs,Message&rhs)
{
    using std::swap;
    for(auto f:lhs.folders)
        f->remMsg(&lhs);
    for(auto f:rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);
    for(auto f:rhs.folders)
        f->addMsg(&rhs);
    for(auto f:lhs.folders)
        f->remMsg(&lhs);   
}
int main()
{
    Folder f,f2;
    Message m("sad");
    Message m2("not sad");
    auto m3(m);
    f.addMsg(&m);
    f.addMsg(&m2);
    m.addFolder(&f2);
    m2.addFolder(&f2);
    f.print();
}