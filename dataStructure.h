
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <list>
#include <string>

#include "branchClass.h"
using namespace std;

class branchLinkedList {
    private:
        pizzaMainBranch main;
        pizzaBranch* head_branch;

    public:
        branchLinkedList(pizzaMainBranch main);
        bool addNewBranch(pizzaBranch* branch);
        bool deleteBranch(string name);

        string getMainName();
};

class pizzaDataBase {
    private:
        branchLinkedList** all_main;
        int count;
        int capacity;

        // int hash(string name, int i);
        int hash(string name);
        branchLinkedList* findBranch(string name);

    public:
        pizzaDataBase(int);
        bool addNewMainBranch(pizzaMainBranch* pb);
        bool addNewBranch(pizzaBranch* pb);
};

#endif
