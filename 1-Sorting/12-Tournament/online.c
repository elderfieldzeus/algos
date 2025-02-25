#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/tournament.h"
#include "./headers/stacklist.h"

void tournamentSort(int arr[], int size, int tree_size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    tournamentSort(arr, size, 7);

    printf("Insertion-sorted array: ");
    print(arr, size);

    return 0;
}

// NOTE: U can use K-merge, but you would need a collection/array/linked list of linked lists 
void tournamentSort(int arr[], int size, int tree_size) {
    // LOL
    if (tree_size <= 0) return;

    // Initialize tree
    int tree[tree_size];

    // Initialize output and buffer linkedlists
    StackList output = NULL;
    StackList buffer = NULL;

    // Keep track of current arr_index
    int arr_index = 0;

    // Number of elements that can fit in the heap at once
    int num_elems = (tree_size + 1) / 2;

    // Keep track of when indices start to point to actual elements
    int elem_start = tree_size - num_elems;

    // Place elements at the leaves of the heap
    while (arr_index < num_elems) {
        tree[elem_start + arr_index] = arr[arr_index];
        arr_index++;
    }

    // Initialize tree, start from lowest-level parent and work upwards
    // View '/12-Tournament/headers/tournament.h'
    initTree(tree, tree_size, elem_start);

    // This is the start of tournament sort
    for (int i = 0; i < size; i++) {
        // Delete-first, like a minheap
        int ndx = tree[0];
        push(&buffer, tree[ndx]);

        // This is considered "deleting" the element, replace it with the next element in the array OR a really BIG number if no more elements left.
        tree[ndx] = (arr_index < size) ? arr[arr_index++] : INF;

        // Initialize parent-traversal
        int parent = tree[0];
        
        // This is like heapify, but iterative
        // View '/12-Tournament/headers/tournament.h'
        resetTree(tree, elem_start, parent);

        if (tree[tree[0]] < top(buffer)) {
            // View '/12-Tournament/headers/tournament.h'
            output = mergeDescending(output, buffer);
            buffer = NULL;
        }
    }

    // Merge output and buffer for the last time
    // View '/12-Tournament/headers/stacklist.h'
    output = mergeDescending(output, buffer);

    // Since I used a descending stack, we will place elements back to the array starting from the end
    while (output != NULL) {
        arr[--arr_index] = top(output);
        pop(&output);
    }
}