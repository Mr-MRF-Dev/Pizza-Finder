
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

branch* treeNode::getNode() { return node; }

void treeNode::setNode(branch* node) { this->node = node; }

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

    if (search(node)) {

        return false;
    }

    head = helpInsert(head, node, 0);
    return true;
}

bool KDTree::helpSearch(treeNode* root, branch* node, int depth) {
    if (root == NULL) return false;
    if (root->getPoint() == node->getPoint()) return true;

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
        return helpSearch(root->getLeft(), node, depth + 1);

    return helpSearch(root->getRight(), node, depth + 1);
}

bool KDTree::search(branch* node) { return helpSearch(head, node, 0); }

treeNode* KDTree::minThreeNode(treeNode* x, treeNode* y, treeNode* z,
                               int depth) {

    treeNode* min = x;
    if (depth == 0) {
        // using X
        if (y != NULL && y->getPoint().getX() < min->getPoint().getX()) min = y;
        if (z != NULL && z->getPoint().getX() < min->getPoint().getX()) min = z;
    }

    else {
        // using Y
        if (y != NULL && y->getPoint().getY() < min->getPoint().getY()) min = y;
        if (z != NULL && z->getPoint().getY() < min->getPoint().getY()) min = z;
    }

    return min;
}

treeNode* KDTree::helpFindMin(treeNode* root, int select, int depth) {

    if (root == NULL) return NULL;

    if (depth % 2 == 0) {
        if (root->getLeft() == NULL) return root;

        return helpFindMin(root->getLeft(), select, depth + 1);
    }

    return minThreeNode(root, helpFindMin(root->getLeft(), select, depth + 1),
                        helpFindMin(root->getRight(), select, depth + 1),
                        select);
}

treeNode* KDTree::findMin(treeNode* root, int select) {
    return helpFindMin(root, select, 0);
}

treeNode* KDTree::helpDeleteNode(treeNode* root, Point p, int depth,
                                 bool* deleted) {

    if (root == NULL) return NULL;

    int cd = depth % 2;

    if (root->getPoint() == p) {

        if (root->getRight() != NULL) {

            treeNode* min = findMin(root->getRight(), cd);

            root->setNode(min->getNode());

            root->setRight(helpDeleteNode(root->getRight(), min->getPoint(),
                                          depth + 1, deleted));
        }

        else if (root->getLeft() != NULL) {

            treeNode* min = findMin(root->getLeft(), cd);

            root->setNode(min->getNode());

            root->setRight(helpDeleteNode(root->getLeft(), min->getPoint(),
                                          depth + 1, deleted));
        }

        else {
            delete root;
            return NULL;
        }

        // set the flag to deleted node of tree
        *deleted = true;
        // back
        return root;
    }

    // go to next depth and found p in next level
    int number_node, number_root;

    if (depth % 2 == 0) {
        number_node = p.getX();
        number_root = root->getPoint().getX();
    }

    else {
        number_node = p.getY();
        number_root = root->getPoint().getY();
    }

    if (number_node < number_root)
        root->setLeft(helpDeleteNode(root->getLeft(), p, depth + 1, deleted));
    else
        root->setRight(helpDeleteNode(root->getRight(), p, depth + 1, deleted));

    return root;
}

bool KDTree::deleteNode(Point p) {

    bool deleted = false;
    head = helpDeleteNode(head, p, 0, &deleted);

    return deleted;
}
