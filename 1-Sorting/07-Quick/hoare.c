#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../0-Test/sort-test.h"

void quickSort(int arr[], int low, int high);

int main() {
    test_sort_w_low_high(quickSort);
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