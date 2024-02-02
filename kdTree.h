
#ifndef KDTREE_H
#define KDTREE_H

#include "branchClass.h"

// using 2D-Tree
class treeNode {
    private:
        branch* node;
        treeNode* left;
        treeNode* right;

    public:
        treeNode(branch* node);
        treeNode(treeNode& tmp);

        treeNode* getLeft();
        treeNode* getRight();

        void setLeft(treeNode* left);
        void setRight(treeNode* right);

};

// class KDTree {
//     private:
//     public:
// };

#endif
