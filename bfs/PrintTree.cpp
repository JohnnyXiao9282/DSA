#include <iostream>
#include <vector>
#include <queue>
#include "../common/TreeNode.h"

class BFS {
public:
    std::vector<int> printTree(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<int> result;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                result.push_back(current->value);

                if (current->left) {
                    q.push(current->left);
                }

                if (current->right) {
                    q.push(current->right);
                }
            }
        }

        return result;
    }
};

int main() {
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    BFS bfs;
    std::vector<int> result = bfs.printTree(root);

    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
