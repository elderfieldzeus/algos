#include "../../0-Test/sort-test.h"
#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../headers/stacklist.h"
#include "../../0-Test/sort-test.h"
#define BASE 10 // base 10

void radixSort(int arr[], int size);

int main() {
    cls();
    test_sort_w_size(radixSort);
    return 0;
}

void radixSort(int arr[], int size) {
    StackList buckets[BASE];

    // OPTIONAL: Store linkedlist in storage so u dont need to free everytime
    // This is like Cursor Based
    StackList storage = NULL;

    // Initialize buckets
    for (int i = 0; i < BASE; i++) {
        buckets[i] = NULL;
    }

    // OPTIONAL: Initialize storage
    for (int i = 0; i < size; i++) {
        // You can create a different function for allocating empty nodes, i was just lazy so im using a placeholder instead (-1)
        push(&storage, -1);
    }

    // Find max number
    int max_num = arr[0];

    for (int i = 1; i < size; i++) {
        max_num = max(max_num, arr[i]);
    }

    // Find number of digits for max number
    int max_digits = log10(max_num) + 1;

    // Radix sort
    for (int i = 0; i < max_digits; i++) {
        // Find current place (1, 10, 100,...)
        int place = pow(BASE, i);

        for (int j = 0; j < size; j++) {
            // Find index of bucket (This is the formula for getting the digit)
            int key = arr[j] / place % BASE;

            // Get node from storage
            StackList temp = storage;
            storage = storage->next;

            // Insert Sorted
            insertSortedAscNoMalloc(buckets + key, arr[j], temp);
        }

        int arr_index = 0;
        for (int i = 0; i < BASE; i++) {
            StackList *trav = buckets + i;

            while ((*trav) != NULL) {
                // Store the head of the bucket
                StackList temp = *trav;
                
                // Remove node from bucket
                *trav = temp->next;

                // Return data from bucket to array
                arr[arr_index++] = temp->data;

                // OPTIONAL: Return nodes to storage LL
                temp->next = storage;
                storage = temp;
            }
        }
    }
}