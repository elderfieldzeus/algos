#include "../../headers/general.h"
#include "../../headers/arrays.h"

void bubbleSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    bubbleSort(arr, size);

    printf("Bubble-sorted array: ");
    print(arr, size);

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