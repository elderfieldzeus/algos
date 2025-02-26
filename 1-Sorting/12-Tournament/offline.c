#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/tournament.h"
#include "../../0-Test/sort-test.h"

void tournamentSort(int arr[], int size);

int main() {
    test_sort_w_size(tournamentSort);
    return 0;
}

void tournamentSort(int arr[], int size) {
    // Doesn't work if one element wahah!
    if (size <= 1) return;

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
        // Keep track of index of the minimum element
        int ndx = tree[0];

        // Delete-first, like a minheap
        arr[i] = tree[ndx];

        // This is considered "deleting" the element, replace it with a really BIG number
        tree[ndx] = INF;

        // Initialize parent-traversal
        int parent = ndx;
        
        // This is like heapify, but iterative
        // View '/12-Tournament/headers/tournament.h'
        resetTree(tree, tree_size, elem_start, parent);
    }
}