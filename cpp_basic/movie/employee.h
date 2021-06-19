#pragma once
#define NAMESIZE 32
#define POSITIONSIZE 64
#define IDSIZE 32
#define PASSWORDSIZE 32
#define EMPLOYSZIE 64
typedef struct Employee
{
    int id;
    char name[NAMESIZE];
    char  position[POSITIONSIZE];
    char password[PASSWORDSIZE];;

}Employee;