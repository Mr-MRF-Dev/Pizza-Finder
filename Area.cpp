#include "Area.h"

// Area Functions
Area::Area(int a1, int a2, int b1, int b2, string name)
    : P1(a1, a2), P2(b1, b2) {
    this->nameArea = name;
}

Area::Area(Area &tmp) : P1(tmp.P1), P2(tmp.P2) { nameArea = tmp.nameArea; }

bool Area::operator==(Area tmp) {
    if (nameArea == tmp.nameArea) return true;

    if (P1 == tmp.P1 && P2 == tmp.P2) return true;

    if (P1 == tmp.P2 && P2 == tmp.P1) return true;

    if (P1.getX() == tmp.P1.getX() && P2.getY() == tmp.P1.getY() &&
        P1.getY() == tmp.P2.getY() && P2.getX() == tmp.P2.getX())
        return true;

    if (P1.getX() == tmp.P2.getX() && P2.getY() == tmp.P2.getY() &&
        P1.getY() == tmp.P1.getY() && P2.getX() == tmp.P1.getX())
        return true;

    return false;
}

bool Area::checkInArea(int x, int y) {
    if (((x >= P1.getX()) && (x <= P2.getX())) &&
        ((y >= P1.getY()) && (y <= P2.getY())))
        return true;
    else if (((x >= P2.getX()) && (x <= P1.getX())) &&
             ((y >= P2.getY()) && (y <= P1.getY())))
        return true;
    else
        return false;
}

string Area::getName() { return nameArea; }

int Area::getMaxX() { return max(P1.getX(), P2.getX()); }

int Area::getMinX() { return min(P1.getX(), P2.getX()); }

int Area::getMaxY() { return max(P1.getY(), P2.getY()); }

int Area::getMinY() { return min(P1.getY(), P2.getY()); }

// AreaList Functions
AreaList::AreaList(int c) {
    capacity = c;
    all = new Area *[c];
    count = 0;
}

bool AreaList::addArea(Area a) {

    Area *new_area = new Area(a);

    if (count == capacity) {

        bool canAdd = true;

        // malloc new space
        Area **tmp = all;
        all = new Area *[capacity *= 2];

        for (int i = 0; i < count; i++) {

            if (*all[i] == *new_area) {
                canAdd = false;
            }

            all[i] = tmp[i];
            delete tmp[i];
        }

        delete tmp;

        if (canAdd) {
            all[count++] = new_area;
        }

        else {
            delete new_area;
            return false;
        }
    }

    // add new area
    for (int i = 0; i < count; i++) {
        if (*all[i] == *new_area) {
            delete new_area;
            return false;
        }
    }

    all[count++] = new_area;
    return true;
}

Area *AreaList::search(string name) {

    for (int i = 0; i < count; i++) {
        if (all[i]->getName() == name) {

            return all[i];
        }
    }

    return NULL;
}
