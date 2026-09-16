#include <iostream>
#include <vector>
#include <algorithm>
#include "../common/TreeNode.h"
#include "bst.h"

class AVL : public BST {
private:
    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    void updateHeight(TreeNode* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    int balanceFactor(TreeNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    TreeNode* rotateRight(TreeNode* node) {
        TreeNode* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    TreeNode* rotateLeft(TreeNode* node) {
        TreeNode* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    TreeNode* rebalance(TreeNode* node) {
        updateHeight(node);
        int balance = balanceFactor(node);

        // Left heavy
        if (balance > 1) {
            if (balanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        // Right heavy
        if (balance < -1) {
            if (balanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

protected:
    TreeNode* insert(TreeNode* node, int value) override {
        node = BST::insert(node, value);
        return rebalance(node);
    }

    TreeNode* remove(TreeNode* node, int value) override {
        node = BST::remove(node, value);
        if (!node) {
            return nullptr;
        }
        return rebalance(node);
    }

public:
    using BST::insert;
    using BST::remove;
};

int main() {
    AVL avl;

    avl.insert(5);
    avl.insert(3);
    avl.insert(8);
    avl.insert(1);
    avl.insert(4);
    avl.insert(7);
    avl.insert(9);
    avl.insert(0);
    avl.insert(2);

    std::vector<int> result = avl.inorder();
    std::cout << "Inorder: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 0 1 2 3 4 5 7 8 9)" << std::endl;

    std::cout << "contains(7): " << avl.contains(7) << " (expected 1)" << std::endl;
    std::cout << "contains(10): " << avl.contains(10) << " (expected 0)" << std::endl;

    avl.remove(3);
    result = avl.inorder();
    std::cout << "After removing 3: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 0 1 2 4 5 7 8 9)" << std::endl;

    avl.remove(5);
    result = avl.inorder();
    std::cout << "After removing 5 (root): ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 0 1 2 4 7 8 9)" << std::endl;

    // Force left-left rotation
    AVL avl2;
    avl2.insert(30);
    avl2.insert(20);
    avl2.insert(10);
    result = avl2.inorder();
    std::cout << "Left-left rotation inorder: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 10 20 30)" << std::endl;

    // Force right-right rotation
    AVL avl3;
    avl3.insert(10);
    avl3.insert(20);
    avl3.insert(30);
    result = avl3.inorder();
    std::cout << "Right-right rotation inorder: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 10 20 30)" << std::endl;

    return 0;
}
