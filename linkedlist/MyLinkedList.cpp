#include <iostream>

class MyLinkedList {
private:
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

    ListNode* left;
    ListNode* right;
    int size;

    ListNode* getNode(int index) {
        if (index < 0 || index >= size) {
            return nullptr;
        }

        // Search from the closer side.
        if (index < size / 2) {
            ListNode* current = left->next;

            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            return current;
        } else {
            ListNode* current = right->prev;

            for (int i = size - 1; i > index; i--) {
                current = current->prev;
            }

            return current;
        }
    }

    void insertBefore(ListNode* next, int val) {
        ListNode* node = new ListNode(val);
        ListNode* prev = next->prev;

        prev->next = node;
        node->prev = prev;

        node->next = next;
        next->prev = node;

        size++;
    }

public:
    MyLinkedList() {
        left = new ListNode(-1);
        right = new ListNode(-1);

        left->next = right;
        right->prev = left;

        size = 0;
    }

    ~MyLinkedList() {
        ListNode* current = left;

        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int index) {
        ListNode* node = getNode(index);

        return node ? node->value : -1;
    }

    void addAtHead(int val) {
        insertBefore(left->next, val);
    }

    void addAtTail(int val) {
        insertBefore(right, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0) {
            index = 0;
        }

        if (index > size) {
            return;
        }

        if (index == size) {
            insertBefore(right, val);
            return;
        }

        ListNode* current = getNode(index);
        insertBefore(current, val);
    }

    void deleteAtIndex(int index) {
        ListNode* current = getNode(index);

        if (!current) {
            return;
        }

        ListNode* prev = current->prev;
        ListNode* next = current->next;

        prev->next = next;
        next->prev = prev;

        delete current;
        size--;
    }
};

void printList(MyLinkedList& list, int len) {
    std::cout << "[ ";
    for (int i = 0; i < len; i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    MyLinkedList list;

    list.addAtHead(1);        // [1]
    list.addAtTail(3);        // [1,3]
    list.addAtIndex(1, 2);    // [1,2,3]
    printList(list, 3);       // expect [ 1 2 3 ]

    std::cout << "get(1): " << list.get(1) << " (expected 2)" << std::endl;

    list.deleteAtIndex(1);    // [1,3]
    printList(list, 2);       // expect [ 1 3 ]

    std::cout << "get(1): " << list.get(1) << " (expected 3)" << std::endl;
    std::cout << "get(5): " << list.get(5) << " (expected -1, out of bounds)" << std::endl;

    list.addAtHead(0);        // [0,1,3]
    list.addAtTail(4);        // [0,1,3,4]
    printList(list, 4);       // expect [ 0 1 3 4 ]

    list.addAtIndex(2, 99);   // [0,1,99,3,4]
    printList(list, 5);       // expect [ 0 1 99 3 4 ]

    list.deleteAtIndex(0);    // [1,99,3,4]
    list.deleteAtIndex(3);    // [1,99,3]
    printList(list, 3);       // expect [ 1 99 3 ]

    return 0;
}