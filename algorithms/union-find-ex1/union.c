#include "union.h"

struct object *get_root(struct object *s[], int a) {
    while (s[a]->id != a) {
        s[a]->id = s[s[a]->id]->id;
        a = s[a]->id;
    }
    return s[a];
}

bool are_objects_connected(struct object *s[], int a, int b) {
    return get_root(s, a)->id == get_root(s, b)->id;
}

void union_objects(struct object *s[], int a, int b) {
    struct object *roa = get_root(s, a);
    struct object *rob = get_root(s, b);
    if (roa->size < rob->size) {
        roa->id = rob->id;
        rob->size += roa->size;
    } else {
        rob->id    = roa->id;
        roa->size += rob->size;
    }
}
