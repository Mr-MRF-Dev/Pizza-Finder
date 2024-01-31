#include "Location.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() { return x; }

int Point::getY() { return y; }

bool Point::operator==(Point tmp) {

    if (x == tmp.x && y == tmp.y) return true;

    return false;
}