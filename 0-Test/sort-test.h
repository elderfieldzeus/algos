#include "../headers/general.h"
#include "../headers/arrays.h"

#define TEST_MAX_ELEM 100
#define TEST_MAX_CHAR 50

#ifndef SORT_TEST_H
#define SORT_TEST_H


typedef struct {
    char label [TEST_MAX_CHAR];
    int start[TEST_MAX_ELEM];
    int correct[TEST_MAX_ELEM];
    int size;
} Test;

Test tests[] = {
    {"Basic case", {5, 3, 8, 4, 2}, {2, 3, 4, 5, 8}, 5},
    {"Empty array", {}, {}, 0},
    {"One element", {1}, {1}, 1},
    {"Already Sorted", {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, 5},
    {"Reverse Sorted", {9, 7, 5, 3, 1}, {1, 3, 5, 7, 9}, 5},
    {"With Duplicates", {4, 2, 2, 8, 3, 3, 1}, {1, 2, 2, 3, 3, 4, 8}, 7},
    {"Large Numbers", {1000000, 500, 100, 250000}, {100, 500, 250000, 1000000}, 4},
};

int test_size = sizeof(tests) / sizeof(tests[0]); 

void test_check(int correct[], int output[], int size, int test_number, char label[]) {
    if(memcmp(correct, output, sizeof(int) * size) == 0) {
        printf("Test #%d Successful! (%s)\n\n", test_number, label);
    }
    else {
        printf("Test #%d Failed! (%s)\n", test_number, label);
        printf("Expected:\t[");
        printinl(correct, size);
        printf("]\nOutput:\t\t[");
        printinl(output, size);
        printf("]\n\n");
    }
}

void test_sort_w_size(void (*sort)(int arr[], int size)) {
    cls();
    for (int i = 0; i < test_size; i++) {
        Test test = tests[i];         

        int arr[test.size];
        memcpy(arr, test.start, sizeof(int) * test.size);

        sort(arr, test.size);

        test_check(test.correct, arr, test.size, i + 1, test.label);
    }
}

void test_sort_w_low_high(void (*sort)(int arr[], int low, int high)) {
    cls();
    for (int i = 0; i < test_size; i++) {
        Test test = tests[i];         

        int arr[test.size];
        memcpy(arr, test.start, sizeof(int) * test.size);

        sort(arr, 0, test.size - 1);

        test_check(test.correct, arr, test.size, i + 1, test.label);
    }
}

#endif