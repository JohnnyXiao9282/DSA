#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct ListNode {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;

        ListNode(int key, int value) {
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
 
    };

    ListNode* left;
    ListNode* right;
    std::unordered_map<int, ListNode*> cache;
    int capacity;

    void insert(ListNode* node) {
        ListNode* prev = this->right->prev;

        node->prev = prev;
        this->right->prev = node;

        prev->next = node;
        node->next = this->right;
    }

    void remove(ListNode* node) {
        ListNode* prev = node->prev;
        ListNode* next = node->next;

        prev->next = next;
        next->prev = prev;
    }



public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->left = new ListNode(-1, -1);
        this->right = new ListNode(-1, -1);
        this->left->next = this->right;
        this->right->prev = this->left;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        } else {
            ListNode* want = cache[key];
            int value = want->value;
            remove(want);
            insert(want);
            return value;

        }

    }

    void put(int key, int value) {
        if (cache.count(key)) {
            ListNode* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        } else {
            ListNode* node = new ListNode(key, value);
            cache[key] = node;
            insert(node);

            if (cache.size() > this->capacity) {
                ListNode* lru = this->left->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;  
            }
        }
    }




};

int main() {
    // Test 1: Basic put and get
    LRUCache cache1(2);
    cache1.put(1, 10);
    cache1.put(2, 20);
    std::cout << "get(1): " << cache1.get(1) << " (expected 10)" << std::endl;

    // Test 2: Eviction of LRU element
    // At this point, key 2 is LRU (key 1 was just accessed)
    cache1.put(3, 30); // should evict key 2
    std::cout << "get(2): " << cache1.get(2) << " (expected -1, evicted)" << std::endl;
    std::cout << "get(3): " << cache1.get(3) << " (expected 30)" << std::endl;

    // Test 3: Update existing key
    LRUCache cache2(2);
    cache2.put(1, 1);
    cache2.put(2, 2);
    cache2.put(1, 100); // update key 1, making key 2 the LRU
    cache2.put(3, 3);   // should evict key 2
    std::cout << "get(1): " << cache2.get(1) << " (expected 100)" << std::endl;
    std::cout << "get(2): " << cache2.get(2) << " (expected -1, evicted)" << std::endl;
    std::cout << "get(3): " << cache2.get(3) << " (expected 3)" << std::endl;

    return 0;
}