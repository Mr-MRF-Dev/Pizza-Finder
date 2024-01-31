
#include "dataStructure.h"

// branchLinkedList functions
branchLinkedList::branchLinkedList(pizzaMainBranch main) : main(main) {
    head_branch = NULL;
}

bool branchLinkedList::addNewBranch(pizzaBranch* branch) {

    if (head_branch == NULL) {
        head_branch = branch;
        return true;
    }

    pizzaBranch* tmp = head_branch;
    while (tmp->getNext() != NULL) {

        if (tmp->getName() == branch->getName()) return false;

        if (tmp->getPoint() == branch->getPoint()) return false;

        tmp = tmp->getNext();
    }

    // check the last node
    if (tmp->getName() == branch->getName()) return false;
    if (tmp->getPoint() == branch->getPoint()) return false;

    tmp->setNext(branch);
    branch->setPrev(tmp);

    return true;
}
