#include "../../../headers/general.h"

#ifndef BUCKET_H
#define BUCKET_H
#define BUCKET_SIZE 2

typedef struct node {
    int data;
    struct node *next;
} *Bucket;

typedef Bucket Buckets[BUCKET_SIZE];

void initBuckets(Buckets BS) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        BS[i] = NULL;
    }
}

void insertSorted(Bucket *B, int data) {
    Bucket *trav;
    Bucket temp = (Bucket)malloc(sizeof(struct node));

    if(temp != NULL) {
        for (trav = B; *trav != NULL && data >= (*trav)->data; trav = &(*trav)->next) {}

        temp->data = data;
        temp->next = *trav;
        *trav = temp;
    }
}

#endif