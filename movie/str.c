#include<stdio.h>
// #include<ctype.h>
#include<string.h>
// #include<stdlib.h>
#include"str.h"
char*s_gets(char*s,int n)
{   char*find;
    char*ret_val;
    ret_val=fgets(s,n,stdin);
    if(ret_val)
    {
        find=strchr(s,'\n');
        if(find)
        {
            *find='\0';
        }else{
            while(getchar()!='\n')
            continue;
        }
    }
    
    return ret_val;
}