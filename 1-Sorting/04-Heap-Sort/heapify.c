#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/heap.h"

void heapSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    heapSort(arr, size);

    printf("Heap-sorted array: ");
    print(arr, size);

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