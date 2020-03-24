#pragma once

#include <stdbool.h>
#define OK 1
#define FALSE 0
typedef bool Status;
#define ACTORNUM 16
#define NAMESIZE 32
#define MOVIENAMESIZE 32
#define MOVIEMAXNUM 16
#define TICKETMEXNUM 1024
typedef struct Time
{
    char year[5];
    char mouth[3];
    char day[3];
} Time;
typedef struct ElemType
{
    char movieName[MOVIENAMESIZE];
    char DirectorName[NAMESIZE];
    char Actors[ACTORNUM][NAMESIZE];
    Time Showtime;
    int ticketNum;
    double ticketprice;
}ElemType;

typedef struct Movie
{
    ElemType MovieInfo;
    struct Movie *next;
    struct Movie *pre;
} Movie, *Pmovie;
typedef struct MovieLinkList
{
    Pmovie head;
    Pmovie tail;
    int movieNum;
} MovieLinkList, *Plist;
Status InitLInkList(Plist p);
Status AddNode(Plist p,ElemType e);
Status DeleteNodeElem(Plist p,Pmovie pm);
// Status DeleteNode(Plist p);
// Status SeekNode(Plist p);
// Status ChangeNode(Plist p);
// Status DeleteNodeNum(Plist p, int n, ElemType *e);
// Status DeleteNodeKey(Plist p, ElemType e);