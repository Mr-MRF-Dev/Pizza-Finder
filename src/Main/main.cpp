#include "menu.h"

int main() {

    // create a db for Branchs
    pizzaDataBase* db = new pizzaDataBase;
    AreaList* l = new AreaList;
    KDTree* ap = new KDTree;
    mainMenu(db, l, ap);

    delete db;
    delete l;
    delete ap;
    return 0;
}