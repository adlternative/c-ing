#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>
Status InitLInkList(Plist *p)
{
    Pnode m, n;
    if (((m = (Pnode)malloc(sizeof(Lnode))) != NULL) && (n = (Pnode)malloc(sizeof(Lnode))) != NULL)
    {
        m->next = n;
        m->pre = n;
        n->next = m;
        n->pre = m;
        (*p)->sum_node = 0;
        (*p)->head = m;
        (*p)->tail = n;
        return OK;
    }
    else
        return FALSE;
}
Status AddNode_head(Plist *p, elem_type e)
{
    Pnode cur;
    if ((cur = (Pnode)malloc(sizeof(Lnode))) != NULL)
    {

        cur->data = e;
        cur->next = (*p)->head->next;
        cur->pre = (*p)->head;
        cur->next->pre = cur;
        (*p)->head->next = cur;
        (*p)->sum_node++;
        return OK;
    }
    else
        return FALSE;
}
Status AddNode_tail(Plist *p, elem_type e)
{
    Pnode cur;
    if ((cur = (Pnode)malloc(sizeof(Lnode))) != NULL)
    {
        cur->data = e;
        cur->next = (*p)->tail;
        cur->pre = (*p)->tail->pre;
        cur->pre->next = cur;
        (*p)->tail->pre = cur;
        (*p)->sum_node++;
        return OK;
    }
    else
        return FALSE;
}
Status DeleteNode_num(Plist *p, int n, elem_type *e)
{
    Pnode m = (*p)->head;
    if (n > (*p)->sum_node || n <= 0)
        return FALSE;
    else
    {
        while (n)
        {
            m = m->next;
            n--;
        }
        *e = m->data;
        m->pre->next = m->next;
        m->next->pre = m->pre;
        free(m);
        (*p)->sum_node--;
    }
    return OK;
}
Status DeleteNode_key(Plist *p, elem_type e)
{
    Pnode temp, m = (*p)->head->next;
    if (m == (*p)->tail)
        return FALSE;
    if (!SeekNode_key(p, e))
        return FALSE;
    while (m != (*p)->tail)
    {
        temp = m->next;
        if (m->data == e)
        {
            m->pre->next = m->next;
            m->next->pre = m->pre;
            free(m);
            (*p)->sum_node--;
        }
        m = temp;
    }

    return OK;
}
Status ChangeNode_num(Plist *p, int n, elem_type *e, elem_type new)
{
    Pnode m = (*p)->head;
    if (n > (*p)->sum_node || n <= 0)
        return FALSE;
    else
    {
        while (n)
        {
            m = m->next;
            n--;
        }
        *e = m->data;
        m->data = new;
    }
    return OK;
}
Status ChangeNode_key(Plist *p, elem_type *e, elem_type new)
{
    Pnode m = (*p)->head->next;
    // elem_type temp;
    // if (!SeekNode_key(p, new))
    //     {printf("aaa");
    //         return FALSE;}
    while (m != (*p)->tail)
    {
        if (m->data == *e)
        {
            m->data = new;
        }
        m = m->next;
    }
    return OK;
}
Status SeekNode_num(Plist *p, int n, elem_type *e)
{
    Pnode m = (*p)->head;
    if (n > (*p)->sum_node || n <= 0)
        return FALSE;
    else
    {
        while (n)
        {
            m = m->next;
            n--;
        }
        *e = m->data;
    }
    return OK;
}
Status SeekNode_key(Plist *p, elem_type e)
{
    Pnode m = (*p)->head;
    while (m != (*p)->tail && m->data != e)
    {
        m = m->next;
    }
    if (m == (*p)->tail)
        return FALSE;
    else
        return OK;
}
void SeekNode_this(Lnode *this)
{
    printf("%d\n", this->data);
}
Status Traverse_Seek(Plist *p, void (*fun)(Lnode *this))
{
    Lnode *temp = (*p)->head->next;
    printf("~~~~~\n");
    while (temp != (*p)->tail)
    {
        fun(temp);
        temp = temp->next;
    }
    printf("~~~~~\n");
    return OK;
}
Status Traverse_Reverse_Seek(Plist *p, void (*fun)(Lnode *this))
{
    Lnode *temp = (*p)->tail->pre;
    printf("~~~~~\n");
    while (temp != (*p)->head)
    {
        fun(temp);
        temp = temp->pre;
    }
    printf("~~~~~\n");
    return OK;
}

Status AddNode(Plist *p)
{
    int choice;
    elem_type e;
    puts("1>头插2>尾插");
    scanf("%d", &choice);
    printf("你想要插入的是");
    scanf("%d", &e);
    if (choice == 1)
    {
        if (AddNode_head(p, e))
        {
            puts("插入成功");
            return OK;
        }
        else
        {
            puts("内存分配失败");
            return FALSE;
        }
    }
    else if (choice == 2)
    {
        if (AddNode_tail(p, e))
        {
            puts("插入成功");
            return OK;
        }
        else
        {
            puts("内存分配失败");
            return FALSE;
        }
    }
    else
    {
        puts("你的输入有误");
        return FALSE;
    }
}
Status DeleteNode(Plist *p)
{
    int choice;
    elem_type e;

    puts("1>以项数删除\t2>以关键字删除");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int num;
        printf("项数是");
        scanf("%d", &num);
        if (DeleteNode_num(p, num, &e))
        {
            printf("%d已经从库中删去\n", e);
            return OK;
        }
        else
        {
            puts("输入过大或者过小");
            return FALSE;
        }
    }
    else if (choice == 2)
    {

        printf("你想要删除的是");
        scanf("%d", &e);
        if (DeleteNode_key(p, e))
        {
            printf("%d已经从库中删去\n", e);
            return OK;
        }
        else
        {
            puts("库中找不到你想要的");
            return FALSE;
        }
    }
    else
    {
        puts("你的输入有误");
        return FALSE;
    }
}
Status SeekNode(Plist *p)
{

    int choice;
    elem_type e;

    puts("1>以项数查找\t2>以关键字查找");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int num;
        printf("查找第几项？");
        scanf("%d", &num);
        if (SeekNode_num(p, num, &e))
        {
            printf("找到了%d\n", e);
            return OK;
        }
        else
        {
            puts("输入过大或者过小");
            return FALSE;
        }
    }
    else if (choice == 2)
    {
        printf("你想要查找的是");
        scanf("%d", &e);
        if (SeekNode_key(p, e))
        {
            printf("找到了%d\n", e);
            return OK;
        }
        else
        {
            puts("库中找不到你想要的");
            return FALSE;
        }
    }
    else
    {
        puts("你的输入有误");
        return FALSE;
    }
}
Status ChangeNode(Plist *p)
{

    int choice;
    elem_type e, new;

    puts("1>以项数更改\t2>以关键字更改");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int num;
        printf("修改第几项？");
        scanf("%d", &num);
        printf("修改为");
        scanf("%d", &new);
        if (ChangeNode_num(p, num, &e, new))
        {
            printf("第%d个数据%d已经被修改为%d\n", num, e, new);
            return OK;
        }
        else
        {
            puts("输入过大或者过小");
            return FALSE;
        }
    }
    else if (choice == 2)
    {
        printf("你想要更改的是");
        scanf("%d", &e);
        printf("修改为");
        scanf("%d", &new);
        if (ChangeNode_key(p, &e, new))
        {
            printf("%d已经被修改为%d\n", e, new);
            return OK;
        }
        else
        {
            puts("库中找不到你想要的");
            return FALSE;
        }
    }
    else
    {
        puts("你的输入有误");
        return FALSE;
    }
}
Status Traverse(Plist *p)
{
    int choice = 1;
    if (choice == 1)
        Traverse_Seek(p, SeekNode_this);
    return OK;
}
Status Traverse_Reverse(Plist *p)
{
    int choice = 1;
    if (choice == 1)
        Traverse_Reverse_Seek(p, SeekNode_this);
    return OK;
}
void menu(Plist *p)
{
    fun choice_fun;
    fun_array menu = {AddNode, DeleteNode, ChangeNode, SeekNode, Traverse, Traverse_Reverse};
    int choice;
    while (1)
    {
        puts("1>增");
        puts("2>删");
        puts("3>改");
        puts("4>查");
        puts("5>正序显示全部");
        puts("6>逆序显示全部");
        puts("7>ESC");
        printf("你的选择\n");
        scanf("%d", &choice);
        if (choice > 7 || choice <= 0)
        {
            printf("输入过大或者过小\n请重新输入\n");
            continue;
        }
        else if (choice != 7)
        {
            choice_fun = menu[choice - 1];
            choice_fun(p);
            if (choice != 6 && choice != 5)
                Traverse(p);
        }
        else
            break;
    }
    puts("bye");
}
