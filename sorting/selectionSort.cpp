#include <iostream>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int>& array) {
    int size = array.size();

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}

void printVector(const std::vector<int>& arr) {
    for (int n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1 = {5, 3, 8, 1, 9, 2};
    selectionSort(v1);
    printVector(v1);

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    selectionSort(v2);
    printVector(v2);

    std::vector<int> v3 = {5, 4, 3, 2, 1};
    selectionSort(v3);
    printVector(v3);

    std::vector<int> v4 = {42};
    selectionSort(v4);
    printVector(v4);

    return 0;
}