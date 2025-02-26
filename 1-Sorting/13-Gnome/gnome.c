#include "../../headers/general.h"
#include "../../headers/arrays.h"
#include "../../0-Test/sort-test.h"

void gnomeSort(int arr[], int size);

int main() {
    test_sort_w_size(gnomeSort);
    return 0;
}

void gnomeSort(int arr[], int size) {
    int trav = 0;

    while(trav < size) {
        if (trav == 0 || arr[trav - 1] <= arr[trav]) {
            trav++;
        }
        else {
            swap(arr + trav, arr + trav - 1);
            trav--;
        }
    }
}