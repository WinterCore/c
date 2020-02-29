#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void add_node(struct node **head, int value) {
    while (*head)
        head = &(*head)->next;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next  = NULL;
    *head = newNode;
}


void delete_node(struct node **head, int value) {
    struct node *curr = *head;
    while (curr) {
        if (curr->value == value) {
            *head = curr->next;
        }
        head = &curr->next;
        curr = curr->next;
    }
}

void print(struct node *head) {
    while (head) {
        printf("%d", head->value);
        if (head->next != NULL) {
            printf(" - ");
        }
        head = head->next;
    }
    putchar('\n');
}


void reverse(struct node **head) {
    struct node *next = *head,
                *prev = NULL;
    while (next) {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        (*head) = next;
    }
    *head = prev;
}

struct node *reverse_recursive(struct node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct node *rest = reverse_recursive(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}
