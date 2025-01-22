#include "../../headers/general.h"
#include "../../headers/arrays.h"

void maxHeapify(int arr[], int size, int parent);
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

void maxHeapify(int arr[], int size, int parent) {
    int largest = parent;
    int left_child = largest * 2 + 1;
    int right_child = largest * 2 + 2;

    if(left_child < size && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    if(right_child < size && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    if(largest != parent) {
        swap(arr + largest, arr + parent);
        maxHeapify(arr, size, largest);
    }
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