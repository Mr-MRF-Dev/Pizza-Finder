
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include <iostream>
#include<conio.h>
using namespace std;
#include "Area.h"
#include "branchClass.h"
#include "dataStructure.h"
#include "color.h"

void Add_N(AreaList* l);
void Add_P(pizzaDataBase* db);
void Add_Br(pizzaDataBase* db);
void Del_Br(pizzaDataBase* db);
void List_P();
void List_Brs(pizzaDataBase* db);
void Near_P();
void Near_Br();
void Avail_P();
void Most_Brs();
void Undo();

#endif
