#include "../../0-Test/sort-test.h"
#include "../../headers/general.h"
#include "../../headers/arrays.h"

void selectionSort(int arr[], int size);

int main() {
    test_sort_w_size(selectionSort);
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