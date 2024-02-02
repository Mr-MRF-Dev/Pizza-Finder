
#include "branchClass.h"

// pizzaMainBranch functions
pizzaMainBranch::pizzaMainBranch(string name, int x, int y) : point(x, y) {
    this->name = name;
}

pizzaMainBranch::pizzaMainBranch(pizzaMainBranch& tmp) : point(tmp.point) {
    name = tmp.name;
}

string pizzaMainBranch::getName() { return name; }

ostream& operator<<(ostream& os, pizzaMainBranch& pmb) {

    // output => "Name: xyz, Point: (x, y)"

    string final = "Name: " + pmb.name;
    final += ",  Point: " + pmb.point.getStr();

    os << final;
    return os;
}

Point pizzaMainBranch::getPoint() { return point; }

// pizzaBranch functions
pizzaBranch::pizzaBranch(string name, string main_name, int x, int y)
    : point(x, y) {
    this->main_name = main_name;
    this->name = name;

    this->next = NULL;
    this->prev = NULL;
}

string pizzaBranch::getName() { return name; }

string pizzaBranch::getMainName() { return main_name; }

Point pizzaBranch::getPoint() { return point; }

pizzaBranch* pizzaBranch::getNext() { return next; }
pizzaBranch* pizzaBranch::getPrev() { return prev; }

void pizzaBranch::setNext(pizzaBranch* next) { this->next = next; }
void pizzaBranch::setPrev(pizzaBranch* prev) { this->prev = prev; }

ostream& operator<<(ostream& os, pizzaBranch& pb) {

    // output => "Name: xyz, Point: (x, y)"

    string final = "Name: " + pb.name;
    final += ",  Point: " + pb.point.getStr();

    os << final;
    return os;
}
