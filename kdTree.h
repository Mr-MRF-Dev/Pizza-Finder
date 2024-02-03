
#ifndef KDTREE_H
#define KDTREE_H

#include <vector>

#include "Area.h"
#include "Location.h"
#include "branchClass.h"
#include "debug.h"
using namespace std;

// using 2D-Tree
class treeNode {
    private:
        branch* node;
        treeNode* left;
        treeNode* right;
        int left_depth;
        int right_depth;

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

        void setLeftDepth(int left);
        void setRightDepth(int right);
        int getLeftDepth();
        int getRightDepth();
        void add1LeftDepth();
        void add1RightDepth();

        bool isBalanced();
};

class KDTree {
    private:
        treeNode* head;
        vector<treeNode*> vec_sort_X;
        bool needReBuild;

        treeNode* helpInsert(treeNode* root, branch* node, int depth);
        void insertInVecX(treeNode* x);

        treeNode* helpReBuild(vector<treeNode*> v, int depth);
        void reBuild();

        void helpMergeSort(vector<treeNode*>* arr, int left, int mid, int right,
                           int select);
        void mergeSort(vector<treeNode*>* arr, int left, int right, int select);

        bool helpSearch(treeNode* root, branch* node, int depth);

        treeNode* minThreeNode(treeNode* x, treeNode* y, treeNode* z,
                               int depth);
        treeNode* helpDeleteNode(treeNode* root, Point p, int depth,
                                 bool* deleted);
        treeNode* helpFindMin(treeNode* root, int select, int depth);
        treeNode* findMin(treeNode* root, int select);

        void helpSearchArea(treeNode* root, vector<branch*>* vec, int depth,
                            int max_x, int min_x, int max_y, int min_y);

    public:
        KDTree();
        bool insert(branch* node);
        bool search(branch* node);
        bool deleteNode(Point p);

        vector<branch*> searchArea(Area* a);
};

#endif
