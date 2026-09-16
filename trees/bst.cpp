#include <iostream>
#include <vector>
#include "../common/TreeNode.h"

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
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

    TreeNode* remove(TreeNode* node, int value) {
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

int main() {
    BST bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(1);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);

    std::vector<int> result = bst.inorder();
    std::cout << "Inorder: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 1 3 4 5 7 8 9)" << std::endl;

    std::cout << "contains(7): " << bst.contains(7) << " (expected 1)" << std::endl;
    std::cout << "contains(10): " << bst.contains(10) << " (expected 0)" << std::endl;

    bst.remove(3);
    result = bst.inorder();
    std::cout << "After removing 3: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 1 4 5 7 8 9)" << std::endl;

    bst.remove(5);
    result = bst.inorder();
    std::cout << "After removing 5 (root): ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << "(expected 1 4 7 8 9)" << std::endl;

    return 0;
}
