#include "../../../headers/general.h"

#ifndef HEAP_H
#define HEAP_H

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

void insertMax(int arr[], int *size, int max, int data) {
    if(*size < max) {
        int child = (*size)++;
        int parent = (child - 1) / 2;

        while(child > 0 && arr[parent] < data) {
            arr[child] = arr[parent];

            child = parent;
            parent = (parent - 1) / 2;
        }

        arr[child] = data;
    }
}

int deleteMax(int arr[], int *size) {
    int temp = -1;

    if(*size > 0) {
        temp = arr[0];

        (*size)--;

        swap(arr, arr + (*size));
        maxHeapify(arr, (*size), 0);
    }

    return temp;
}

#endif