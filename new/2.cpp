#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int j=0;
    double  slope=static_cast<double>(j)/3;
    const char*pc;
    auto p=const_cast<char*>(pc);//正确,但是通过p写  错
    // char*p=(char*)pc;
    int a,b,s;
    while (cin>>a>>b)
    {
        try
        {
            if(b==0)
                throw string("/0  err");
            else{
                cout<<a/b <<endl;
                return  0;
            }
        }
        catch(string s)
        {
            std::cerr <<s << '\n';
            char c;
            cout<<"你要重来吗(y/n)？？"<<endl;
            if(cin>>c&&c=='y'){
                continue;
            }else{
                return -1;
            }
        }
    }
}