#include "../../headers/general.h"
#include "../../headers/arrays.h"

void selectionSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    selectionSort(arr, size);

    printf("Selection-sorted array: ");
    print(arr, size);

    return 0;
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int smallest = i;

        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }

        if(smallest != i) {
            swap(arr + i, arr + smallest);
        }
    }
}