
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <iostream>
#include <string>
#include <vector>

#include "branchClass.h"
#include "debug.h"

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
        vector<branchLinkedList*> all_vec;
        branchLinkedList** all_main;
        int count;
        int capacity;

        // int hash(string name, int i);
        int hash(string name);
        branchLinkedList* findBranch(string name);

        void helpMergeSort(vector<branchLinkedList*>* arr, int left, int mid,
                           int right);
        void mergeSort(vector<branchLinkedList*>* arr, int left, int right);

    public:
        pizzaDataBase(int capacity = 10);
        bool addNewMainBranch(pizzaMainBranch* pbm);
        bool addNewBranch(pizzaBranch* pb);
        bool delBranch(Point l);
        bool printBranch(string name);
        string getBranchName(Point l);

        bool getMostBranch();
};

#endif
