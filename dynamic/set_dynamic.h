#ifndef SET_DYNAMIC_H
#define SET_DYNAMIC_H

#include <stddef.h>

#define NEGATIVE_INT -42

struct set {
    int* s;
    size_t capacity;
    size_t size;
};

struct set set__empty();
int set__is_empty(struct set set);
int set__add(struct set set, int i);
int set__remove(struct set set, int i);
int set__find(struct set set, int i);
int set__size(struct set set);

#endif
