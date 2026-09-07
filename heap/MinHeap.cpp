#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void percolateDown(std::vector<int>& array, int index) {
        int size = array.size();
        if (size == 0) {
            return;
        }

        while (index <= size / 2 - 1) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int candidate = left;

            if (right < size && array[right] < array[left]) {
                candidate = right;
            }

            if (array[index] > array[candidate]) {
                std::swap(array[index], array[candidate]);
            } else {
                break;
            }
            index = candidate;
        }
    }

    std::vector<int> heapify(std::vector<int> array) {
        int size = array.size();

        if (size == 0) {
            return array;
        }

        // To have children, we have 2i + 1 <= size - 1 which is the same as i <= size / 2 - 1
        for (int i = size / 2 - 1; i >= 0; i--) {
            percolateDown(array, i);
        }

        return array;
    }

public:
    MinHeap(std::vector<int> array) {
        heap = heapify(array);
    }

    int top() {
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void pop() {
        if (heap.empty()) {
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            percolateDown(heap, 0);
        }
    }
};

int main() {
    std::vector<int> v1 = {5, 3, 8, 1, 9, 2};
    MinHeap heap1(v1);

    std::cout << "top(): " << heap1.top() << " (expected 1)" << std::endl;

    std::cout << "Popping all: ";
    while (!heap1.empty()) {
        std::cout << heap1.top() << " ";
        heap1.pop();
    }
    std::cout << "(expected 1 2 3 5 8 9)" << std::endl;

    std::vector<int> v2 = {42};
    MinHeap heap2(v2);
    std::cout << "single element top(): " << heap2.top() << " (expected 42)" << std::endl;

    std::vector<int> v3;
    MinHeap heap3(v3);
    std::cout << "empty heap empty(): " << heap3.empty() << " (expected 1)" << std::endl;

    return 0;
}
