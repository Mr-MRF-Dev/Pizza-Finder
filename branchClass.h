
#ifndef BRANCHCLASS_H
#define BRANCHCLASS_H

#include <string>

#include "Location.h"
using namespace std;

class pizzaMainBranch {
    private:
        string name;
        Point point;

    public:
        friend ostream& operator<<(ostream& os, pizzaMainBranch& pmb);

        pizzaMainBranch(string name, int x, int y);
        pizzaMainBranch(pizzaMainBranch& tmp);

        string getName();
        Point getPoint();
};

ostream& operator<<(ostream& os, pizzaMainBranch& pmb);

class pizzaBranch {
    private:
        string main_name;
        string name;
        Point point;

        pizzaBranch* next;
        pizzaBranch* prev;

    public:
        friend ostream& operator<<(ostream& os, pizzaBranch& pb);

        pizzaBranch(string name, string main_name, int x, int y);

        string getMainName();
        string getName();
        Point getPoint();

        void setNext(pizzaBranch* next);
        void setPrev(pizzaBranch* prev);

        pizzaBranch* getNext();
        pizzaBranch* getPrev();
};

ostream& operator<<(ostream& os, pizzaBranch& pb);

#endif