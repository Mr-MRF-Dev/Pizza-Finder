
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Point {
    private:
        int x;
        int y;

    public:
        Point(int x, int y);
        Point(Point& tmp);

        int getX();
        int getY();

        string getStr();

        bool operator==(Point tmp);
};

#endif