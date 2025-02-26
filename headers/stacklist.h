#include "./general.h"

#ifndef STACKLIST_H
#define STACKLIST_H

typedef struct node {
    int data;
    struct node *next;
} *StackList;

/* Stack Functions  */
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


/* List Functions */

void insertSortedAscNoMalloc(StackList *L, int data, StackList node) {
    if (node != NULL) {
        StackList *trav;

        for (trav = L; *trav != NULL && data > (*trav)->data; trav = &(*trav)->next) {}

        node->data = data;
        node->next = *trav;
        *trav = node;
    }
}

void insertSortedAsc(StackList *L, int data) {
    StackList temp = (StackList)malloc(sizeof(struct node));

    if (temp != NULL) {
        StackList *trav;

        for (trav = L; *trav != NULL && data > (*trav)->data; trav = &(*trav)->next) {}

        temp->data = data;
        temp->next = *trav;
        *trav = temp;
    }
}

void insertSortedDesc(StackList *L, int data) {
    StackList temp = (StackList)malloc(sizeof(struct node));

    if (temp != NULL) {
        StackList *trav;

        for (trav = L; *trav != NULL && data < (*trav)->data; trav = &(*trav)->next) {}

        temp->data = data;
        temp->next = *trav;
        *trav = temp;
    }
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