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