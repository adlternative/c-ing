#include<iostream>
#include<string>
#include<vector>
#include"my_err.h"
using namespace std;
auto func(int i)->int(*)[10]
{

}
int odd[]={1,2,3,4,5};
decltype (odd)*arrPtr(int i)
{   
/*
     缺少*
    function returning array is not allowed
 */
    return  &odd;
}
// int test(int a=2);
int test(int a,int b=1);
// int test(int a){

// }
int test(int a,int b)
{
    printf("%d",a);
}
int  main()
{
    ERR_MSG_PRINT("出错了");
    
    error_msg(ErrCode(1),{"i","love","you"});
    test(1);   
}