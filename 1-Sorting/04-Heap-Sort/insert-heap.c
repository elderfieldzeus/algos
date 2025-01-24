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
    if(size > 0) {
        int heap[size];
        int heap_size = 0;

        for(int i = 0; i < size; i++) {
            insertMax(heap, &heap_size, size, arr[i]);
        }

        for(int i = size - 1; i >= 0; i--) {
            arr[i] = deleteMax(heap, &heap_size);
        }
    }
}