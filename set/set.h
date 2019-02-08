#ifndef SET_H
#define SET_H

#include <stddef.h>

#define SUCCESS  0

struct set;

struct set set__empty(void);

int set__is_empty( const struct set* set);

int set__find( const struct set* set, int e);
size_t set__size( const struct set *set);

int set__add( struct set *set, int e);
int set__remove( struct set *set, int e);

#endif

