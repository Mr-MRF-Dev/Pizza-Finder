#include "Location.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;

    // log2("Point::Point(x, y)", this->getStr());
}

Point::Point(Point& tmp) {
    x = tmp.x;
    y = tmp.y;

    // log2("Point::Point(& Point)", this->getStr());
}

int Point::getX() {
    // log2("Point::getX()", this->getStr());

    return x;
}

int Point::getY() {
    // log2("Point::getY()", this->getStr());

    return y;
}

bool Point::operator==(Point tmp) {

    // log3("Point::operator==", this->getStr(), tmp.getStr());

    if (x == tmp.x && y == tmp.y) return true;

    return false;
}

string Point::getStr() {

    // log2("Point::getStr()", this->getStr());

    return "(" + to_string(x) + ", " + to_string(y) + ")";
}
