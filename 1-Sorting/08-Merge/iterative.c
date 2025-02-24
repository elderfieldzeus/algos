#include "../../headers/general.h"
#include "../../headers/arrays.h"

void mergeSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    mergeSort(arr, size);

    printf("Merge-sorted array: ");
    print(arr, size);

    return 0;
}

void mergeSort(int arr[], int size) {
    // Keep doubling the gap until it is greater than or equal to size
    for (int gap = 1; gap < size; gap *= 2) {

        // Calculate end to avoid continually calculating in the for loop
        int end = size - gap;
        
        // i here will be used for the starting index of the two sorted subarrays
        for (int i = 0; i < end; i += (gap * 2)) {

            // Set size of left partition
            int l_size = gap;

            // Set size of right partition, if partition size is less than gap, utilize that 
            int r_size = min(gap, size - (gap + i));


            // Create left and right temporary arrays
            int left[l_size];
            int right[r_size];

            // Copy partitions respectively
            memcpy(left, arr + i, sizeof(int) * l_size);
            memcpy(right, arr + i + gap, sizeof(int) * r_size);

            // Create their respective indices
            int l_index = 0;
            int r_index = 0;
            int arr_index = i;

            // Merge sorted arrays
            while (l_index < l_size && r_index < r_size) {
                if (right[r_index] < left[l_index]) {
                    arr[arr_index++] = right[r_index++];
                }
                else {
                    arr[arr_index++] = left[l_index++];
                }
            }

            // Copy remaining elements if still lesser than respective size
            while (l_index < l_size) {
                arr[arr_index++] = left[l_index++];
            }

            // Copy remaining elements if still lesser than respective size
            while (r_index < r_size) {
                arr[arr_index++] = right[r_index++];
            }
        }

        printf("GAP %d: ", gap);
        print(arr, size);
    }
}