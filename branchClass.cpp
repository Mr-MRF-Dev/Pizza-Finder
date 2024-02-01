
#include "branchClass.h"

// pizzaMainBranch functions
pizzaMainBranch::pizzaMainBranch(string name, int x, int y) : point(x, y) {
    this->name = name;
}

pizzaMainBranch::pizzaMainBranch(pizzaMainBranch& tmp) : point(tmp.point) {
    name = tmp.name;
}

string pizzaMainBranch::getName() { return name; }

Point pizzaMainBranch::getPoint() { return point; }

pizzaBranch::pizzaBranch(string name, string main_name, int x, int y)
    : point(x, y) {
    this->main_name = main_name;
    this->name = name;

    this->next = NULL;
    this->prev = NULL;
}

// pizzaBranch functions
string pizzaBranch::getName() { return name; }

string pizzaBranch::getMainName() { return main_name; }

Point pizzaBranch::getPoint() { return point; }

pizzaBranch* pizzaBranch::getNext() { return next; }
pizzaBranch* pizzaBranch::getPrev() { return prev; }

void pizzaBranch::setNext(pizzaBranch* next) { this->next = next; }
void pizzaBranch::setPrev(pizzaBranch* prev) { this->prev = prev; }
