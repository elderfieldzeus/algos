#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
    int color; // 0 for Red, 1 for Black
} *RBT;

void rotateLeft(RBT *x);
void rotateRight(RBT *x);

void insert(RBT *root, int data);
void delete(RBT *root, int data);
void deleteFixup(RBT *root, RBT *node);

void preorder(RBT root);

int main() {

}

void rotateLeft(RBT *x) {
    RBT temp = (*x)->right;

    (*x)->right = temp->left;
    temp->left = *x;

    *x = temp;
}

void rotateRight(RBT *x) {
    RBT temp = (*x)->left;

    (*x)->left = temp->right;
    temp->right = *x;

    *x = temp;
}

void insert(RBT *root, int data) {
    
}