
#include "kdTree.h"

// treeNode functions
treeNode::treeNode(branch* node) {
    this->node = node;
    left = NULL;
    right = NULL;
    right_depth = 0;
    left_depth = 0;
}

treeNode::treeNode(treeNode& tmp) {
    node = tmp.node;
    left = tmp.left;
    right = tmp.right;
    right_depth = tmp.right_depth;
    left_depth = tmp.left_depth;
}

void treeNode::add1LeftDepth() { left_depth += 1; }

void treeNode::add1RightDepth() { right_depth += 1; }

void treeNode::setLeftDepth(int left) { left_depth = left; }

void treeNode::setRightDepth(int right) { right_depth = right; }

int treeNode::getLeftDepth() { return left_depth; }

int treeNode::getRightDepth() { return right_depth; }

bool treeNode::isBalanced() {
    int x = left_depth - right_depth;

    // log2("treeNode::isBalanced()",
        //  to_string(x) + ", " + this->getPoint().getStr());

    if (x >= -1 && x <= 1) return true;

    return false;
}

Point treeNode::getPoint() { return node->getPoint(); }

treeNode* treeNode::getLeft() { return left; }

treeNode* treeNode::getRight() { return right; }

void treeNode::setLeft(treeNode* left) { this->left = left; }

void treeNode::setRight(treeNode* right) { this->right = right; }

branch* treeNode::getNode() { return node; }

void treeNode::setNode(branch* node) { this->node = node; }

// KDTree functions
KDTree::KDTree() {
    head = NULL;
    needReBuild = false;

    // log2("KDTree::KDTree()", "create a new tree");
}

void KDTree::insertInVecX(treeNode* x) {

    // log2("KDTree::insertInVecX", x->getPoint().getStr());
    vec_sort_X.push_back(x);
}

treeNode* KDTree::helpInsert(treeNode* root, branch* node, int depth) {

    if (root == NULL) {
        treeNode* new_node = new treeNode(node);
        insertInVecX(new_node);
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

    if (number_node < number_root) {
        root->add1LeftDepth();
        if (!root->isBalanced()) needReBuild = true;
        root->setLeft(helpInsert(root->getLeft(), node, depth + 1));
    }

    else {
        root->add1RightDepth();
        if (!root->isBalanced()) needReBuild = true;
        root->setRight(helpInsert(root->getRight(), node, depth + 1));
    }

    return root;
}

bool KDTree::insert(branch* node) {

    if (search(node)) {
        return false;
    }

    head = helpInsert(head, node, 0);

    if (needReBuild) {
        // log2("KDTree::insert()", "need reBuild");
        reBuild();
        needReBuild = false;
    }

    return true;
}

void KDTree::helpMergeSort(vector<treeNode*>* arr, int left, int mid, int right,
                           int select) {

    int leftLen = mid - left + 1;
    int rightLen = right - mid;

    vector<treeNode*> leftVec(leftLen);
    vector<treeNode*> rightVec(rightLen);

    for (int i = 0; i < leftLen; i++) leftVec[i] = (*arr)[left + i];
    for (int j = 0; j < rightLen; j++) rightVec[j] = (*arr)[mid + 1 + j];

    auto I_ofLeft = 0, I_ofRight = 0;
    int insertMaster = left;

    while (I_ofLeft < leftLen && I_ofRight < rightLen) {

        if (select == 0) {
            if (leftVec[I_ofLeft]->getPoint().getX() <=
                rightVec[I_ofRight]->getPoint().getX()) {

                (*arr)[insertMaster] = leftVec[I_ofLeft];
                I_ofLeft++;
            }

            else {
                (*arr)[insertMaster] = rightVec[I_ofRight];
                I_ofRight++;
            }
        }

        // Y
        else {
            if (leftVec[I_ofLeft]->getPoint().getY() <=
                rightVec[I_ofRight]->getPoint().getY()) {

                (*arr)[insertMaster] = leftVec[I_ofLeft];
                I_ofLeft++;
            }

            else {
                (*arr)[insertMaster] = rightVec[I_ofRight];
                I_ofRight++;
            }
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

void KDTree::mergeSort(vector<treeNode*>* arr, int left, int right,
                       int select) {

    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, select);
    mergeSort(arr, mid + 1, right, select);
    helpMergeSort(arr, left, mid, right, select);
}

void KDTree::reBuild() {

    // log2("KDTree::reBuild()", "start");

    mergeSort(&vec_sort_X, 0, vec_sort_X.size() - 1, 0);  // sorted By X

    for (auto i : vec_sort_X)
        // log2("KDTree::reBuild() - for ", (*i).getPoint().getStr());

    head = helpReBuild(vec_sort_X, 0);
}

treeNode* KDTree::helpReBuild(vector<treeNode*> v, int depth) {

    // log3("KDTree::helpReBuild()", to_string(v.size()), to_string(depth));

    if (v.size() == 0) return NULL;

    int mid = (v.size()) / 2;

    int s_tmp = 0;
    int m_tmp = mid + 1;
    int end = v.size() - 1;
    vector<treeNode*> v_left;
    vector<treeNode*> v_right;

    bool ender1 = false;
    bool ender2 = false;

    while (!ender1 || !ender2) {

        if (s_tmp <= mid - 1) {
            v_left.push_back(v[s_tmp]);
            s_tmp++;
        } else {
            ender1 = true;
        }

        if (m_tmp <= end) {
            v_right.push_back(v[m_tmp]);
            m_tmp++;
        } else {
            ender2 = true;
        }
    }

    // log2("KDTree::helpReBuild() - while", "while Ended");

    if ((depth + 1) % 2 != 0) {
        mergeSort(&v_left, 0, v_left.size() - 1, 1);
        mergeSort(&v_right, 0, v_right.size() - 1, 1);
    }

    else {
        mergeSort(&v_left, 0, v_left.size() - 1, 0);
        mergeSort(&v_right, 0, v_right.size() - 1, 0);
    }

    // set the left node
    treeNode* tmp = helpReBuild(v_left, depth + 1);

    if (tmp == NULL)
        v[mid]->setLeftDepth(-1);
    else
        v[mid]->setLeftDepth(tmp->getLeftDepth());

    (v[mid])->setLeft(tmp);

    // set the right node
    tmp = helpReBuild(v_right, depth + 1);

    if (tmp == NULL)
        v[mid]->setRightDepth(-1);
    else
        v[mid]->setRightDepth(tmp->getRightDepth());

    (v[mid])->setRight(tmp);

    return v[mid];
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

    if (depth % 2 == 0) {  // check with X point
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

    // x -> cd == 0, else: y -> cd == 1
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

void KDTree::helpSearchArea(treeNode* root, vector<branch*>* vec, int depth,
                            int max_x, int min_x, int max_y, int min_y) {

    if (root == NULL) return;

    int root_x = root->getPoint().getX();
    int root_y = root->getPoint().getY();

    if (root_x >= min_x && root_x <= max_x && root_y >= min_y &&
        root_y <= max_y) {

        vec->push_back(root->getNode());
    }

    if (depth % 2 == 0) {
        if (root_x > max_x) {
            helpSearchArea(root->getLeft(), vec, depth, max_x, min_x, max_y,
                           min_y);
        }

        else if (root_x < min_x) {
            helpSearchArea(root->getRight(), vec, depth, max_x, min_x, max_y,
                           min_y);
        }

        // if (root_x >= min_x && root_x <= max_x)
        else {
            helpSearchArea(root->getLeft(), vec, depth, max_x, min_x, max_y,
                           min_y);
            helpSearchArea(root->getRight(), vec, depth, max_x, min_x, max_y,
                           min_y);
        }
    }

    else {
        if (root_y > max_y) {
            helpSearchArea(root->getLeft(), vec, depth, max_x, min_x, max_y,
                           min_y);
        }

        else if (root_y < min_y) {
            helpSearchArea(root->getRight(), vec, depth, max_x, min_x, max_y,
                           min_y);
        }

        // if (root_y >= min_y && root_y <= max_y)
        else {
            helpSearchArea(root->getLeft(), vec, depth, max_x, min_x, max_y,
                           min_y);
            helpSearchArea(root->getRight(), vec, depth, max_x, min_x, max_y,
                           min_y);
        }
    }
}

vector<branch*> KDTree::searchArea(Area* a) {
    vector<branch*> vec;
    helpSearchArea(head, &vec, 0, a->getMaxX(), a->getMinX(), a->getMaxY(),
                   a->getMinY());

    return vec;
}

int KDTree::checkOtherBr(Point t, treeNode* root, treeNode* near, int depth) {
    
    int distance = t.getDistance(root->getPoint());

    if (depth % 2 == 0){
        if (pow(root->getPoint().getX() - t.getX(), 2) < distance) return 1;
        else return 0; 
    }
    else {
        if (pow(root->getPoint().getY() - t.getY(), 2) < distance) return 1;
        else return 0; 
    }
    return 0;
}

treeNode* KDTree::helpFindNearstBranch(Point t, treeNode* root, treeNode* near, int depth){
    
    if(root==NULL){
        return near;
    }    
    
    if (near->getPoint().getDistance(t) > root->getPoint().getDistance(t) || near == NULL){
        near = root;
    }

    treeNode* new_br;
    treeNode* other_br;

    if(depth % 2 == 0){
        
        if(t.getX() < root->getPoint().getX()){
            new_br = root->getLeft();
            other_br = root->getRight();
        }
        
        else{
            new_br = root->getRight();
            other_br = root->getLeft();
        }

    }
    else if(depth % 2 == 1){
        
        if(t.getY() < root->getPoint().getY()){
            new_br = root->getLeft();
            other_br = root->getRight();
        }
        
        else{
            new_br = root->getRight();
            other_br = root->getLeft();
        }
    }

    near = helpFindNearstBranch(t, new_br, near, ++depth);

    if(checkOtherBr(t, new_br, near, depth)){ 
        near = helpFindNearstBranch(t, other_br, near, ++depth);
    }
    return near;
}

branch* KDTree::findNearstBranch(Point t){
    return helpFindNearstBranch(t, head, NULL, 0)->getNode();
}
