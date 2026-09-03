#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
    int value;
    ListNode* prev;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

#endif
