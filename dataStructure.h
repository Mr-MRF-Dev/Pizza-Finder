
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <iostream>
#include <vector>
#include <string>

#include "branchClass.h"
using namespace std;

class branchLinkedList {
    private:
        pizzaMainBranch* main;
        pizzaBranch* head_branch;
        int count;

    public:
        branchLinkedList(pizzaMainBranch* main);
        bool addNewBranch(pizzaBranch* branch);
        bool deleteBranch(Point l);

        string getBrName(Point l);
        string getMainName();
        int getCount();
        void print();
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
        pizzaDataBase(int capacity = 10);
        bool addNewMainBranch(pizzaMainBranch* pbm);
        bool addNewBranch(pizzaBranch* pb);
        bool delBranch(Point l);
        bool printBranch(string name);
        string getBranchName(Point l);

        vector<string> getMostBranch(string name);
 };

#endif
