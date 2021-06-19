#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int s;
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
        

    // for (auto &&i : v)
    // {
    //     cout<<i<<endl;
    // }
    
    auto beg=v.begin();
    auto end=v.end();
    auto mid=v.begin()+(end-beg)/2;
    int sought=3;
    while(mid!=end&&*mid!=sought){
        if(sought<*mid)
            end=mid;
        else
            beg=mid+1;
        mid=beg+(end-beg)/2;
    }
    if(mid!=end)
        cout<<*mid<<endl;
    else
        cout<<"NULL"<<endl;

    // string      s;
    // cout<<s[0]<<endl;
    // const string s="Keep out";
    vector<string>a(10,"sad");
    
    vector<vector<string>>file;
    vector<vector<string>>file2;
    file.push_back(a);
    file.pop_back();
    file.empty();
    file.size();
    file[0];
    file2=file;
    file==file2;
    file!=file2;
    file<file2;

    for (auto &&i : file)
    {
        for (auto &&ii : i)
        {
            cout<<ii<<endl;
        }
        
    }
    
    // string  s("sad");
    // for (auto& c : s)
    // {
    //     c='X';
    // }
    // cout<<s<<endl;
}