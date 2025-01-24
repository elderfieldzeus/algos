#include "../../headers/general.h"
#include "../../headers/arrays.h"

void insertionSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    insertionSort(arr, size);

    printf("Insertion-sorted array: ");
    print(arr, size);

    return 0;
}

void insertionSort(int arr[], int size) {
    for(int i = 1, j; i < size; i++) {
        int temp = arr[i];
        
        for(j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }

        if(j != i) {
            arr[j] = temp;
        }
    }
}