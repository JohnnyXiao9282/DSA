#ifndef BST_H
#define BST_H

#include <vector>
#include "../common/TreeNode.h"

class BST {
protected:
    TreeNode* root;

    virtual TreeNode* insert(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    TreeNode* find(TreeNode* node, int value) {
        if (!node || node->value == value) {
            return node;
        }

        if (value < node->value) {
            return find(node->left, value);
        }

        return find(node->right, value);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    virtual TreeNode* remove(TreeNode* node, int value) {
        if (!node) {
            return nullptr;
        }

        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            if (!node->left) {
                TreeNode* right = node->right;
                delete node;
                return right;
            }

            if (!node->right) {
                TreeNode* left = node->left;
                delete node;
                return left;
            }

            TreeNode* successor = findMin(node->right);
            node->value = successor->value;
            node->right = remove(node->right, successor->value);
        }

        return node;
    }

    void inorder(TreeNode* node, std::vector<int>& result) {
        if (!node) {
            return;
        }

        inorder(node->left, result);
        result.push_back(node->value);
        inorder(node->right, result);
    }

public:
    BST() {
        root = nullptr;
    }

    virtual ~BST() {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) {
        return find(root, value) != nullptr;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    std::vector<int> inorder() {
        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};

#endif
