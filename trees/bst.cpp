#include <iostream>
#include <vector>
#include "bst.h"

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
