#include "main.h"

int main() {

    // create a db for Branchs
    pizzaDataBase *db = new pizzaDataBase;
    AreaList* l = new AreaList;
    int a;
    char b;
    string x;
    while (1) {
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

        cin >> x;

        if (x == "1" || x == "Add-N" || x == "add-n") {
            system("cls");
            Add_N(l);
        } else if (x == "2" || x == "Add-P" || x == "add-p") {
            system("cls");
            Add_P(db);
        } else if (x == "3" || x == "Add-Br" || x == "add-br") {
            system("cls");
            Add_Br(db);
        } else if (x == "4" || x == "Del-Br" || x == "del-br") {
            system("cls");
            Del_Br(db);
        } else if (x == "5" || x == "List-P" || x == "list-p") {
            system("cls");
            cout << "6\n" << endl;
        } else if (x == "6" || x == "List-Brs" || x == "list-brs") {
            system("cls");
            List_Brs(db);
        } else if (x == "7" || x == "Near-P" || x == "near-p") {
            system("cls");
            cout << "8\n" << endl;
        } else if (x == "8" || x == "Near-Br" || x == "near-br") {
            system("cls");
            cout << "9\n" << endl;
        } else if (x == "9" || x == "Avail-P" || x == "avail-p") {
            system("cls");
            cout << "10\n" << endl;
        } else if (x == "10" || x == "Most-Brs" || x == "most-brs") {
            system("cls");
            cout << "11\n" << endl;
        } else if (x == "11" || x == "Undo" || x == "undo") {
            system("cls");
            cout << "12\n" << endl;
        } else if (x == "0" || x == "Exit" || x == "exit") {
            system("cls");
            cout << "ended, press any key to close the program\n" << endl;
            break;
        } else {
            system("cls");
            cout << "please enter a valid option\n" << endl;
        }
    }
    getch();
    return 0;
}