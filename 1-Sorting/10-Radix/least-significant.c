#include "../../0-Test/sort-test.h"
#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../headers/stacklist.h"
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

    for (int i = 0; i < BASE; i++) {
        buckets[i] = NULL;
    }

    // OPTIONAL: Initialize storage
    for (int i = 0; i < size; i++) {
        // You can create a different function for allocating empty nodes, i was just lazy so im using a placeholder instead (-1)
        push(&storage, -1);
    }

    int max_num = arr[0];

    for (int i = 1; i < size; i++) {
        max_num = max(max_num, arr[i]);
    }

    int max_digits = log10(max_num) + 1;

    for (int i = 0; i < max_digits; i++) {
        int place = pow(BASE, i);

        for (int j = 0; j < size; j++) {
            int key = arr[j] / place % BASE;

            StackList temp = storage;
            storage = storage->next;

            insertSortedAscNoMalloc(buckets + key, arr[j], temp);
        }

        int arr_index = 0;
        for (int i = 0; i < BASE; i++) {
            StackList *trav = buckets + i;
            while ((*trav) != NULL) {
                StackList temp = *trav;
                *trav = temp->next;
                arr[arr_index++] = temp->data;

                // OPTIONAL: Return nodes to storage LL
                temp->next = storage;
                storage = temp;
            }
        }
    }
}