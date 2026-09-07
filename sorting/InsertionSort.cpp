#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& array) {
    int size = array.size();

    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
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
    insertionSort(v1);
    printVector(v1);

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    insertionSort(v2);
    printVector(v2);

    std::vector<int> v3 = {5, 4, 3, 2, 1};
    insertionSort(v3);
    printVector(v3);

    std::vector<int> v4 = {42};
    insertionSort(v4);
    printVector(v4);

    return 0;
}
