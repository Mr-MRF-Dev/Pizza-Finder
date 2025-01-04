
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#ifdef _WIN32
    #include <conio.h>
    #define SYS_CLEAR system("cls")
#else
    #include <ncurses.h>

    #include <cstdlib>
    #define SYS_CLEAR system("clear")

int getch() {
    initscr();
    cbreak();
    noecho();
    int ch = getch();
    endwin();
    return ch;
}
#endif

#include <iostream>
using namespace std;

#include "Area.h"
#include "branchClass.h"
#include "color.h"
#include "dataStructure.h"
#include "kdTree.h"

void Add_N(AreaList* l);
void Add_P(pizzaDataBase* db, KDTree* ap);
void Add_Br(pizzaDataBase* db, KDTree* ap);
void Del_Br(pizzaDataBase* db, KDTree* ap);
void List_P(KDTree* ap, AreaList* l);
void List_Brs(pizzaDataBase* db);
void Near_P(KDTree* ap);
void Near_Br(KDTree* ap, pizzaDataBase* db);
void Avail_P(KDTree* ap);
void Most_Brs(pizzaDataBase* db);
void Undo();

#endif
