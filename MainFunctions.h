
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include <conio.h>

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
void Del_Br(pizzaDataBase* db);
void List_P();
void List_Brs(pizzaDataBase* db);
void Near_P();
void Near_Br();
void Avail_P();
void Most_Brs();
void Undo();

#endif
