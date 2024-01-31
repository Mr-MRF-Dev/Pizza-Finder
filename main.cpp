#include "main.h"

int main() {
    int a;
    char b;
    string x;
    while (1) {
        cout << "---------------------------------------------------------" << endl;
        cout << " 1) Add-N : add a new hood" << endl;
        cout << " 2) Add-P : add a new main Pizza shop" << endl;
        cout << " 3) Add-Br : add a new branch to a main pizza shop" << endl;
        cout << " 4) Del-P : Delete a main Pizza shop" << endl;
        cout << " 5) Del-Br : Delete a branch from a main Pizza shop" << endl;
        cout << " 6) List-P : list of pizza shops in a hood" << endl;
        cout << " 7) List-Brs : list of the branches of a main pizza shop" << endl;
        cout << " 8) Near-P : nearst pizza shop to a location" << endl;
        cout << " 9) Near-Br : nearst selected pizza shop in a location" << endl;
        cout << "10) Avail-P : list of pizza shops in an area" << endl;
        cout << "11) Most-Brs : the main pizza shop with the most branches" << endl;
        cout << "12) Undo : undo some selected orders" << endl;
        cout << " 0) Exit : quit the program" << endl;
        cout << "---------------------------------------------------------" << endl;

        cin >> x;

        if (x == "1" || x == "Add-N" || x == "add-n") {
            system("cls");
            Add_N();
        }
        else if (x == "2" || x == "Add-P" || x == "add-p") {
            system("cls");
            Add_P;
        }
        else if (x == "3" || x == "Add-Br" || x == "add-br") {
            system("cls");
            cout << "3\n" << endl;
        }
        else if (x == "4" || x == "Del-P" || x == "del-p") {
            system("cls");
            cout << "4\n" << endl;
        }
        else if (x == "5" || x == "Del-Br" || x == "del-br") {
            system("cls");
            cout << "5\n" << endl;
        }
        else if (x == "6" || x == "List-P" || x == "list-p") {
            system("cls");
            cout << "6\n" << endl;
        }
        else if (x == "7" || x == "List-Br" || x == "list-br") {
            system("cls");
            cout << "7\n" << endl;
        }
        else if (x == "8" || x == "Near-P" || x == "near-p") {
            system("cls");
            cout << "8\n" << endl;
        }
        else if (x == "9" || x == "Near-Br" || x == "near-br") {
            system("cls");
            cout << "9\n" << endl;
        }
        else if (x == "10" || x == "Avail-P" || x == "avail-p") {
            system("cls");
            cout << "10\n" << endl;
        }
        else if (x == "11" || x == "Most-Brs" || x == "most-brs") {
            system("cls");
            cout << "11\n" << endl;
        }
        else if (x == "12" || x == "Undo" || x == "undo") {
            system("cls");
            cout << "12\n" << endl;
        }
        else if (x == "0" || x == "Exit" || x == "exit") {
            system("cls");
            cout << "ended, press any key to close the program\n" << endl;
            break;
        }
        else {
            system("cls");
            cout<< "please enter a valid option\n" <<endl;
        }
    }
    getch();
    return 0;
}