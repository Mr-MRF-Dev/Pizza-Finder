
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <cmath>
#include "debug.h"
using namespace std;

class Point {
    private:
        int x;
        int y;

    public:
        Point(int x, int y);
        Point(const Point& tmp);

        int getX();
        int getY();

        string getStr();

        bool operator==(Point tmp);

        int getDistance(Point temp);
};

#endif