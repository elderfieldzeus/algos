#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../0-Test/sort-test.h"

void shellSort(int arr[], int size);

int main() {
    test_sort_w_size(shellSort);
    return 0;
}

void shellSort(int arr[], int size) {
    // Start with a gap of half the size of the array and continually divide by 2
    for (int gap = size / 2; gap > 0; gap /= 2) {

        // Start at current gap and keep incrementing until it reaches size
        for (int i = gap; i < size; i++) {
            
            // Store temporary variable to be shifted into a better position
            int temp = arr[i], j;

            // Continualy shift by gap until element is lesser than or equal to temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // If j is not equal to i, then place temp in new position
            if (j != i) {
                arr[j] = temp;
            } 
        }
    }
}