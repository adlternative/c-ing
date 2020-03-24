#include<iostream>
#include<cstdlib>
#include"Sales_item.h"
using namespace std;
string str;
int reused=42;
int main()
{   
    
    Sales_item count("f");
    Sales_item book,item1,val1,val2,item2,curItem;
    std::string books("0-201-78345-X");
    auto item =val1+val2;
    while (cin>>item1>>item2)
    {
        try
        {
            if(item1.isbn()!=item2.isbn())
                throw runtime_error("data must refer to same isbn");
            cout<<item1+item2<<endl;
        }
        catch(runtime_error err)
        {
            cout<<err.what()<<"\n try again? enter y or n"<<endl;
            
            // std::cerr << err.what() << '\n';
            char c;
            cin>>c;
            if(!cin||c=='n')
                break;
        }
        
    }
    
    // std::cin>>book;
    // std::cout<<book<<std::endl;
    
    // while(std::cin>>item1)
    //     if(compareIsbn(item1,count))
    //         count+=item1;
    //     else{
    //         cerr<<"data must refer to same isbn"<<endl;
    //         return -1;
    //     }
    // cout<<count;   
    // return 0;
    // if(cin>>curItem){
    //     int cnt=curItem.getUnits_sold();
    //     while(cin>>item)
    //         if(compareIsbn(item,curItem))
    //             cnt+=item.getUnits_sold();
    //         else{
    //             cout<<curItem.isbn()<<" "<<cnt<<endl;
    //             curItem=item;
    //             cnt=item.getUnits_sold();
    //         }
    //     cout<<curItem.isbn()<<" "<<endl;
    // }
    // if(cin>>curItem){
    //     while(cin>>item){
    //         if(compareIsbn(item,curItem)){
    //             curItem+=item;
    //         }else{
    //             cout<<curItem<<endl;
    //             curItem=item;
    //         }
    //     }
    //     cout<<curItem<<endl;
    // }else{
    //     cerr<<"no data!"<<endl;
    //     return -1;
    // }
    return 0;
}
