
#include "branchClass.h"

pizzaMainBranch::pizzaMainBranch(string name, int x, int y) : point(x, y) {
    this->name = name;
}

string pizzaMainBranch::getName() { return name; }

Point pizzaMainBranch::getPoint() { return point; }

pizzaBranch::pizzaBranch(string name, string main_name, int x, int y)
    : point(x, y) {
    this->main_name = main_name;
    this->name = name;
}

string pizzaBranch::getName() { return name; }

string pizzaBranch::getMainName() { return main_name; }

Point pizzaBranch::getPoint() { return point; }
