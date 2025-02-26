#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/heap.h"
#include "../../0-Test/sort-test.h"

void heapSort(int arr[], int size);

int main() {
    test_sort_w_size(heapSort);
    return 0;
}

void heapSort(int arr[], int size) {
    int last_index = size - 1;
    int lowest_parent = (last_index - 1) / 2;

    for(int i = lowest_parent; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }

    while(last_index > 0) {
        swap(arr, arr + last_index);
        maxHeapify(arr, last_index--, 0);
    }
}