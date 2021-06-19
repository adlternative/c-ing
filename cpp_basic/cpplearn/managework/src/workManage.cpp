#include "../head/workManage.h"
void WorkerManager::ExitSystem()
{
    cout<<"bye"<<endl;
    //system("pause");
    exit(0);
}

WorkerManager::WorkerManager()
{
}
WorkerManager::~WorkerManager()
{
}
void WorkerManager::Show_Menu()
{
    cout << "0 exit" << endl;
    cout << "1 add" << endl;
    cout << "2 show" << endl;
    cout << "3 delete" << endl;
    cout << "4 change" << endl;
    cout << "5 search" << endl;
    cout << "6 sort" << endl;
    cout << "7 clear" << endl;
    cout << endl;
}