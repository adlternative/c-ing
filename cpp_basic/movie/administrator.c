#include "administrator.h"
#include <stdio.h>
#include <stdlib.h>
// #include "MovieLinkList.h"
#include <string.h>
#include <errno.h>
// #include "employee.h"
#include "str.h"
void showMovie(const Movie *ptemp)
{
    
    printf("电影名：%s\n", ptemp->MovieInfo.movieName);
    printf("导演名：%s\n", ptemp->MovieInfo.DirectorName);
    printf("票数：%d\n", ptemp->MovieInfo.ticketNum);
    printf("价格： %.2lf\n", ptemp->MovieInfo.ticketprice);
    int i = 0;
    printf("演员:");
    while (strcmp(ptemp->MovieInfo.Actors[i], ""))
    {
        // printf("%s\n", strerror(errno));
        printf("%s  ", ptemp->MovieInfo.Actors[i++]);
    }
    printf("\n");
    printf("上映时间：%s:%s:%s\n", ptemp->MovieInfo.Showtime.year, ptemp->MovieInfo.Showtime.mouth, ptemp->MovieInfo.Showtime.day);
    // printf("\n");
}
void showAllMovies()
{
    Movie temp;
    FILE *fp = fopen("movie", "rb");

    int count = 0;
    while (fread(&temp, sizeof(Movie), 1, fp))
    {
        showMovie(&temp);
        printf("第%d项\n", count);
        printf("\n");
        count++;
    }
}

Status addNewMovies()
{
    MovieLinkList ml;
    Movie temp;
    FILE *fp = fopen("movie", "rb");
    InitLInkList(&ml);
    while (fread(&temp, sizeof(Movie), 1, fp))
    {
        AddNode(&ml, temp.MovieInfo);
    }
    puts("电影名");
    s_gets(temp.MovieInfo.movieName, MOVIENAMESIZE);
    puts("导演名");
    s_gets(temp.MovieInfo.DirectorName, NAMESIZE);
    puts("演员名，#结束");
    int i;
    for (i = 0; i < ACTORNUM - 1; i++)
    {
        s_gets(temp.MovieInfo.Actors[i], NAMESIZE);
        if (temp.MovieInfo.Actors[i][0] == '#')
        {
            i++;
            break;
        }
    }
    temp.MovieInfo.Actors[i - 1][0] = '\0';
    puts("时间：年");
    s_gets(temp.MovieInfo.Showtime.year, 5);
    puts("时间：月");
    s_gets(temp.MovieInfo.Showtime.mouth, 3);
    puts("时间：日");
    s_gets(temp.MovieInfo.Showtime.day, 3);
    puts("票数");
    scanf("%d", &temp.MovieInfo.ticketNum);
    puts("价格");
    scanf("%lf", &temp.MovieInfo.ticketprice);
    AddNode(&ml, temp.MovieInfo);
    fclose(fp);
    fp = fopen("movie", "wb");
    Movie *ftemp;
    for (ftemp = ml.head->next; ftemp != ml.tail; ftemp = ftemp->next)
    {
        fwrite(ftemp, sizeof(Movie), 1, fp);
    }
    fclose(fp);

    return OK;
}

void underCarriageMovies()
{
    MovieLinkList ml;
    Movie temp, find, findarr[MOVIEMAXNUM];
    memset(findarr, 0, sizeof(findarr));
    FILE *fp = fopen("movie", "rb");
    InitLInkList(&ml);
    while (fread(&temp, sizeof(Movie), 1, fp))
        AddNode(&ml, temp.MovieInfo);
    int choice;
    puts("1>根据电影名查找删除");
    puts("2>根据导演查找删除");
    puts("3>根据演员查找删除");
    puts("4>根据上映时间查找删除");
    puts("5>根据项数查找删除");

    scanf("%d", &choice);
    while (getchar() != '\n')
        continue;
    int findnum;
    char ans[2];
    switch (choice)
    {
    case 1:
        if (SeekNodeMovieName(&ml, &find))
        {
            showMovie(&find);
            char ans[2];
            puts("你想删除它么?");
            s_gets(ans, 2);
            if (ans[0] == 'n')
                return;
            DeleteNodeElem(&ml, &find);
        }
        else
            puts("查找失败");
        break;
    case 2:
        if (SeekNodeDirectorName(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
                char ans[2];
                puts("你想删除它么?");
                s_gets(ans, 2);
                if (ans[0] == 'n')
                    continue;
                DeleteNodeElem(&ml, findarr + i);
            }
        else
            puts("查找失败");
        break;
    case 3:
        if (SeekNodeActorName(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
                char ans[2];
                puts("你想删除它么?");
                s_gets(ans, 2);
                if (ans[0] == 'n')
                    return;
                DeleteNodeElem(&ml, findarr + i);
            }
        else
            puts("查找失败");
        break;
    case 4:
        if (SeekNodeShowTime(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
                char ans[2];
                puts("你想删除它么?");
                s_gets(ans, 2);
                if (ans[0] == 'n')
                    return;

                DeleteNodeElem(&ml, findarr + i);
            }
        else
            puts("查找失败");

        break;
    case 5:
        if (SeekNodeNum(&ml, &find))
        {
            showMovie(&find);
            char ans[2];
            puts("你想删除它么?");
            s_gets(ans, 2);
            if (ans[0] == 'n')
                return;
            DeleteNodeElem(&ml, &find);
        }
        else
            puts("查找失败");
        break;
    default:
        printf("你的选择有误\n");
        break;
    }
    fclose(fp);
    fopen("movie", "wb");
    Movie *ftemp;
    for (ftemp = ml.head->next; ftemp != ml.tail; ftemp = ftemp->next)
    {
        fwrite(ftemp, sizeof(Movie), 1, fp);
    }
    fclose(fp);
}
void seekMovies()
{
    MovieLinkList ml;
    Movie temp, find, findarr[MOVIEMAXNUM];
    memset(findarr, 0, sizeof(findarr));
    FILE *fp = fopen("movie", "rb");
    InitLInkList(&ml);
    while (fread(&temp, sizeof(Movie), 1, fp))
        AddNode(&ml, temp.MovieInfo);
    int choice;
    puts("1>根据电影名查找");
    puts("2>根据导演查找");
    puts("3>根据演员查找");
    puts("4>根据上映时间查找");
    puts("5>根据项数查找");

    scanf("%d", &choice);
    while (getchar() != '\n')
        continue;
    int findnum;
    switch (choice)
    {
    case 1:
        if (SeekNodeMovieName(&ml, &find))
            showMovie(&find);
        else
            puts("查找失败");
        break;
    case 2:
        if (SeekNodeDirectorName(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
            }
        else
            puts("查找失败");
        break;
    case 3:
        if (SeekNodeActorName(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
            }
        else
            puts("查找失败");
        break;
    case 4:
        if (SeekNodeShowTime(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
            }
        else
            puts("查找失败");

        break;
    case 5:
        if (SeekNodeNum(&ml, &find))
            showMovie(&find);
        else
            puts("查找失败");
        break;
    default:
        printf("你的选择有误\n");
        break;
    }
    fclose(fp);
}
Status SeekNodeDirectorName(const Plist pml, Movie findarr[], int *findnum)
{
    Movie *ftemp;
    Status findflag = FALSE;
    char tname[NAMESIZE];
    puts("你想要查找的导演名是:");
    s_gets(tname, NAMESIZE);
    int i = 0;
    for (ftemp = pml->head->next; ftemp != pml->tail; ftemp = ftemp->next)
    {
        if (!strcmp(ftemp->MovieInfo.DirectorName, tname))
        {
            findarr[i++] = *ftemp;
            findflag = OK;
        }
    }
    *findnum = i;
    return findflag;
}
Status SeekNodeMovieName(const Plist pml, Pmovie find)
{
    Movie *ftemp;
    char tname[MOVIENAMESIZE];
    puts("你想要查找的电影名是:");
    s_gets(tname, MOVIENAMESIZE);
    int num = 0;
    for (ftemp = pml->head->next; ftemp != pml->tail; ftemp = ftemp->next)
    {
        if (!strcmp(ftemp->MovieInfo.movieName, tname))
        {
            // puts("find");
            // printf("%s",ftemp->MovieInfo.movieName);
            *find = *ftemp;
            return OK;
        }
    }
    return FALSE;
}
Status SeekNodeActorName(const Plist pml, Movie findarr[], int *findnum)
{
    Movie *ftemp;
    Status findflag = FALSE;
    char tname[NAMESIZE];
    puts("你想要查找的演员名是:");
    s_gets(tname, NAMESIZE);
    int i = 0;
    for (ftemp = pml->head->next; ftemp != pml->tail; ftemp = ftemp->next)
    {
        for (int j = 0; ftemp->MovieInfo.Actors[j][0] != '\0'; j++)
            if (!strcmp(ftemp->MovieInfo.Actors[j], tname))
            {
                findarr[i++] = *ftemp;
                findflag = OK;
            }
    }
    *findnum = i;
    return findflag;
}
Status SeekNodeShowTime(const Plist pml, Movie findarr[], int *findnum)
{
    Movie *ftemp;
    Status findflag = FALSE;
    Time t;
    puts("你想要查找的时间是:");
    puts("年：");
    s_gets(t.year, 5);
    puts("月：");
    s_gets(t.mouth, 3);
    puts("日：");
    s_gets(t.day, 3);

    int i = 0;
    for (ftemp = pml->head->next; ftemp != pml->tail; ftemp = ftemp->next)
    {
        if (!strcmp(t.year, ftemp->MovieInfo.Showtime.year) && !strcmp(t.mouth, ftemp->MovieInfo.Showtime.mouth) && !strcmp(t.day, ftemp->MovieInfo.Showtime.day))
        {
            findarr[i++] = *ftemp;
            findflag = OK;
        }
    }
    *findnum = i;
    return findflag;
}
Status SeekNodeNum(const Plist pml, Pmovie find)
{
    Movie *ftemp;
    puts("你想要查找的是第几项:");
    int n;
    scanf("%d", &n);
    while (getchar() != '\n')
        continue;
    int i = 0;
    for (ftemp = pml->head->next; ftemp != pml->tail && i < n; ftemp = ftemp->next, i++)
        ;

    if (ftemp == pml->tail)
        return FALSE;
    else
    {
        *find = *ftemp;
        return OK;
    }
}
void ChangeQueue(Plist pml, Pmovie pfind, FILE **ffp)
{
    char ans[2];
    puts("你想修改它么?");
    s_gets(ans, 2);
    if (ans[0] == 'n')
        return;
    puts("你想修改电影名吗?");
    s_gets(ans, 2);
    if (ans[0] == 'y')
    {
        char newName[NAMESIZE];
        s_gets(newName, NAMESIZE);
        strcpy(pfind->MovieInfo.movieName, newName);
    }
    puts("你想修改导演名吗?");
    s_gets(ans, 2);
    if (ans[0] == 'y')
    {
        char newName[NAMESIZE];
        s_gets(newName, NAMESIZE);
        strcpy(pfind->MovieInfo.DirectorName, newName);
    }
    puts("你想修改演员名吗?");
    s_gets(ans, 2);
    if (ans[0] == 'y')
    {
        puts("#结束");
        int i;
        for (i = 0; i < ACTORNUM - 1; i++)
        {
            s_gets(pfind->MovieInfo.Actors[i], NAMESIZE);
            if (pfind->MovieInfo.Actors[i][0] == '#')
            {
                i++;
                break;
            }
        }
        pfind->MovieInfo.Actors[i - 1][0] = '\0';
    }
    puts("你想修改上映时间吗?");
    s_gets(ans, 2);
    if (ans[0] == 'y')
    {
        char newYear[5];
        Time newTime;
        puts("年");
        s_gets(newTime.year, 5);
        puts("月");
        s_gets(newTime.mouth, 3);
        puts("日");
        s_gets(newTime.day, 3);
        pfind->MovieInfo.Showtime = newTime;
    }
    pfind->next->pre = pfind;
    pfind->pre->next = pfind;
    fclose(*ffp);
    *ffp = fopen("movie", "wb");
    Movie *ftemp;
    for (ftemp = pml->head->next; ftemp != pml->tail; ftemp = ftemp->next)
    {
        // puts("???");
        if (!fwrite(ftemp, sizeof(Movie), 1, *ffp))
            puts("?");
    }
    fclose(*ffp);
}
void changeMovies()
{
    MovieLinkList ml;
    Movie temp, find, findarr[MOVIEMAXNUM];
    memset(findarr, 0, sizeof(findarr));
    FILE *fp = fopen("movie", "rb");
    InitLInkList(&ml);
    while (fread(&temp, sizeof(Movie), 1, fp))
        AddNode(&ml, temp.MovieInfo);
    int choice;
    puts("1>根据电影名查找修改");
    puts("2>根据导演查找修改");
    puts("3>根据演员查找修改");
    puts("4>根据上映时间查找修改");
    puts("5>根据项数查找修改");

    scanf("%d", &choice);
    while (getchar() != '\n')
        continue;
    int findnum;
    char ans[2];
    switch (choice)
    {
    case 1:
        if (SeekNodeMovieName(&ml, &find))
        {
            showMovie(&find);
            ChangeQueue(&ml, &find, &fp);
        }
        else
            puts("查找失败");
        break;
    case 2:
        if (SeekNodeDirectorName(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
                ChangeQueue(&ml, findarr + i, &fp);
            }
        else
            puts("查找失败");
        break;
    case 3:
        if (SeekNodeActorName(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
                ChangeQueue(&ml, findarr + i, &fp);
            }
        else
            puts("查找失败");
        break;
    case 4:
        if (SeekNodeShowTime(&ml, findarr, &findnum))
            for (int i = 0; i < findnum; i++)
            {
                showMovie(findarr + i);
                ChangeQueue(&ml, findarr + i, &fp);
            }
        else
            puts("查找失败");

        break;
    case 5:
        if (SeekNodeNum(&ml, &find))
        {
            showMovie(&find);
            ChangeQueue(&ml, &find, &fp);
        }
        else
            puts("查找失败");
        break;
    default:
        printf("你的选择有误\n");
        break;
    }
    // fclose(fp);
}
void addEmployee()
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
    puts("名字");
    s_gets(e.name, NAMESIZE);
    puts("密码");
    s_gets(e.password, PASSWORDSIZE);
    int choice = 0;
    puts("0>管理者   1>前台");
    scanf("%d", &choice);
    while (getchar() != '\n')
        continue;
    if (choice == 0)
        strcpy(e.position, "administrator");
    else if (choice == 1)
        strcpy(e.position, "reception");
    else
        puts("你的选择有误");
    Earr[i] = e;
    Earr[i].id = Earr[i - 1].id + 1;
    fclose(fp);
    fp = fopen("account", "wb");
    for (int j = 0; j <= i; j++)
    {
        fwrite(Earr + j, sizeof(Earr[j]), 1, fp);
    }
    fclose(fp);
}
void deleteEmployee()
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
    puts("1>根据名字查找删除");
    puts("2>根据id查找删除");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
    {
        continue;
    }

    if (choice == 1)
    {
        puts("名字");
        s_gets(e.name, NAMESIZE);

        for (int j = 0; j < i; j++)
        {
            if (!strcmp(e.name, Earr[j].name))
            {
                showEmployee(Earr + j);
                puts("你确定要删除它吗？");
                char ans[2];
                s_gets(ans, 2);
                if (ans[0] == 'y')
                {
                    for (int k = j; k < i - 1; k++)
                    {
                        Earr[k] = Earr[k + 1];
                    }
                    i--;
                }
            }
        }
    }
    else if (choice == 2)
    {
        puts("ID");
        int id;
        scanf("%d", &id);
        while (getchar() != '\n')
            continue;
        for (int j = 0; j < i; j++)
        {
            if (id == Earr[j].id)
            {
                showEmployee(Earr + j);
                puts("你确定要删除它吗？");
                char ans[2];
                s_gets(ans, 2);
                if (ans[0] == 'y')
                {
                    for (int k = j; k < i - 1; k++)
                    {
                        Earr[k] = Earr[k + 1];
                    }
                    i--;
                    break;
                }
            }
        }
    }
    else
        puts("你的选择有误");
    fclose(fp);
    fp = fopen("account", "wb");
    for (int j = 0; j < i; j++)
    {
        fwrite(Earr + j, sizeof(Employee), 1, fp);
    }
    fclose(fp);
}
void changeEmployee()
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
    puts("1>根据名字查找修改");
    puts("2>根据id查找修改");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
    {
        continue;
    }
    if (choice == 1)
    {
        puts("名字");
        s_gets(e.name, NAMESIZE);
        for (int j = 0; j < i; j++)
        {
            if (!strcmp(e.name, Earr[j].name))
            {
                showEmployee(Earr + j);

                char ans[2];
                puts("你要修改姓名吗？");
                s_gets(ans, 2);

                if (ans[0] == 'y')
                {
                    s_gets(Earr[j].name, NAMESIZE);
                }

                puts("你要修改职位吗？");
                s_gets(ans, 2);

                if (ans[0] == 'y')
                {
                    int ch;
                    puts("0>管理者1>前台 ");
                    scanf("%d", &ch);
                    while (getchar() != '\n')
                        continue;
                    if (ch == 0)
                    {
                        strcpy(Earr[j].position, "administrator");
                    }
                    else if (ch == 1)
                    {
                        strcpy(Earr[j].position, "reception");
                    }
                }

                puts("你要修改密码吗？");
                s_gets(ans, 2);

                if (ans[0] == 'y')
                {
                    s_gets(Earr[j].password, PASSWORDSIZE);
                }
            }
        }
    }
    else if (choice == 2)
    {
        puts("ID");
        int id;
        scanf("%d", &id);
        while (getchar() != '\n')
            continue;
        for (int j = 0; j < i; j++)
        {
            if (id == Earr[j].id)
            {
                showEmployee(Earr + j);
                char ans[2];
                puts("你要修改姓名吗？");
                s_gets(ans, 2);

                if (ans[0] == 'y')
                {
                    s_gets(Earr[j].name, NAMESIZE);
                }

                puts("你要修改职位吗？");
                s_gets(ans, 2);

                if (ans[0] == 'y')
                {
                    int ch;
                    puts("0>管理者1>前台 ");
                    scanf("%d", &ch);
                    while (getchar() != '\n')
                        continue;
                    if (ch == 0)
                    {
                        strcpy(Earr[j].position, "administrator");
                    }
                    else if (ch == 1)
                    {
                        strcpy(Earr[j].position, "reception");
                    }
                }

                puts("你要修改密码吗？");
                s_gets(ans, 2);

                if (ans[0] == 'y')
                {
                    s_gets(Earr[j].password, PASSWORDSIZE);
                }
            }
        }
    }
    else
        puts("你的输入有误");
    fclose(fp);
    fp = fopen("account", "wb");
    for (int j = 0; j < i; j++)
    {
        fwrite(Earr + j, sizeof(Employee), 1, fp);
    }
    fclose(fp);
}
void showEmployee(Employee *e)
{
    printf("id:%d\n", e->id);
    printf("名字:%s\n", e->name);
    printf("职位:%s\n", e->position);
    // printf("%d",e->password);
    printf("\n");
}
void showAllEmployees()
{
    Employee e;

    FILE *fp = fopen("account", "rb");
    int i = 0;
    while ((fread(&e, sizeof(Employee), 1, fp)) == 1)
    {
        showEmployee(&e);
    }
    fclose(fp);
}
void logout()
{
    puts("退出成功");
}