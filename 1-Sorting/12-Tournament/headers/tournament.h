#include "../../../headers/general.h"

#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#define INF 99999


void initTree(int tree[], int tree_size, int elem_start) {
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
        tree[i] = (right_trav >= tree_size || tree[left_trav] < tree[right_trav]) ? left_trav : right_trav;
    }
}

void resetTree(int tree[], int tree_size, int elem_start, int parent) {
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
        tree[parent] = (right_trav >= tree_size || tree[left_trav] < tree[right_trav]) ? left_trav : right_trav;
    }
}

#endif