#include "../../headers/general.h"
#include "../../headers/arrays.h"

void quickSort(int arr[], int low, int high);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Quick-sorted array: ");
    print(arr, size);

    return 0;
}

void quickSort(int arr[], int low, int high) {
    // If low is equal to or greater than high then return early
    if (low < high) {

        // i is one step behind low
        int i = low - 1;

        // j is equal to low, this will be our main trav variable
        int j = low;

        // pivot is stored for comparison purposes
        int pivot = arr[high];

        // Swap elements so that lighter elements are to the left, and heavier elements are to the right
        for (; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr + (++i), arr + j);
            }
        }

        // Put pivot value into proper position
        swap(arr + (++i), arr + high);

        // Recursively call quick sort on the lighter and heavier partitions
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}