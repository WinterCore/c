#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int value;
    struct node *next;
};

void add_node(struct node **head, int value);
void delete_node(struct node **head, int value);
void reverse(struct node **head);
int count_occurrences(struct node *head, int n);
struct node *reverse_recursive(struct node *head);
void print(struct node *head);
struct node *find_last(struct node *list, int n);
void insert_into_ordered_list(struct node **list, struct node *new_node);

#endif
