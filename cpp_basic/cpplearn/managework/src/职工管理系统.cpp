#include<iostream>
#include"../head/workManage.h"
using namespace std;
int main()
{
    WorkerManager wm;
    int choice=0;
    while(true)
    {

    wm.Show_Menu(); 
    cout<<"choice："<<endl;
    cin>>choice;
    switch (choice)
    {
    case 0:
        wm.ExitSystem();
        break;
    case 1:
    
        break;
    case 2:
    
        break;
    case 3:
    
        break;
    case 4:
    
        break;
    case 5:
    
        break;
    case 6:
    
        break;
    case 7:
        
            break;    
        default:
        system("clear");
        break;
    }
    }
}