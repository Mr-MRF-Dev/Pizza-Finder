
#ifndef BRANCHCLASS_H
#define BRANCHCLASS_H

#include <string>

#include "Location.h"
using namespace std;

class branch {
    protected:
        string name;
        Point point;
        int type;

        // -1 => nothing
        //  0 => pizza main branch
        //  1 => pizza branch

    public:
        friend ostream& operator<<(ostream& os, branch& b);

        branch(string name, int x, int y);
        branch(string name, Point p);
        string getName();
        Point getPoint() const;
        int getType();

        virtual string getMainName() = 0;
};

ostream& operator<<(ostream& os, branch& b);

class pizzaMainBranch : public branch {

    public:
        string getMainName();
        friend ostream& operator<<(ostream& os, pizzaMainBranch& pmb);

        pizzaMainBranch(string name, int x, int y);
        pizzaMainBranch(pizzaMainBranch& tmp);
};

ostream& operator<<(ostream& os, pizzaMainBranch& pmb);

class pizzaBranch : public branch {
    private:
        string main_name;

        pizzaBranch* next;
        pizzaBranch* prev;

    public:
        friend ostream& operator<<(ostream& os, pizzaBranch& pb);

        pizzaBranch(string name, string main_name, int x, int y);
        pizzaBranch(pizzaBranch& tmp);

        string getMainName();

        void setNext(pizzaBranch* next);
        void setPrev(pizzaBranch* prev);

        pizzaBranch* getNext();
        pizzaBranch* getPrev();
};

ostream& operator<<(ostream& os, pizzaBranch& pb);

#endif