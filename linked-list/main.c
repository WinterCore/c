#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *addNode(struct node *node, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = node;
    return newNode;
}

struct node *searchNode(struct node *node, int predicate) {
    while (node != NULL && node->value != predicate)
        node = node->next;
    return node;
}

void deleteNode(struct node **tree, struct node *node) {
    struct node *entry = *tree;

    while (entry) {
        if (entry->value == node->value) {
            *tree = entry->next;
            free(entry);
        }
        tree = &entry->next;
        entry = entry->next;
    }
}

void printNode(struct node *node) {
    while (node) {
        printf("%d - ", node->value);
        node = node->next;
    }
    putchar('\n');
}

int main(void) {
    struct node *node = NULL;
    node = addNode(node, 1);
    node = addNode(node, 2);
    node = addNode(node, 3);
    node = addNode(node, 4);
    node = addNode(node, 5);
    printNode(node);
    deleteNode(&node, searchNode(node, 3));
    printNode(node);
    return 0;
}
