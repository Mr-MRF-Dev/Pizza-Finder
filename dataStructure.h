
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

};


// class pizzaDataBase {
//     private:
//         pizzaMainBranch* all_main;
//         int count;

//     public:
//         pizzaDataBase(/* args */);
//         ~pizzaDataBase();
// };

// pizzaDataBase::pizzaDataBase(/* args */) {}

// pizzaDataBase::~pizzaDataBase() {}

#endif