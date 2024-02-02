
#include "dataStructure.h"

// branchLinkedList functions
branchLinkedList::branchLinkedList(pizzaMainBranch* main) {
    this->main = main;
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

bool branchLinkedList::deleteBranch(Point l) {

    if (head_branch == NULL) {
        return false;
    }

    pizzaBranch* tmp = head_branch;
    if (head_branch->getPoint() == l) {
        // delete head
        head_branch = head_branch->getNext();
        delete tmp;
        return true;
    }

    while (tmp != NULL) {

        if (tmp->getPoint() == l) {
            // delete node
            tmp->getPrev()->setNext(tmp->getNext());
            delete tmp;
            return true;
        }

        tmp = tmp->getNext();
    }

    return false;
}

string branchLinkedList::getMainName() { return main->getName(); }

// pizzaDataBase functions
pizzaDataBase::pizzaDataBase(int capacity) {
    this->capacity = capacity;
    all_main = new branchLinkedList*[capacity];
    //* ¯\_(ツ)_/¯
    // for (int i = 0; i < capacity; i++) {
    //     all_main[i] = NULL;
    // }
    count = 0;
}

bool pizzaDataBase::addNewMainBranch(pizzaMainBranch* pbm) {

    if (count == capacity) {
        // malloc new space
        branchLinkedList** tmp = all_main;

        all_main = new branchLinkedList*[capacity * 2];
        capacity *= 2;

        //* ¯\_(ツ)_/¯
        // for (int i = 0; i < capacity; i++) {
        //     all_main[i] = NULL;
        // }

        for (int i = 0; i < count; ++i) {

            int index = hash(tmp[i]->getMainName());

            while (all_main[index] != NULL) {
                index++;
                if (index == capacity) {
                    index = 0;
                }
            }

            all_main[index] = tmp[i];
            delete tmp[i];
        }

        delete tmp;
    }

    // add new MAIN Branch
    branchLinkedList* new_main = new branchLinkedList(pbm);

    // where add the main branch???
    // using hash function
    int index = hash(pbm->getName());
    while (all_main[index] != NULL) {
        if (all_main[index]->getMainName() == new_main->getMainName()) {
            delete new_main;
            return false;
        }

        index++;
        if (index == capacity) {
            index = 0;
        }
    }

    all_main[index] = new_main;
    count++;

    return true;
}

int pizzaDataBase::hash(string name) {

    int final = 0;

    for (int j = name.length(); j >= 0; j--) {

        int key = (int)name[j] * j + 1;

        final += key;

        if (final % capacity * 1000 == 0) {
            final /= 2;
        }
    }

    return final % capacity;
}

branchLinkedList* pizzaDataBase::findBranch(string name) {

    int first_index = hash(name);
    int sec_index = first_index;

    do {

        if (all_main[sec_index] && all_main[sec_index]->getMainName() == name)
            return all_main[sec_index];

        sec_index++;
        if (sec_index == capacity) sec_index = 0;

    } while ((sec_index != first_index));

    return NULL;
}

bool pizzaDataBase::addNewBranch(pizzaBranch* pb) {

    string main_name = pb->getMainName();
    branchLinkedList* branch = findBranch(main_name);

    if (branch) return branch->addNewBranch(pb);

    return false;
}

bool pizzaDataBase::delBranch(Point l) {

    for (int i = 0; i < capacity; i++) {
        if (all_main[i] && all_main[i]->deleteBranch(l)) return true;
    }

    return false;
}

// int pizzaDataBase::hash(string name, int i) {

//     int final_1 = 0;
//     int final_2 = 0;

//     for (int j = name.length(); j >= 0; j--) {

//         int key = (int)name[j] * j + 1;
//         if (j % 2 == 0) {
//             final_1 += key;

//             if (final_1 % 13 == 0) {
//                 final_1 /= 2;
//             }

//         }

//         else {
//             final_2 += key * 2;

//             if (final_2 % 13 == 0) {
//                 final_2 /= 2;
//             }
//         }
//     }

//     // double hash.......
//     return (final_1 + final_2 * i) % capacity;
// }
