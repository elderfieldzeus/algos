#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED 0
#define BLACK 1

typedef struct node {
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
    int color; // 0 for Red, 1 for Black
} *RBT;

void rotateLeft(RBT x);
void rotateRight(RBT x);

void insert(RBT *root, int data);
void delete(RBT *root, int data);
void deleteFixup(RBT *root, RBT *node);

void preorder(RBT root);

int main() {
    RBT root = NULL;

    insert(&root, 10);preorder(root);printf("\n");
    insert(&root, 20);preorder(root);printf("\n");
    insert(&root, 30);preorder(root);printf("\n");
    insert(&root, 15);preorder(root);printf("\n");
    insert(&root, 25);preorder(root);printf("\n");
    insert(&root, 21);preorder(root);printf("\n");

    // delete(&root, 20);

    // printf("Preorder Traversal after deletion: ");
    // preorder(root);
    // printf("\n");

    return 0;
}

void rotateLeft(RBT x) {
    RBT temp = x->right;

    x->right = temp->left;
    if (temp->left != NULL) {
        temp->left->parent = x;
    }

    temp->left = x;
    temp->parent = x->parent;

    if (x->parent != NULL) {
        if (x == x->parent->left) {
            x->parent->left = temp;
        } else {
            x->parent->right = temp;
        }
    }

    x->parent = temp;
}

void rotateRight(RBT x) {
    RBT temp = x->left;

    x->left = temp->right;
    if (temp->right != NULL) {
        temp->right->parent = x;
    }

    temp->right = x;
    temp->parent = x->parent;

    if (x->parent != NULL) {
        if (x == x->parent->left) {
            x->parent->left = temp;
        } else {
            x->parent->right = temp;
        }
    }

    x->parent = temp;
}

void insert(RBT *root, int data) {
    RBT *trav = root, nodeParent = NULL;

    // BST Traversal to find the position for the new node
    while (*trav != NULL && (*trav)->data != data) {
        nodeParent = *trav;

        if (data < (*trav)->data) {
            trav = &(*trav)->left;
        } else {
            trav = &(*trav)->right;
        }
    }

    
    // Or you can wrap all the code below this with an if statement
    if (*trav != NULL) return;

    RBT temp = (RBT)malloc(sizeof(struct node));

    temp->data = data;
    temp->parent = nodeParent;
    temp->left = NULL;
    temp->right = NULL;
    temp->color = RED; // New node is red
    
    *trav = temp;
    
    // Fix the tree

    RBT node = temp;
    while (nodeParent != NULL && nodeParent->color == RED && nodeParent->parent != NULL) {
        bool parentIsLeft = (nodeParent == nodeParent->parent->left) ? true : false;
        bool nodeIsLeft = (node == nodeParent->left) ? true : false;
        RBT uncle = (parentIsLeft) ? nodeParent->parent->right : nodeParent->parent->left;

        // Case 2: Uncle is red
        if (uncle != NULL && uncle->color == RED) {
            nodeParent->color = BLACK;
            uncle->color = BLACK;

            nodeParent->parent->color = RED;
        }
        else {
            nodeParent->color = BLACK;
            nodeParent->parent->color = RED;

            if (parentIsLeft) {
                if (!nodeIsLeft) {
                    
                    rotateLeft(nodeParent);
                    nodeParent = node;
                }

                rotateRight(nodeParent->parent);

                nodeParent = nodeParent->right;
            }
            else {
                if (nodeIsLeft) {
                    rotateRight(nodeParent);
                    nodeParent = node;
                }
                rotateLeft(nodeParent->parent);
                
                nodeParent = nodeParent->left;
            }
        }

        node = nodeParent;
        nodeParent = nodeParent->parent;
    }

    if (nodeParent != NULL && nodeParent->parent == NULL) {
        *root = nodeParent;
    }

    (*root)->color = BLACK; // Case 1: Root is always black
}

void preorder(RBT root) {
    if (root == NULL) {
        printf("_ ");
        return;
    };

    printf("[%d-%s] ", root->data, root->color == RED ? "R" : "B");
    preorder(root->left);
    preorder(root->right);
}