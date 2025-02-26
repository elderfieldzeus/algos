#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/bucket.h"
#include "../../0-Test/sort-test.h"

void bucketSort(int arr[], int size);

int main() {
    test_sort_w_size(bucketSort);
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