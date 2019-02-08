#ifndef SET_SENTINEL_H
#define SET_SENTINEL_H

#define SET_SIZE 10

struct set{
    int s[SET_SIZE];
};

//debug function
void print_set(const struct set* set);
#endif
