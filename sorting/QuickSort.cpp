#include <iostream>
#include <vector>

void sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = left + (right - left) / 2;
    std::swap(arr[pivot], arr[right]);

    int store = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < arr[right]) {
            std::swap(arr[store++], arr[i]);
        }
    }

    std::swap(arr[right], arr[store]);
    sort(arr, left, store - 1);
    sort(arr, store + 1, right);
}

void quickSort(std::vector<int>& arr) {
    if (arr.size() < 2) {
        return;
    }

    sort(arr, 0, arr.size() - 1);
}

void printVector(const std::vector<int>& arr) {
    for (int n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1 = {5, 3, 8, 1, 9, 2};
    quickSort(v1);
    printVector(v1);

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    quickSort(v2);
    printVector(v2);

    std::vector<int> v3 = {5, 4, 3, 2, 1};
    quickSort(v3);
    printVector(v3);

    std::vector<int> v4 = {42};
    quickSort(v4);
    printVector(v4);

    return 0;
}
