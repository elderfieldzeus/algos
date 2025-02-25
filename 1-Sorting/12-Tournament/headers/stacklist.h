#include "../../../headers/general.h"

#ifndef STACKLIST_H
#define STACKLIST_H

typedef struct node {
    int data;
    struct node *next;
} *StackList;

void push(StackList *S, int data) {
    StackList temp = (StackList) malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->data = data;
        temp->next = *S;
        *S = temp;
    }
}

void pop(StackList *S) {
    StackList temp = *S;

    if (temp != NULL) {
        *S = temp->next;
        free(temp);
    }
}

int top(StackList S) {
    return (S == NULL) ? -1 : S->data;
}

// Merge lists to A
StackList mergeDescending(StackList A, StackList B) {
    StackList C = NULL;
    StackList *travC = &C;

    while (A != NULL && B != NULL) {
        if (B->data > A->data) {
            *travC = B;
            B = B->next;
        } 
        else {
            *travC = A;
            A = A->next;
        }
        travC = &(*travC)->next;
    }

    if (A == NULL) {
        A = B;
    }

    *travC = A;

    return C;
}

void printSL(StackList S) {
    while(S != NULL) {
        printf("%d ", S->data);
        S = S->next;
    }
    printf("\n");
}

#endif