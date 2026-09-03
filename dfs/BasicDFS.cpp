#include <iostream>
#include <vector>
#include <unordered_set>

struct GraphNode {
    int value;
    std::vector<GraphNode*> neighbors;

    GraphNode(int value) {
        this->value = value;
    }
};

void dfs(GraphNode* node, std::unordered_set<GraphNode*>& visited) {
    // Base case: null or already visited
    if (!node || visited.count(node)) {
        return;
    }

    // Visit the node
    visited.insert(node);
    std::cout << node->value << " ";

    // Recurse into all unvisited neighbors
    for (GraphNode* neighbor : node->neighbors) {
        dfs(neighbor, visited);
    }
}

int main() {
    GraphNode* n1 = new GraphNode(1);
    GraphNode* n2 = new GraphNode(2);
    GraphNode* n3 = new GraphNode(3);
    GraphNode* n4 = new GraphNode(4);
    GraphNode* n5 = new GraphNode(5);
    // Graph should look like:
    //     1
    //    / \
    //   2   3
    //    \ /
    //     4
    //     |
    //     5

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n4);
    n3->neighbors.push_back(n1);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n2);
    n4->neighbors.push_back(n3);
    n4->neighbors.push_back(n5);
    n5->neighbors.push_back(n4);

    std::unordered_set<GraphNode*> visited;
    std::cout << "DFS from node 1: ";
    dfs(n1, visited);
    std::cout << std::endl;

    return 0;
}
