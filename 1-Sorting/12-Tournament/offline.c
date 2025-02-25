#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/tournament.h"

void tournamentSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    tournamentSort(arr, size);

    printf("Insertion-sorted array: ");
    print(arr, size);

    return 0;
}

void tournamentSort(int arr[], int size) {
    // Set tree size
    int tree_size = size * 2 - 1;

    // Keep track of when indices start to point to actual elements
    int elem_start = tree_size - size;

    // Create temporary heap
    int tree[tree_size];

    // Place elements at the leaves of the heap
    for (int i = 0; i < size; i++) {
        tree[elem_start + i] = arr[i];
    }

    // Initialize tree, start from lowest-level parent and work upwards
    // View '/12-Tournament/headers/tournament.h'
    initTree(tree, tree_size, elem_start);

    // This is the start of tournament sort
    for (int i = 0; i < size; i++) {

        // Delete-first, like a minheap
        arr[i] = tree[tree[0]];

        // This is considered "deleting" the element, replace it with a really BIG number
        tree[tree[0]] = INF;

        // Initialize parent-traversal
        int parent = tree[0];
        
        // This is like heapify, but iterative
        // View '/12-Tournament/headers/tournament.h'
        resetTree(tree, elem_start, parent);
    }
}