#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>
int main()
{
    Plist fun;
    elem_type temp;
    InitLInkList(&fun);
    menu(&fun);

    // for (int i = 0; i < 5; i++)
    // {
    //     AddNode_head(&fun, i);
    //     AddNode_tail(&fun, i);
    //     // printf("sum=%d\n",fun->sum_node);
    // }
    // Traverse(&fun, SeekNode_this);
    // int num;
    // puts("查找第几个");
    // scanf("%d", &num);
    // if (SeekNode_num(&fun, num, &temp))
    //     printf("第%d个是%d\n", num, temp);
    // else
    //     puts("输入过大或者过小");
    // Traverse(&fun, SeekNode_this);
    // puts("查找什么数字");
    // scanf("%d", &temp);
    // if (SeekNode_key(&fun, temp))
    //     puts("FIND");
    // else
    //     puts("NOTFIND");
    //      Traverse(&fun, SeekNode_this);
    // DeleteNode_key(&fun, 2);
    // Traverse(&fun, SeekNode_this);

    // //
    // DeleteNode_num(&fun, 2, &temp);
    // printf("%d被删除\n", temp);
    // Traverse(&fun, SeekNode_this);

    return 0;
}