
#ifndef AREA_H
#define AREA_H
#include "Location.h"
#include <string>
using namespace std;

class Area{
	Point P1;
	Point P2;
	string nameArea;
public:
	Area(int a1, int a2, int b1, int b2, string name);
	bool checkInArea(int x, int y);
	string getName();

};



#endif