#include "../../0-Test/sort-test.h"
#include "../../headers/general.h"
#include "../../headers/arrays.h"
#define BASE 10 // base 10
#define MAX_COUNT_SIZE 100000

void countSort(int arr[], int size);

int main() {
    cls();
    test_sort_w_size(countSort);
    return 0;
}

void countSort(int arr[], int size) {
    if (size <= 0) return;

    int max_num = arr[0];
    int min_num = arr[0];

    for(int i = 1; i < size; i++) {
        max_num = max(max_num, arr[i]);
        min_num = min(min_num, arr[i]);
    }

    int count_size = max_num - min_num + 1;
    
    if (count_size > MAX_COUNT_SIZE) {
        printf("\nError: Size is too big. Use another sorting algorithm");
        return;
    }

    int count_arr[count_size];

    memset(count_arr, 0, sizeof(int) * count_size);

    for (int i = 0; i < size; i++) {
        int index = arr[i] - min_num;
        count_arr[index]++;
    }

    for (int j = count_size - 1; j > 0; j--) {
        count_arr[j] = count_arr[j - 1];
    }
    count_arr[0] = 0;

    // Cumulative sum
    for (int i = 1; i < count_size; i++) {
        count_arr[i] += count_arr[i - 1];
    }

    int output[size];

    for (int i = 0; i < size; i++) {
        int index = arr[i] - min_num;

        output[count_arr[index]++] = arr[i];
    }

    memcpy(arr, output, sizeof(int) * size);
}