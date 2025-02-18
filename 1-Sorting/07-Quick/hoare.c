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

        // i starts before low for uniform code later on in the do while loop
        int i = low - 1;

        // j starts after high for uniform code later on in the do while loop
        int j = high + 1;

        // pivot value is kept temporarily for comparison
        int pivot = arr[low];

        // While i < j
        while (i < j) {

            // Continually increment i, then check if it is still lesser than pivot 
            do {
                i++;
            } while (arr[i] < pivot);

            // Continually decrement j, then check if it is still greater than pivot
            do {
                j--;
            } while (arr[j] > pivot);

            // If indices do not cross, swap
            if (i < j) {
                swap(arr + i, arr + j);
            }
        }

        // Recursively call left and right partitions
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}