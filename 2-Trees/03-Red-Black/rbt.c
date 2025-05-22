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

void transplant(RBT *root, RBT toBeDeleted, RBT replacement);
void delete(RBT *root, int data);
void deleteFixup(RBT *root, RBT node);

void preorder(RBT root);

int main() {
    RBT root = NULL;

    insert(&root, 10);preorder(root);printf("\n");
    insert(&root, 20);preorder(root);printf("\n");
    insert(&root, 30);preorder(root);printf("\n");
    insert(&root, 15);preorder(root);printf("\n");
    insert(&root, 25);preorder(root);printf("\n");
    insert(&root, 21);preorder(root);printf("\n");

    delete(&root, 20);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 30);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 15);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 25);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 10);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

    delete(&root, 21);
    printf("\nPreorder Traversal after deletion: ");
    preorder(root);

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

                // Case 3: Uncle is black triangle
                if (!nodeIsLeft) {
                    rotateLeft(nodeParent);
                    nodeParent = node;
                }

                // Case 4: if (nodeIsLeft) Uncle is black line
                rotateRight(nodeParent->parent);

                nodeParent = nodeParent->right;
            }
            else {

                // Case 3: Uncle is black triangle
                if (nodeIsLeft) {
                    rotateRight(nodeParent);
                    nodeParent = node;
                }

                // Case 4: if (!nodeIsLeft) Uncle is black line
                rotateLeft(nodeParent->parent);
                
                nodeParent = nodeParent->left;
            }
        }

        node = nodeParent;
        nodeParent = nodeParent->parent;
    }

    // In the case of a new root, we update the root pointer
    if (nodeParent != NULL && nodeParent->parent == NULL) {
        *root = nodeParent;
    }

    (*root)->color = BLACK; // Case 1: Root is always black
}

void transplant(RBT *root, RBT toBeDeleted, RBT replacement) {
    if (toBeDeleted == *root) {
        *root = replacement;
    }
    else if (toBeDeleted->parent->left == toBeDeleted) {
        toBeDeleted->parent->left = replacement;
    } else {
        toBeDeleted->parent->right = replacement;
    }
}

void delete(RBT *root, int data) {
    RBT *trav = root, nodeToBeDeleted = NULL, replacement = NULL;

    // BST Traversal to find the node to be deleted
    while (*trav != NULL && (*trav)->data != data) {
        if (data < (*trav)->data) {
            trav = &(*trav)->left;
        } else {
            trav = &(*trav)->right;
        }
    }

    if (*trav == NULL) return;

    nodeToBeDeleted = *trav;
    int originalColor = nodeToBeDeleted->color;

    // Case 1: Left Child is NULL
    if (nodeToBeDeleted->left == NULL) {
        replacement = nodeToBeDeleted->right;
        transplant(root, nodeToBeDeleted, replacement);
    }

    // Case 2: Right Child is NULL
    else if (nodeToBeDeleted->right == NULL) {
        replacement = nodeToBeDeleted->left;
        transplant(root, nodeToBeDeleted, replacement);
    }

    // Case 3: Both Children are not NULL
    else {
        replacement = nodeToBeDeleted->right;

        while (replacement->left != NULL) {
            replacement = replacement->left;
        }

        originalColor = replacement->color;

        transplant(root, replacement, replacement->right);
        
        replacement->right = nodeToBeDeleted->right;
        replacement->right->parent = replacement;

        transplant(root, nodeToBeDeleted, replacement);
        replacement->left = nodeToBeDeleted->left;
        replacement->left->parent = replacement;
        replacement->color = nodeToBeDeleted->color;
    }


    if (originalColor == BLACK && replacement != NULL) {
        deleteFixup(root, replacement);
    }
    else if (originalColor == BLACK) {
        // nodeToBeDeleted is used as a temporary node to signify DOUBLE_BLACK
        deleteFixup(root, nodeToBeDeleted);
    }

    free(nodeToBeDeleted);
}

void deleteFixup(RBT *root, RBT node) {
    if (*root == NULL || node == NULL) return;

    while (node != *root && node->color == BLACK) {
        bool nodeIsLeft = (node == node->parent->left || (node->parent->right != node && node->parent->left == NULL)) ? true : false;
        RBT sibling = (nodeIsLeft) ? node->parent->right : node->parent->left;

        if (sibling == NULL) {
            node = node->parent;
            continue;
        }

        // Case 1: Sibling is Red
        if (sibling->color == RED) {
            sibling->color = BLACK;
            node->parent->color = RED;

            if (nodeIsLeft) {
                rotateLeft(node->parent);
                sibling = node->parent->right;
            } else {
                rotateRight(node->parent);
                sibling = node->parent->left;
            }
        }

        // Case 2: Sibling is Black with two black children
        if ((sibling->left == NULL || sibling->left->color == BLACK) && (sibling->right == NULL || sibling->right->color == BLACK)) {
            sibling->color = RED;
            node = node->parent;
        }
        else {
            // Case 3.A: Node is left, Sibling is Black, and sibling's right child is black
            if ((sibling->right == NULL || sibling->right->color == BLACK) && nodeIsLeft) {
                sibling->color = RED;

                sibling->left->color = BLACK;
                rotateRight(sibling);
                sibling = node->parent->right;

            }
            // Case 3.B: Node is right, Sibling is Black, and sibling's left child is black
            else if ((sibling->left == NULL || sibling->left->color == BLACK) && !nodeIsLeft) {
                sibling->color = RED;

                sibling->right->color = BLACK;
                rotateLeft(sibling);
                sibling = node->parent->left;
            }

            // Case 4: Sibling is black and sibling's right child is Red
            sibling->color = node->parent->color;
            node->parent->color = BLACK;

            if (nodeIsLeft) {
                sibling->right->color = BLACK;
                rotateLeft(node->parent);
            } else {
                sibling->left->color = BLACK;
                rotateRight(node->parent);
            }

            node = *root;
        }
    }

    node->color = BLACK;
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