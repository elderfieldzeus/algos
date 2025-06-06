#include "../../0-Test/sort-test.h"

void bubbleSort(int arr[], int size);

int main() {
    test_sort_w_size(bubbleSort);
    return 0;
}

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = size - 1; j > i; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(arr + j, arr + j - 1);
            }
        }
    }
}