#include "../../headers/general.h"
#define NUMBER_OF_CHARACTERS 26

typedef struct node {
    struct node *characters[NUMBER_OF_CHARACTERS];
    int count;
    bool isEndOfWord;
} *Trie;

Trie newNode();
void insert(Trie *trie, char word[], int index);
bool delete(Trie *trie, char word[], int index);
bool search(Trie trie, char word[], int index);

int main() {
    Trie trie = NULL;

    insert(&trie, "hello", 0);
    insert(&trie, "world", 0);
    insert(&trie, "hell", 0);

    printf("Searching for 'hello': %s\n", search(trie, "hello", 0) ? "Found" : "Not Found");
    printf("Searching for 'hell': %s\n", search(trie, "hell", 0) ? "Found" : "Not Found");
    printf("Searching for 'world': %s\n", search(trie, "world", 0) ? "Found" : "Not Found");
    printf("Searching for 'lollers': %s\n", search(trie, "lollers", 0) ? "Found" : "Not Found");

    delete(&trie, "hello", 0);

    printf("Searching for 'hello' after deletion: %s\n", search(trie, "hello", 0) ? "Found" : "Not Found");
    printf("Searching for 'hell' after deleting 'hello': %s\n", search(trie, "hell", 0) ? "Found" : "Not Found");

    return 0;
}

Trie newNode() {
    Trie temp = (Trie)malloc(sizeof(struct node));

    if (temp != NULL) {
        for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
            temp->characters[i] = NULL;
        }
        temp->count = 0;
        temp->isEndOfWord = false;
    }

    return temp;
}

void insert(Trie *trie, char word[], int index) {

    if (*trie == NULL) {
        *trie = newNode();
    }
    
    if (index == strlen(word)) {
        (*trie)->isEndOfWord = true;
        return;
    }   

    insert(&(*trie)->characters[word[index] - 'a'], word, index + 1);
    (*trie)->count++;
}

bool delete(Trie *trie, char word[], int index) {
    if (*trie == NULL || (index == strlen(word) && !(*trie)->isEndOfWord)) return false;

    if (index == strlen(word)) {
        (*trie)->isEndOfWord = false;
        (*trie)->count--;

        if ((*trie)->count == 0) {
            free(*trie);
            *trie = NULL;
            return true;
        }

        return false;
    }

    bool deleteNode = delete(&(*trie)->characters[word[index] - 'a'], word, index + 1);

    if (deleteNode) {
        (*trie)->count--;

        if ((*trie)->count == 0) {
            free(*trie);
            *trie = NULL;
            return true;
        }
        else {
            return false;
        }
    }
}

bool search(Trie trie, char word[], int index) {
    if (trie == NULL) return false;

    if (index == strlen(word)) {
        return trie->isEndOfWord;
    }

    return search(trie->characters[word[index] - 'a'], word, index + 1);
}