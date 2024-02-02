
#include "kdTree.h"

treeNode::treeNode(branch* node) {
    this->node = node;
    left = NULL;
    right = NULL;
}

treeNode::treeNode(treeNode& tmp) {
    node = tmp.node;
    left = tmp.left;
    right = tmp.right;
}

treeNode* treeNode::getLeft() { return left; }
treeNode* treeNode::getRight() { return right; }

void treeNode::setLeft(treeNode* left) { this->left = left; }
void treeNode::setRight(treeNode* right) { this->right = right; }
