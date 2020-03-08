#ifndef UNION_H
#define UNION_H

#include <stdbool.h>

struct object { int id, size; bool isOpen; };

bool are_objects_connected(struct object *[], int, int);
void union_objects(struct object *[], int, int);


#endif
