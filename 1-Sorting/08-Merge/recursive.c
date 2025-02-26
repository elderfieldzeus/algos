#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../0-Test/sort-test.h"

void mergeSort(int arr[], int low, int high);

int main() {
    test_sort_w_low_high(mergeSort);
    return 0;
}

void mergeSort(int arr[], int low, int high) {
    // If low is equal to or greater than high then return early
    if (low < high) {
        // Partition into left and right
        int partition = (high + low) / 2;

        // Recursively call merge sort on left and right partitions
        mergeSort(arr, low, partition);
        mergeSort(arr, partition + 1, high);
        
        // Calculate sizes of left and right partitions
        int left_size = partition - low + 1;
        int right_size = high - (partition + 1) + 1;

        // Create two temporary arrays to store these partitions
        int left[left_size];
        int right[right_size];

        // Copy elements into left and right
        memcpy(left, arr + low, left_size * sizeof(int));
        memcpy(right, arr + partition + 1, right_size * sizeof(int));

        // Create separate indices to keep track 
        int l_index = 0;
        int r_index = 0;
        int arr_index = low;

        // Merge sorted arrays
        while (l_index < left_size && r_index < right_size) {
            if (right[r_index] < left[l_index]) {
                arr[arr_index++] = right[r_index++];
            }
            else {
                arr[arr_index++] = left[l_index++];
            }
        }

        // Copy remaining elements if still lesser than respective size
        while (l_index < left_size) {
            arr[arr_index++] = left[l_index++];
        }

        // Copy remaining elements if still lesser than respective size
        while (r_index < right_size) {
            arr[arr_index++] = right[r_index++];
        }
    }
}