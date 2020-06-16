#include"my_err.h"
using   namespace   std;

void error_msg(ErrCode e,initializer_list<string>i1)
{

    for (auto beg = i1.begin(); beg!=i1.end() ; beg++)    {
        cout<<*beg<<" ";
    }
    cout<<endl;    
}