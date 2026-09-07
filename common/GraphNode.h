#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>

struct GraphNode {
    int value;
    std::vector<GraphNode*> neighbors;

    GraphNode(int value) {
        this->value = value;
    }
};

#endif
