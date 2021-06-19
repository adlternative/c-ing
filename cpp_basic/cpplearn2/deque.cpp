#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
void printDeque(const deque<int>&d)
{
    for (deque<int>::const_iterator it =d.begin(); it !=d.end(); it++){
        cout<<*it<<" ";
    }
    cout << endl;
}
int main()
{
    std::deque<int>d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int >d2(d1.begin(),d1.end());
    printDeque(d2);
    deque<int >d3(d1);
    printDeque(d3);
    deque<int >d4(10,100);
    printDeque(d4);
    deque<int >d5=d1;
    deque<int >d6;
    d6.assign(d1.begin(),d1.end());
    deque<int >d7;
    d7.assign(10,100);
    printDeque(d5);    
    printDeque(d6);    
    printDeque(d7);    
    if(!d7.empty()){
        cout<<"非空";
        cout<<d7.size();
    }
    d7.resize(12);
    printDeque(d7);
    d7.resize(15,1);
    printDeque(d7);
    d7.resize(5);
    printDeque(d7);
    d7.push_front(-1);
    printDeque(d7);
    d7.insert(d7.begin(),2,1000);
    printDeque(d7);
    d7.insert(d7.begin(),d1.begin(),d1.end());
    printDeque(d7);
    deque<int>::iterator it=d7.begin();
    it++;
    d7.erase(it);
    printDeque(d7);
    // cout<<d7[1]<<endl;
    sort(d7.begin(),d7.end());
    
    for (int i = 0; i < d7.size(); i++){
        cout<<d7[i]<<endl;
    }
    cout<<endl;
    
    d7.erase(d7.begin(),d7.end());
    d7.clear();
    printDeque(d7);
}