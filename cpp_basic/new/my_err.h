#pragma once
#include<iostream>
#include<initializer_list>
#include<string>
#define ERR_MSG_PRINT(msg)\
    std::cerr<<"Err:"<<(msg)<<endl<<"in function: "<<__func__<<endl<<\
    "at line:"<<__LINE__<<endl<<"at time:"<<__DATE__<<"  "<<__TIME__<<endl;\

using  ErrCode= int; 
void error_msg(ErrCode e,std::initializer_list<std::string>i1);
