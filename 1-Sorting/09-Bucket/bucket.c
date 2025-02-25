#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/bucket.h"

void bucketSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    bucketSort(arr, size);

    printf("Bucket-sorted array: ");
    print(arr, size);

    return 0;
}

void bucketSort(int arr[], int size) {
    Buckets BS;
    initBuckets(BS);

    int min_elem = arr[0];
    int max_elem = arr[0];

    for (int i = 1; i < size; i++) {
        min_elem = min(min_elem, arr[i]);
        max_elem = max(max_elem, arr[i]);
    }

    int range = (max_elem - min_elem) / BUCKET_SIZE + 1;

    for (int i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min_elem) / range;

        insertSorted(BS + bucket_index, arr[i]);
    }

    int arr_index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        
        while (BS[i] != NULL) {
            Bucket temp = BS[i];
            BS[i] = temp->next;

            arr[arr_index++] = temp->data;
            free(temp);
        }
    }
}