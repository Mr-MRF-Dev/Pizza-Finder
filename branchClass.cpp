
#include "branchClass.h"

// branch functions
branch::branch(string name, int x, int y) : point(x, y) {
    this->name = name;
    type = -1;
}

branch::branch(string name, Point p) : point(p) {
    this->name = name;
    type = -1;
}

int branch::getType() { return type; }

Point branch::getPoint() { return point; }

string branch::getName() { return name; }

ostream& operator<<(ostream& os, branch& b) {

    // output => " MAIN  ~ Name: xyz, Point: (x, y)"
    // output => "BRANCH ~ Name: xyz, Point: (x, y)"

    string final;
    if (b.type == 0)
        final += " MAIN  ~ Name: " + b.name;
    else
        final += "BRANCH ~ Name: " + b.name;

    final += ",  Point: " + b.point.getStr();

    os << final;
    return os;
}

// pizzaMainBranch functions
pizzaMainBranch::pizzaMainBranch(string name, int x, int y)
    : branch(name, x, y) {
    type = 0;
}

pizzaMainBranch::pizzaMainBranch(pizzaMainBranch& tmp)
    : branch(tmp.name, tmp.point) {
    type = 0;
}

string pizzaMainBranch::getMainName() { return name; }

ostream& operator<<(ostream& os, pizzaMainBranch& pmb) {

    // output => " MAIN  ~ Name: xyz, Point: (x, y)"

    string final = " MAIN  ~ Name: " + pmb.name;
    final += ",  Point: " + pmb.point.getStr();

    os << final;
    return os;
}

// pizzaBranch functions
pizzaBranch::pizzaBranch(string name, string main_name, int x, int y)
    : branch(name, x, y) {
    this->main_name = main_name;
    type = 1;

    this->next = NULL;
    this->prev = NULL;
}

pizzaBranch::pizzaBranch(pizzaBranch& tmp) : branch(tmp.name, tmp.point) {
    main_name = tmp.main_name;
    type = 1;

    next = tmp.next;
    prev = tmp.prev;
}

string pizzaBranch::getMainName() { return main_name; }

pizzaBranch* pizzaBranch::getNext() { return next; }
pizzaBranch* pizzaBranch::getPrev() { return prev; }

void pizzaBranch::setNext(pizzaBranch* next) { this->next = next; }
void pizzaBranch::setPrev(pizzaBranch* prev) { this->prev = prev; }

ostream& operator<<(ostream& os, pizzaBranch& pb) {

    // output => "BRANCH ~ Name: xyz, Point: (x, y)"

    string final = "BRANCH ~ Name: " + pb.name;
    final += ",  Point: " + pb.point.getStr();

    os << final;
    return os;
}
