#include "../../headers/general.h"
#include "../../headers/arrays.h"

void combSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    combSort(arr, size);

    printf("Comb-sorted array: ");
    print(arr, size);

    return 0;
}

void combSort(int arr[], int size) {
    // Flag variable is NEEDED because without it the outer loop ends early
    bool sorted = false;
    
    // Continually shrink gap until array is sorted
    for (int gap = size / 1.3; gap > 1 || !sorted; gap /= 1.3) {
        
        // The gap is rounded up to 1 when lesser than 1
        if (gap < 1) {
            gap = 1;
        }
        
        // Set sorted flag to true to determine whether the outer loop should keep going or not
        sorted = true;

        // Bubble sort but with a bigger gap
        for (int i = gap; i < size; i++) {
            if (arr[i - gap] > arr[i]) {
                swap(arr + i, arr + i - gap);
                sorted = false;
            }
        }
    }
}