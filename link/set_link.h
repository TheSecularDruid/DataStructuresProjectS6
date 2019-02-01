#ifndef SET_LINK_H
#define SET_LINK_H

#include "link.h"

struct set {
    struct link* l;
};


struct set set__empty();
int set__is_empty(struct set to_test);
int set__add(struct set dest, int i);
int set__remove(struct set source, int i);
int set__find(struct set place, int i);
int set__size(struct set to_test);

#endif
