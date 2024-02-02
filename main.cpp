#include "menu.h"

int main() {

    // create a db for Branchs
    pizzaDataBase *db = new pizzaDataBase;
    AreaList* l = new AreaList;
    KDTree ap;
    mainMenu(db,l,ap);
    
    delete db;
    delete l;
    return 0;
}