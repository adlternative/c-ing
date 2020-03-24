//添加工作人员信息
//添加电影信息
#pragma once
#include "MovieLinkList.h"
#include"employee.h"
void showAllMovies();
void showMovies(const Movie *ptemp);
Status addNewMovies();
void underCarriageMovies();
void changeMovies();
void addEmployee();
void deleteEmployee();
void changeEmployee();
void showAllEmployees();
void showEmployee(Employee*e);

void logout();
Status SeekNodeDirectorName(const Plist pml, Movie findarr[], int *findnum);
void seekMovies();
Status SeekNodeMovieName(const Plist pml, Pmovie find);
Status SeekNodeActorName(const Plist pml, Movie findarr[], int *findnum);
Status SeekNodeNum(const Plist pml, Pmovie find);
Status SeekNodeShowTime(const Plist pml, Movie findarr[], int *findnum);
// changeMovies();