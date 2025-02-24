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
    for (int i = (tree_size - 2) / 2; i >= 0; i--) {

        // Initiate left_trav, this will store the index of the current min of that subtree
        int left_trav = i * 2 + 1;

        // Initiate right_trav, this will store the index of the current min of that subtree
        int right_trav = i * 2 + 2;

        // If left_trav is currently not storing an index of an element, this means its child is not an element. So we STEAL the index from its child.
        if (left_trav < elem_start) {
            left_trav = tree[left_trav];
        }

        // If right_trav is currently not storing an index of an element, this means its child is not an element. So we STEAL the index from its child.
        if (right_trav < elem_start) {
            right_trav = tree[right_trav];
        }

        // Compare elements and store the index of the minimum element
        tree[i] = (tree[right_trav] < tree[left_trav]) ? right_trav : left_trav;
    }

    // This is the start of tournament sort
    for (int i = 0; i < size; i++) {

        // Delete-first, like a minheap
        arr[i] = tree[tree[0]];

        // This is considered "deleting" the element, replace it with a really BIG number
        tree[tree[0]] = INF;

        // Initialize parent-traversal
        int parent = tree[0];
        
        // This is like heapify, but iterative
        while (parent > 0) {
            
            // Traverse first to get the element's current parent
            parent = (parent - 1) / 2;
            
            // Same as earlier, let the trav store the min element index of that subtree
            int left_trav = parent * 2 + 1;
            int right_trav = left_trav + 1;

            if (left_trav < elem_start) {
                left_trav = tree[left_trav];
            }
    
            if (right_trav < elem_start) {
                right_trav = tree[right_trav];
            }

            // Also same as earlier, let the parent now point to the index of the lesser element.
            tree[parent] = (tree[right_trav] < tree[left_trav]) ? right_trav : left_trav;
        }
    }
}