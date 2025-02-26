#include "../../headers/general.h"
#include "../../headers/arrays.h"

void gnomeSort(int arr[], int size);

int main() {
    cls();

    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    print(arr, size);

    gnomeSort(arr, size);

    printf("Gnome-sorted array: ");
    print(arr, size);

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