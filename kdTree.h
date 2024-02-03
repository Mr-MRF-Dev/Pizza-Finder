
#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
using namespace std;

#include "Area.h"
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
        branch* getNode();

        void setNode(branch* node);
        void setLeft(treeNode* left);
        void setRight(treeNode* right);
};

class KDTree {
    private:
        treeNode* head;

        treeNode* helpInsert(treeNode* root, branch* node, int depth);
        bool helpSearch(treeNode* root, branch* node, int depth);

        treeNode* minThreeNode(treeNode* x, treeNode* y, treeNode* z,
                               int depth);
        treeNode* helpDeleteNode(treeNode* root, Point p, int depth,
                                 bool* deleted);
        treeNode* helpFindMin(treeNode* root, int select, int depth);
        treeNode* findMin(treeNode* root, int select);

        void helpSearchArea(treeNode* root, vector<branch*>* vec, int depth,
                                 int max_x, int min_x, int max_y, int min_y);

        treeNode* helpFindNearstBranch(Point t, treeNode* root, treeNode* near, int depth);

    public:
        KDTree();
        bool insert(branch* node);
        bool search(branch* node);
        bool deleteNode(Point p);

        vector<branch*> searchArea(Area* a);

        bool checkOtherBr(Point t, treeNode* root, treeNode* near, int depth);
        branch* findNearstBranch(Point t);

};

#endif
