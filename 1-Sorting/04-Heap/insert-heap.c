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