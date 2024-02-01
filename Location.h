
#ifndef LOCATION_H
#define LOCATION_H

class Point {
    private:
        int x;
        int y;

    public:
        Point(int x, int y);
        Point(Point& tmp);
        bool operator==(Point tmp);

        int getX();
        int getY();

        bool operator==(Point tmp);
};

#endif