#include "menu.h"
#include "str.h"
#include "administrator.h"
#include "reception.h"
void workMenu(const Employee *e)
{
    printf("weclome %s :%s\n", e->position, e->name);
    if (!strcmp(e->position, "reception"))
    {
        while (true)
        {
            puts("1>查看所有电影");
            puts("2>售票服务  ");
            puts("3>退票服务");

            puts("8>退出登录");
            int choice;
            scanf("%d", &choice);
            while (getchar() != '\n')
                continue;
            FILE *fp2 = fopen("money", "rb");
            double moneyCount = 0;
            fread(&moneyCount, sizeof(double), 1, fp2);
            fclose(fp2);
            switch (choice)
            {
            case 1:
                showAllMovies();
                break;
            case 2:
                sellTicketes(&moneyCount);
                fp2 = fopen("money", "wb");
                printf("总盈利：%.2f\n", moneyCount);
                fwrite(&moneyCount, sizeof(double), 1, fp2);
                fclose(fp2);
                break;
            case 3:
                refondTicketes(&moneyCount);
                fp2 = fopen("money", "wb");
                printf("总盈利：%.2f\n", moneyCount);
                fwrite(&moneyCount, sizeof(double), 1, fp2);
                fclose(fp2);
                break;
                //         case 4:
                //             bookTickets();
                //             break;
                //         case 5:
                //             addVIP();
                //             break;
                //         case 6:
                //             reportVIPLossHandling();
                //             break;
                //         case 7:
                //             showVIPInfo();
                //             break;
            case 8:
                logout();
                return;
            default:
                puts("输出错误，重新输入");
                break;
            }
        }
    }
    else if (!strcmp(e->position, "administrator"))
    {
        int choice;
        while (true)
        {

            puts("1>添加电影");
            puts("2>删除电影");
            puts("3>修改电影信息");
            puts("4>查看所有电影信息");
            puts("5>查找电影信息");
            puts("6>添加新工作人员");
            puts("7>删除工作人员");
            puts("8>修改工作人员信息");
            puts("9>查看所有工作人员信息");
            puts("10>退出");

            scanf("%d", &choice);
            while (getchar() != '\n')
                continue;
            switch (choice)
            {
            case 1:
                addNewMovies();
                break;
            case 2:
                underCarriageMovies();
                break;
            case 3:
                changeMovies();
                break;
            case 4:
                showAllMovies();
                break; 
            case 5:
                seekMovies();
                break;
            case 6:
                addEmployee();
                break;
            case 7:
                deleteEmployee();
                break;
            case 8:
                changeEmployee();
                break;
            case 9:
                showAllEmployees();
                break;
            case 10:
                logout();
                return;
            default:
                puts("输出错误，重新输入");
                break;
            }
        }
    }
}
void login()
{
    Employee e, Earr[EMPLOYSZIE];
    char name[NAMESIZE];
    char pwd[PASSWORDSIZE];

    FILE *fp = fopen("account", "rb");
    int i = 0;
    while ((fread(&e, sizeof(Employee), 1, fp)) == 1)
    {
        Earr[i++] = e;
    }
    while (true)
    {
        puts("姓名: ");
        s_gets(name, NAMESIZE);
        puts("密码:");
        s_gets(pwd, PASSWORDSIZE);
        for (int j = 0; j < i; j++)
        {
            if ((!strcmp(name, Earr[j].name)) && (!strcmp(pwd, Earr[j].password)))
            {
                puts("登录成功");
                workMenu(Earr + j);
                fclose(fp);
                return;
            }
        }
        puts("输入有误！请重新输入");
    }
}
void menu(void)
{
    int choice;
    puts("welcome to menu!");
    while (true)
    {
        puts("1>登录    2>退出");
        scanf("%d", &choice);
        while (getchar() != '\n')
            continue;
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            return;
        default:
            puts("输入有误,请重新输入!");
            break;
        }
    }
}