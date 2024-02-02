
#include "kdTree.h"

// treeNode functions
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

Point treeNode::getPoint() { return node->getPoint(); }

treeNode* treeNode::getLeft() { return left; }
treeNode* treeNode::getRight() { return right; }

void treeNode::setLeft(treeNode* left) { this->left = left; }
void treeNode::setRight(treeNode* right) { this->right = right; }

// KDTree functions
KDTree::KDTree() { head = NULL; }

treeNode* KDTree::helpInsert(treeNode* root, branch* node, int depth) {

    if (root == NULL) {
        treeNode* new_node = new treeNode(node);
        return new_node;
    }

    int number_node, number_root;

    if (depth % 2 == 0) {
        number_node = node->getPoint().getX();
        number_root = root->getPoint().getX();
    }

    else {
        number_node = node->getPoint().getY();
        number_root = root->getPoint().getY();
    }

    if (number_node < number_root)
        root->setLeft(helpInsert(root->getLeft(), node, depth + 1));
    else
        root->setRight(helpInsert(root->getRight(), node, depth + 1));

    return root;
}

bool KDTree::insert(branch* node) {
    head = helpInsert(head, node, 0);
    return true;
}
