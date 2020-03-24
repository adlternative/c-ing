#include<iostream>
#include<string>
using namespace std;
int main()
{
    // string str,temp;
    // while(cin>>str){
    //     if(temp<str){
    //         cout<<temp<<"<"<<str<<endl;
    //     }
    //     // cout<<str<<endl;
    //     temp=str;
    // }
    // while(getline(cin,str)){
    //     cout<<str<<endl;
    // }
    // string str1,str2,strout;
    // cin>>str1>>str2;
    // strout=str1>str2?str1:str2;
    // if(str1.size()==str2.size()){
    //     cout<<"dengchang"<<endl;
    //     return 0;
    // }
    // strout=str1.size()>str2.size()?str1:str2;
    // cout<<strout<<endl;
    // string str,temp;
    // int flag=0;
    // while(cin>>str){
    //     if(flag==0){
    //         flag=1;
    //         temp+=str;
    //     }else{
    //         temp+=" "+str;
    //     }
    // }
    // decltype(temp.size())punct_cnt=0;

    // for(auto c:temp){
    //     if(ispunct(c))
    //         ++punct_cnt;
    //     cout<<c<<endl;
    // }
    // cout<<punct_cnt<<endl;
    // cout<<temp<<endl;
    string s("hello world");
    // for(auto &c:s){
    //     c=toupper(c);
    // }
    s[0]='q';
    cout<<s<<endl;
    for (decltype(s.size()) i = 0; i !=s.size()&&!isspace(s[i]); i++)
    {
        s[i]=toupper(s[i]);
    }
    cout<<s<<endl;
    const string sd="SD";
    for (auto &c : sd)
    {
        
    }
    const char*str=s.c_str();
    printf("%s",str);   
}