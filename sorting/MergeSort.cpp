#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    std::vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

void mergeSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void printVector(const std::vector<int>& arr) {
    for (int n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1 = {5, 3, 8, 1, 9, 2};
    mergeSort(v1, 0, v1.size() - 1);
    printVector(v1);

    std::vector<int> v2 = {1, 2, 3, 4, 5};
    mergeSort(v2, 0, v2.size() - 1);
    printVector(v2);

    std::vector<int> v3 = {5, 4, 3, 2, 1};
    mergeSort(v3, 0, v3.size() - 1);
    printVector(v3);

    std::vector<int> v4 = {42};
    mergeSort(v4, 0, v4.size() - 1);
    printVector(v4);

    return 0;
}
