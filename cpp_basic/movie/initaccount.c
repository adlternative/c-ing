#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "employee.h"
#include "str.h"
int main()
{
    Employee e;
    FILE *fp = fopen("account", "rb");
    if (1)
    {
        fclose(fp);
        fp = fopen("account", "wb");
        char name[NAMESIZE];
        char pwd[PASSWORDSIZE];
        puts("姓名:");
        s_gets(name, NAMESIZE);
        puts("密码");
        s_gets(pwd, PASSWORDSIZE);
        e.id=0;
        strcpy(e.name,name);
        strcpy(e.password,pwd);
        strcpy(e.position,"administrator");
        fwrite(&e, sizeof(Employee), 1, fp);
        fclose(fp);
    }
    else
    {
        puts("该系统已被初始化");
        exit(-1);
    }
}
