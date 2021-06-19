#include "MovieLinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "str.h"

Status InitLInkList(Plist p)
{
    Pmovie m, n;
    if ((m = (Pmovie)malloc(sizeof(Movie))) && (n = (Pmovie)malloc(sizeof(Movie))))
    {
        m->next = n;
        m->pre = n;
        n->next = m;
        n->pre = m;
        p->movieNum = 0;
        p->head = m;
        p->tail = n;
        return OK;
    }
    else
        return FALSE;
}
Status AddNode(Plist p, ElemType e)
{
    Pmovie cur;
    if ((cur = (Pmovie)malloc(sizeof(Movie))) != NULL)
    {
        cur->MovieInfo = e;
        cur->pre = p->tail->pre;
        cur->next = p->tail;
        p->tail->pre->next = cur;
        p->tail->pre = cur;
        ;

        p->movieNum++;
        return OK;
    }
    else
        return FALSE;
}
// Status DelelteNodeNum(Plist p,int n)
// {
//     Pmovie Ptemp=p->head->next;
//     while (Ptemp!=p->tail&&n--)
//     {
//         Ptemp=Ptemp->next;
//     }
//     if(n==0)
//     {
//         Ptemp->next->pre=Ptemp->pre;
//         Ptemp->pre->next=Ptemp  ->next->pre;
//         free(Ptemp);
//     }
// }
Status DeleteNodeElem(Plist p, Pmovie pm)
{ 
    Pmovie temp = pm->next->pre;       
    pm->next->pre = pm->pre;
    pm->pre->next = pm->next;
    free(temp);
    return OK;
}

// Status DeleteNode(Plist p)
// {
//     int choice;
//     ElemType e;
//     puts("1>以项数删除\t2>以电影名字删除");
//     scanf("%d", &choice);
//     if (choice == 1)
//     {
//         int num;
//         printf("项数是");
//         scanf("%d", &num);
//         if (DeleteNodeNum(p, num, &e))
//         {
//             printf("%s已经从库中删去\n", e.movieName);
//             return OK;
//         }
//         else
//         {
//             puts("输入的数字过大或者过小");
//             return FALSE;
//         }
//     }
//     else if (choice == 2)
//     {
//         printf("你想要删除电影名字是");
//         scanf("%s", &e.movieName);
//         if (DeleteNodeKey(p, e))
//         {
//             printf("%s已经从库中删去\n", e.movieName);
//             return OK;
//         }
//         else
//         {
//             puts("库中找不到你想要的");
//             return FALSE;
//         }
//     }
// }
// Status SeekNode(Plist p)
// {
//     int choice;
//     ElemType e;

//     puts("1>以项数查找\t2>以电影名字查找");
//     scanf("%d", &choice);

//     if (choice == 1)
//     {
//         int num;
//         printf("查找第几项？");
//         scanf("%d", &num);
//         if (SeekNodeNum(p, num, &e))
//         {
//             printf("找到了%s\n", e.movieName);
//             return OK;
//         }
//         else
//         {
//             puts("输入过大或者过小");
//             return FALSE;
//         }
//     }
//     else if (choice == 2)
//     {
//         printf("你想要查找的是");
//         scanf("%s", e.movieName);
//         if (SeekNodeKey(p, e))
//         {
//             printf("找到了%d\n", e);
//             return OK;
//         }
//         else
//         {
//             puts("库中找不到你想要的");
//             return FALSE;
//         }
//     }
// }
// Status ChangeNode(Plist p)
// {
//     int choice;
//     ElemType eold, enew;

//     puts("1>以项数更改\t2>以关键字更改");
//     scanf("%d", &choice);
//     if (choice == 1)
//     {
//         int num;
//         printf("修改第几项？");
//         scanf("%d", &num);
//         ChangeNodeNum(p,num,&eold,&enew);
//         SeekNode_this(eold);
//         puts("修订改为--->");
//         SeekNode_this(enew);

//         // puts("你想修改电影名称吗（y/n）");
//         // char answer[2];
//         // s_gets(answer, 2);
//         // if (answer[0] == 'y')
//         //     scanf("%d", &new.movieName);
//         // puts("你想修改导演名称吗（y/n）");
//         // s_gets(answer, 2);
//         // if (answer[0] == 'y')
//         //     scanf("%d", &new.DirectorName);
//         // puts("你想修改上映时间吗（y/n）");
//         // s_gets(answer, 2);
//         // if (answer[0] == 'y')
//         // {
//         //     puts("年");
//         //     s_gets(new.Showtime.year, 4);
//         //     puts("月");
//         //     s_gets(new.Showtime.mouth, 2);
//         //     puts("日");
//         //     s_gets(new.Showtime.day, 2);
//         // }
//         // puts("你想修改票数吗（y/n）");
//         // s_gets(answer, 2);
//         // if (answer[0] == 'y')
//         // {
//         //     scanf("%d",&new.ticketNum);
//         // }
//     }
// }