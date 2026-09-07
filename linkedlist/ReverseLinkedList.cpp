#include <iostream>
#include "ListNode.h"

ListNode* reverse(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    std::cout << "Before: ";
    ListNode* current = n1;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode* newHead = reverse(n1);

    std::cout << "After:  ";
    current = newHead;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}