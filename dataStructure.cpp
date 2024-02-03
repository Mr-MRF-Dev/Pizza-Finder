
#include "dataStructure.h"

// branchLinkedList functions
branchLinkedList::branchLinkedList(pizzaMainBranch* main) {
    this->main = main;
    head_branch = NULL;
    count = 1;
}

bool branchLinkedList::addNewBranch(pizzaBranch* branch) {

    if (head_branch == NULL) {
        head_branch = branch;
        count++;
        return true;
    }

    pizzaBranch* tmp = head_branch;
    while (tmp->getNext() != NULL) {

        if (tmp->getName() == branch->getName()) return false;

        // if (tmp->getPoint() == branch->getPoint()) return false;

        tmp = tmp->getNext();
    }

    // check the last node
    if (tmp->getName() == branch->getName()) return false;
    // if (tmp->getPoint() == branch->getPoint()) return false;

    tmp->setNext(branch);
    branch->setPrev(tmp);
    count++;
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
        count--;
        return true;
    }

    while (tmp != NULL) {

        if (tmp->getPoint() == l) {
            // delete node
            tmp->getPrev()->setNext(tmp->getNext());
            delete tmp;
            count--;
            return true;
        }

        tmp = tmp->getNext();
    }

    return false;
}

string branchLinkedList::getMainName() { return main->getName(); }

string branchLinkedList::getBrName(Point l) {

    pizzaBranch* tmp = head_branch;
    while (tmp) {
        if (tmp->getPoint() == l) {
            return head_branch->getName();
        }
        tmp = tmp->getNext();
    }
    return "";
}

int branchLinkedList::getCount() { return count; }

void branchLinkedList::print() {
    int i = 0;
    cout << "\n" << *main << endl;
    pizzaBranch* tmp = head_branch;
    cout << "\n";
    while (tmp) {
        i++;
        cout << i << ". " << *tmp << endl;
        tmp = tmp->getNext();
    }
    cout << "\ntotal branches: " << i << endl;
}

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
    all_vec.push_back(new_main);
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

bool pizzaDataBase::printBranch(string name) {

    branchLinkedList* branch = findBranch(name);

    if (branch) {

        branch->print();

        return true;
    }

    return false;
}

string pizzaDataBase::getBranchName(Point l) {

    for (int i = 0; i < capacity; i++) {
        if (all_main[i] && all_main[i]->getBrName(l) != "")
            return all_main[i]->getBrName(l);
    }
    return "";
}

bool pizzaDataBase::getMostBranch() {

    if (all_vec.size() == 0) return false;

    string final;
    mergeSort(&all_vec, 0, all_vec.size() - 1);

    all_vec[0]->print();
    return true;
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

void pizzaDataBase::helpMergeSort(vector<branchLinkedList*>* arr, int left,
                                  int mid, int right) {

    int leftLen = mid - left + 1;
    int rightLen = right - mid;

    vector<branchLinkedList*> leftVec(leftLen);
    vector<branchLinkedList*> rightVec(rightLen);

    for (int i = 0; i < leftLen; i++) leftVec[i] = (*arr)[left + i];
    for (int j = 0; j < rightLen; j++) rightVec[j] = (*arr)[mid + 1 + j];

    auto I_ofLeft = 0, I_ofRight = 0;
    int insertMaster = left;

    while (I_ofLeft < leftLen && I_ofRight < rightLen) {

        if (leftVec[I_ofLeft]->getCount() >= rightVec[I_ofRight]->getCount()) {

            (*arr)[insertMaster] = leftVec[I_ofLeft];
            I_ofLeft++;
        }

        else {
            (*arr)[insertMaster] = rightVec[I_ofRight];
            I_ofRight++;
        }

        insertMaster++;
    }

    while (I_ofLeft < leftLen) {
        (*arr)[insertMaster] = leftVec[I_ofLeft];
        I_ofLeft++;
        insertMaster++;
    }

    while (I_ofRight < rightLen) {
        (*arr)[insertMaster] = rightVec[I_ofRight];
        I_ofRight++;
        insertMaster++;
    }
}

void pizzaDataBase::mergeSort(vector<branchLinkedList*>* arr, int left,
                              int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    helpMergeSort(arr, left, mid, right);
}
