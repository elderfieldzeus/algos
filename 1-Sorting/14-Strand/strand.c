#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "./headers/stacklist.h"

void strandSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    strandSort(arr, size);

    printf("Strand-sorted array: ");
    print(arr, size);

    return 0;
}

void strandSort(int arr[], int size) {
    StackList arr_list = NULL;
    StackList output = NULL;

    // Copy elements to arr_list from end since I am using Stack approach
    for (int i = size - 1; i >= 0; i--) {
        push(&arr_list, arr[i]);
    }

    // Strand Sort Algorithm
    // While arr_list is not empty
    while (arr_list != NULL) {

        // Initialize sublist (stack)
        StackList sublist = NULL;

        // Initialize trav for deleting
        StackList *trav = &arr_list;

        // This portion is similar to delete all occurences
        while (*trav != NULL) {
            // If sublist is empty, or if current element is lesser than top of sublist
            if (sublist == NULL || (*trav)->data >= top(sublist)) {
                // Temporarily store next element in arr_list
                StackList temp = (*trav)->next;

                // Push element to top of sublist
                (*trav)->next = sublist;
                sublist = *trav;

                // Make *trav point to the next element (temp)
                *trav = temp;
            }
            else {
                // Traverse
                trav = &(*trav)->next;
            }
        }

        // Since it is in reverse order (stack) we merge 2 sorted lists (descending)
        output = mergeDescending(output, sublist);
    }

    // Return sorted elements back to arr (Remember it is still in descending order, so we start from the end)
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = top(output);
        pop(&output);
    }
}