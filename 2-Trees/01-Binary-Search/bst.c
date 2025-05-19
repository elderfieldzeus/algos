#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *BST;

void insert(BST* root, int data);
void delete(BST* root, int data);
bool search(BST root, int data);
void inorder(BST root);

int main() {
    BST root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Search for 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Search for 90: %s\n", search(root, 90) ? "Found" : "Not Found");

    delete(&root, 20);
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    delete(&root, 30);
    printf("Inorder traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    delete(&root, 50);
    printf("Inorder traversal after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}

void insert(BST *root, int data) {
    if (*root == NULL) {
        BST temp = (BST)malloc(sizeof(struct node));

        if (temp != NULL) {
            temp->data = data;
            temp->left = temp->right = NULL;
            *root = temp;
        }
        
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

void delete(BST *root, int data) {
    if (*root == NULL) {
        return;
    }
    
    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    } else {
        // Node with only one child or no child
        if ((*root)->right == NULL) {
            BST temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            BST *temp = &(*root)->right;
            while (*temp && (*temp)->left != NULL) {
                temp = &(*temp)->left;
            }
            (*root)->data = (*temp)->data; // Copy the inorder successor's content to this node
            
            free(*temp);
            *temp = NULL;
        }
    }
}

bool search(BST root, int data) {
    if (root == NULL) {
        return false;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return true;
    }
}

void inorder(BST root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}