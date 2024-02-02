
#ifndef KDTREE_H
#define KDTREE_H

#include "Location.h"
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
        Point getPoint();

        treeNode* getLeft();
        treeNode* getRight();

        void setLeft(treeNode* left);
        void setRight(treeNode* right);
};

class KDTree {
    private:
        treeNode* head;

        treeNode* helpInsert(treeNode* root, branch* node, int depth);

    public:
        KDTree();
        bool insert(branch* node);
};

#endif
