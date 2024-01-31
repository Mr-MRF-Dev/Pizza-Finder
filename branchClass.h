
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
        pizzaMainBranch(string name, int x, int y);

        string getName();
        Point getPoint();
};

class pizzaBranch {
    private:
        string main_name;
        string name;
        Point point;

    public:
        pizzaBranch(string name, string main_name, int x, int y);

        string getMainName();
        string getName();
        Point getPoint();
};

#endif