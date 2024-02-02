#include "menu.h"

int main() {

    // create a db for Branchs
    pizzaDataBase *db = new pizzaDataBase;
    AreaList* l = new AreaList;

    mainMenu(db,l);
    
    delete db;
    delete l;
    return 0;
}