#include <stdio.h>
#include <stdlib.h>

#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct inventoryItem {
    int number;
    char name[NAME_LEN];
    int on_hand;
    struct inventoryItem *next;
};

typedef struct inventoryItem InventoryItem;

InventoryItem *findPart(InventoryItem *inventory, int itemId) {
    while (inventory) {
        if (itemId == inventory->number) {
            return inventory;
        }
        inventory = inventory->next;
    }
    return NULL;
}

InventoryItem *insert(InventoryItem *inventory) {
    int number;

    printf("Enter part number: ");
    scanf("%d", &number);
    if (findPart(inventory, number) != NULL) {
        printf("Part already exists. \n");
        return inventory;
    }
    InventoryItem *newItem = malloc(sizeof(InventoryItem));

    newItem->number = number;
    printf("Enter part name: ");
    read_line(newItem->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &newItem->on_hand);

    if (inventory == NULL)
        return newItem;
    InventoryItem *p = inventory;
    if (p->number > number) {
        newItem->next = inventory;
        return newItem;
    }
    while (p->next && p->next->number < number)
        p = p->next;
    newItem->next = p->next;
    p->next = newItem;
    return inventory;
}

void print(InventoryItem *inventory) {
    printf("Part Number\t\tPart Name\t\tQuantity on Hand\n");
    while (inventory != NULL) {
        printf("%07d\t\t\t%-24s%d\n", inventory->number, inventory->name, inventory->on_hand);
        inventory = inventory->next;
    }
}

void search(InventoryItem *inventory) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);
    InventoryItem *item = findPart(inventory, number);
    if (!item) {
        printf("Part not found.\n");
        return;
    }
    printf("Part name: %s\n", item->name);
    printf("Quantity on hand: %d", item->on_hand);
}

void update(InventoryItem *inventory) {

    int number;
    printf("Enter part number: ");
    scanf("%d", &number);
    InventoryItem *item = findPart(inventory, number);
    if (!item) {
        printf("Part not found.");
        return;
    }

    printf("Enter part name: ");
    read_line(item->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &item->on_hand);
}


int main(void) {
    InventoryItem *inventory = NULL;
    char code;
    while (1) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');

        switch (code) {
        case 'i':
            inventory = insert(inventory);
            break;
        case 's':
            search(inventory);
            break;
        case 'u':
            update(inventory);
            break;
        case 'p':
            print(inventory);
            break;
        case 'q':
            return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }

    return 0;
}
