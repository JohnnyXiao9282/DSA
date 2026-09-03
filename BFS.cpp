#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


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