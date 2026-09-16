#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
    int value;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->value = value;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

#endif
