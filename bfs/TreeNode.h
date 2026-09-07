#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

#endif
