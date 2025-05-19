#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a, b) ((a > b) ? a : b)

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int height; // Height of the node for AVL balancing
} *AVL;


int getHeight(AVL x);
int getNewHeight(AVL x);
int getBalanceFactor(AVL x);

void rotateLeft(AVL *x);
void rotateRight(AVL *x);

void balance(AVL *root);

void insert(AVL* root, int data);
void delete(AVL* root, int data);
bool search(AVL root, int data);
void preorder(AVL root);

int main() {
    AVL root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Search for 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Search for 90: %s\n", search(root, 90) ? "Found" : "Not Found");

    delete(&root, 20);
    printf("Preorder traversal after deleting 20: ");
    preorder(root);
    printf("\n");

    delete(&root, 30);
    printf("Preorder traversal after deleting 30: ");
    preorder(root);
    printf("\n");

    delete(&root, 50);
    printf("Preorder traversal after deleting 50: ");
    preorder(root);
    printf("\n");

    return 0;
}

int getHeight(AVL x) {
    return x == NULL ? 0 : x->height;
}

int getNewHeight(AVL x) {
    return max(getHeight(x->left), getHeight(x->right)) + 1;
}

int getBalanceFactor(AVL x) {
    return x == NULL ? 0 : getHeight(x->left) - getHeight(x->right);
}

void rotateLeft(AVL *x) {
    AVL temp = (*x)->right;

    (*x)->right = temp->left;
    temp->left = *x;

    (*x)->height = getNewHeight(*x);
    temp->height = getNewHeight(temp);

    *x = temp;
}

void rotateRight(AVL *x) {
    AVL temp = (*x)->left;

    (*x)->left = temp->right;
    temp->right = *x;

    (*x)->height = getNewHeight(*x);
    temp->height = getNewHeight(temp);

    *x = temp;
}

void balance(AVL *root) {
    if (*root != NULL) {
        int balanceFactor = getBalanceFactor(*root);

        // Case 1: Left-Left
        if (balanceFactor > 1 && getBalanceFactor((*root)->left) > 0) {
            rotateRight(root);
        }
        // Case 2: Left-Right
        else if (balanceFactor > 1) {
            rotateLeft(&(*root)->left);
            rotateRight(root);
        }
        // Case 3: Right - Right
        else if (balanceFactor < -1 && getBalanceFactor((*root)->right) < 0) {
            rotateLeft(root);
        }
        // Case 4: Right - Left
        else if (balanceFactor < -1) {
            rotateRight(&(*root)->right);
            rotateLeft(root);
        }
    }
}

void insert(AVL* root, int data) {
    if (*root == NULL) {
        AVL temp = (AVL)malloc(sizeof(struct node));

        if (temp != NULL) {
            temp->data = data;
            temp->left = temp->right = NULL;
            *root = temp;
        }
    }
    else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }

    (*root)->height = getNewHeight(*root);

    balance(root);
}

void delete(AVL* root, int data) {
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
            AVL temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            AVL temp = (*root)->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data; // Copy the inorder successor's content to this node
            delete(&(*root)->right, temp->data);
        }
    }

    if (*root != NULL) {
        (*root)->height = getNewHeight(*root);
    }

    balance(root);
}

bool search(AVL root, int data) {
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    return search((data < root->data) ? root->left : root->right, data);
}

void preorder(AVL root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else {
        printf("_ ");
    }
}