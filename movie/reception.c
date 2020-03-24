
#include <stdio.h>
#include "str.h"
#include <string.h>
#include "reception.h"

void sellTicketes(double *count)
{
    MovieLinkList ml;
    Movie temp;
    FILE *fp = fopen("movie", "rb");
    InitLInkList(&ml);
    while (fread(&temp, sizeof(Movie), 1, fp))
    {
        AddNode(&ml, temp.MovieInfo);
    }
    fclose(fp);
    char Moviename[MOVIENAMESIZE];
    puts("需要看什么电影 ？");
    s_gets(Moviename, MOVIENAMESIZE);
    Movie *ftemp;
    for (ftemp = ml.head->next; ftemp != ml.tail; ftemp = ftemp->next)
    {
        if (!strcmp(ftemp->MovieInfo.movieName, Moviename))
        {
            if (ftemp->MovieInfo.ticketNum > 0)
            {
                puts("需要几张票?");
                int num = 0;
                scanf("%d", &num);
                while (getchar() != '\n')
                    continue;
                if (ftemp->MovieInfo.ticketNum >= num)
                    ftemp->MovieInfo.ticketNum -= num;
                else
                {
                    char ans[2];
                    printf("票只剩下%d张了，你还买这%d张吗？\n", ftemp->MovieInfo.ticketNum, ftemp->MovieInfo.ticketNum);
                    s_gets(ans, 2);
                    if (ans[0] == 'y')
                    {
                        num = ftemp->MovieInfo.ticketNum;
                        ftemp->MovieInfo.ticketNum -= ftemp->MovieInfo.ticketNum;
                    }
                    else
                        return;
                }
                printf("卖了%d张%s的票,盈利%.2f元\n", num, Moviename, ftemp->MovieInfo.ticketprice * num);
                *count = *count + ftemp->MovieInfo.ticketprice * num;
            }
            else
                puts("票卖光啦！");
            break;
        }
    }
    if (ftemp == ml.tail)
        puts("电影不存在");
    fp = fopen("movie", "wb");
    for (ftemp = ml.head->next; ftemp != ml.tail; ftemp = ftemp->next)
    {
        fwrite(ftemp, sizeof(Movie), 1, fp);
    }
    fclose(fp);
}
void refondTicketes(double *count)
{
    MovieLinkList ml;
    Movie temp;
    FILE *fp = fopen("movie", "rb");
    InitLInkList(&ml);
    while (fread(&temp, sizeof(Movie), 1, fp))
    {
        AddNode(&ml, temp.MovieInfo);
    }
    fclose(fp);
    char Moviename[MOVIENAMESIZE];
    puts("需要退什么电影的票 ？");
    s_gets(Moviename, MOVIENAMESIZE);
    Movie *ftemp;
    for (ftemp = ml.head->next; ftemp != ml.tail; ftemp = ftemp->next)
    {
        if (!strcmp(ftemp->MovieInfo.movieName, Moviename))
        {
            if (ftemp->MovieInfo.ticketNum >= 0)
            {
                puts("需要退几张票?");
                int num = 0;
                scanf("%d", &num);
                while (getchar() != '\n')
                    continue;
                ftemp->MovieInfo.ticketNum+=num;
                printf("退回了%d张%s的票,盈利%.2f元\n", num, Moviename, -ftemp->MovieInfo.ticketprice * num);
                *count = *count + ftemp->MovieInfo.ticketprice * num;
            }
            break;
        }
    }
    if (ftemp == ml.tail)
        puts("电影不存在");
    fp = fopen("movie", "wb");
    for (ftemp = ml.head->next; ftemp != ml.tail; ftemp = ftemp->next)
    {
        fwrite(ftemp, sizeof(Movie), 1, fp);
    }
    fclose(fp);
}