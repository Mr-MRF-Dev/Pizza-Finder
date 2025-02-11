#include "menu.h"

void mainMenu(pizzaDataBase* db, AreaList* l, KDTree* ap) {
    string act;
    int returnVal;
    while (1) {
        cout << Color_Yellow_Dark
             << "---------------------------------------------------------"
             << endl;
        cout << Color_Yellow << " 1)" << Color_Aqua << " Add-N " << Color_Yellow
             << ":" << Color_Reset << " add a new Area" << endl;
        cout << Color_Yellow << " 2)" << Color_Aqua << " Add-P " << Color_Yellow
             << ":" << Color_Reset << " add a new main Pizza shop" << endl;
        cout << Color_Yellow << " 3)" << Color_Aqua << " Add-Br "
             << Color_Yellow << ":" << Color_Reset
             << " add a new branch to a main pizza shop" << endl;
        cout << Color_Yellow << " 4)" << Color_Aqua << " Del-Br "
             << Color_Yellow << ":" << Color_Reset
             << " Delete a branch from a main Pizza shop" << endl;
        cout << Color_Yellow << " 5)" << Color_Aqua << " List-P "
             << Color_Yellow << ":" << Color_Reset
             << " list of pizza shops in a hood" << endl;
        cout << Color_Yellow << " 6)" << Color_Aqua << " List-Brs "
             << Color_Yellow << ":" << Color_Reset
             << " list of the branches of a main pizza shop" << endl;
        cout << Color_Yellow << " 7)" << Color_Aqua << " Near-P "
             << Color_Yellow << ":" << Color_Reset
             << " nearst pizza shop to a location" << endl;
        cout << Color_Yellow << " 8)" << Color_Aqua << " Near-Br "
             << Color_Yellow << ":" << Color_Reset
             << " nearst selected pizza shop in a location" << endl;
        cout << Color_Yellow << " 9)" << Color_Aqua << " Avail-P "
             << Color_Yellow << ":" << Color_Reset
             << " list of pizza shops in an area" << endl;
        cout << Color_Yellow << "10)" << Color_Aqua << " Most-Brs "
             << Color_Yellow << ":" << Color_Reset
             << " the main pizza shop with the most branches" << endl;
        cout << Color_Yellow << "11)" << Color_Aqua << " Undo " << Color_Yellow
             << ":" << Color_Reset << " undo some selected orders" << endl;
        cout << Color_Yellow << " 0)" << Color_Aqua << " Exit " << Color_Yellow
             << ":" << Color_Reset << " quit the program" << endl;
        cout << Color_Yellow_Dark
             << "---------------------------------------------------------"
             << Color_Reset << endl;
        cin >> act;
        if (act == "1" || act == "Add-N" || act == "add-n") {
            returnVal = SYS_CLEAR();
            Add_N(l);
        } else if (act == "2" || act == "Add-P" || act == "add-p") {
            returnVal = SYS_CLEAR();
            Add_P(db, ap);
        } else if (act == "3" || act == "Add-Br" || act == "add-br") {
            returnVal = SYS_CLEAR();
            Add_Br(db, ap);
        } else if (act == "4" || act == "Del-Br" || act == "del-br") {
            returnVal = SYS_CLEAR();
            Del_Br(db, ap);
        } else if (act == "5" || act == "List-P" || act == "list-p") {
            returnVal = SYS_CLEAR();
            List_P(ap, l);
        } else if (act == "6" || act == "List-Brs" || act == "list-brs") {
            returnVal = SYS_CLEAR();
            List_Brs(db);
        } else if (act == "7" || act == "Near-P" || act == "near-p") {
            returnVal = SYS_CLEAR();
            Near_P(ap);
        } else if (act == "8" || act == "Near-Br" || act == "near-br") {
            returnVal = SYS_CLEAR();
            Near_Br(ap, db);
        } else if (act == "9" || act == "Avail-P" || act == "avail-p") {
            returnVal = SYS_CLEAR();
            Avail_P(ap);
        } else if (act == "10" || act == "Most-Brs" || act == "most-brs") {
            returnVal = SYS_CLEAR();
            Most_Brs(db);
        } else if (act == "11" || act == "Undo" || act == "undo") {
            returnVal = SYS_CLEAR();
            cout << "12\n" << endl;
        } else if (act == "0" || act == "Exit" || act == "exit") {
            returnVal = SYS_CLEAR();
            cout << Color_Deep_Pink
                 << "program ended, press any key to close the program\n"
                 << endl;
            getch();
            cout << Color_Reset << endl;
            break;
        } else {
            returnVal = SYS_CLEAR();
            cout << Color_Red << "please enter a valid option\n" << endl;
        }
    }
}
