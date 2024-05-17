
#ifndef AREA_H
#define AREA_H
#include <string>

#include "Location.h"
using namespace std;

class Area {
        Point P1;
        Point P2;
        string nameArea;

    public:
        Area(int a1, int a2, int b1, int b2, string name);
        Area(Area &tmp);
		bool operator==(Area tmp);
        bool checkInArea(int x, int y);
        string getName();

        int getMaxX();
        int getMinX();
        int getMaxY();
        int getMinY();
};

class AreaList {

    private:
        Area** all;
        int capacity;
        int count;

    public:
        AreaList(int c = 10);
        bool addArea(Area a);
        Area* search(string name);

};

#endif