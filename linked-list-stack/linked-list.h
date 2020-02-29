#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int value;
    struct node *next;
};

void add_node(struct node **head, int value);
void delete_node(struct node **head, int value);
void reverse(struct node **head);
struct node *reverse_recursive(struct node *head);
void print(struct node *head);

#endif
