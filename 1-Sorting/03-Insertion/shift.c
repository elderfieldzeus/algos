#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../0-Test/sort-test.h"

void insertionSort(int arr[], int size);

int main() {
    test_sort_w_size(insertionSort);
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