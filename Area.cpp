#include "Area.h"

Area::Area(int a1, int a2, int b1, int b2, string name) :P1(a1, a2), P2(b1, b2) { this->nameArea = name; }
bool Area::checkInArea(int x, int y) {
	if (((x >= P1.getX()) && (x <= P2.getX())) && ((y >= P1.getY()) && (y <= P2.getY()))) return true;
	else if(((x >= P2.getX()) && (x <= P1.getX())) && ((y >= P2.getY()) && (y <= P1.getY()))) return true;
	else return false;
}
string Area::getName() { return nameArea; }