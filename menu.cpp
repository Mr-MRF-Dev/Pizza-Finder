#include "menu.h"

void mainMenu(pizzaDataBase* db, AreaList* l){
    string act;
    while(1){
    cout << "---------------------------------------------------------"<< endl;
    cout << " 1) Add-N : add a new Area" << endl;
    cout << " 2) Add-P : add a new main Pizza shop" << endl;
    cout << " 3) Add-Br : add a new branch to a main pizza shop" << endl;
    cout << " 4) Del-Br : Delete a branch from a main Pizza shop" << endl;
    cout << " 5) List-P : list of pizza shops in a hood" << endl;
    cout << " 6) List-Brs : list of the branches of a main pizza shop"<< endl;
    cout << " 7) Near-P : nearst pizza shop to a location" << endl;
    cout << " 8) Near-Br : nearst selected pizza shop in a location"<< endl;
    cout << " 9) Avail-P : list of pizza shops in an area" << endl;
    cout << "10) Most-Brs : the main pizza shop with the most branches"<< endl;
    cout << "11) Undo : undo some selected orders" << endl;
    cout << " 0) Exit : quit the program" << endl;
    cout << "---------------------------------------------------------"<< endl;
    cin >> act;
    if (act == "1" || act == "Add-N" || act == "add-n") {
            system("cls");
            Add_N(l);
        } else if (act == "2" || act == "Add-P" || act == "add-p") {
            system("cls");
            Add_P(db);
        } else if (act == "3" || act == "Add-Br" || act == "add-br") {
            system("cls");
            Add_Br(db);
        } else if (act == "4" || act == "Del-Br" || act == "del-br") {
            system("cls");
            Del_Br(db);
        } else if (act == "5" || act == "List-P" || act == "list-p") {
            system("cls");
            cout << "6\n" << endl;
        } else if (act == "6" || act == "List-Brs" || act == "list-brs") {
            system("cls");
            List_Brs(db);
        } else if (act == "7" || act == "Near-P" || act == "near-p") {
            system("cls");
            cout << "8\n" << endl;
        } else if (act == "8" || act == "Near-Br" || act == "near-br") {
            system("cls");
            cout << "9\n" << endl;
        } else if (act == "9" || act == "Avail-P" || act == "avail-p") {
            system("cls");
            cout << "10\n" << endl;
        } else if (act == "10" || act == "Most-Brs" || act == "most-brs") {
            system("cls");
            cout << "11\n" << endl;
        } else if (act == "11" || act == "Undo" || act == "undo") {
            system("cls");
            cout << "12\n" << endl;
        } else if (act == "0" || act == "Exit" || act == "exit") {
            system("cls");
            cout << "ended, press any key to close the program\n" << endl;
            getch();
            break;
        } else {
            system("cls");
            cout << "please enter a valid option\n" << endl;
        }
    }
}
