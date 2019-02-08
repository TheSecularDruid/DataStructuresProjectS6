#ifndef SET_SENTINEL_H
#define SET_SENTINEL_H

#define SET__SIZE 10
#define BORNE -1

struct set{
    int s[SET_SIZE];
};

//debug function
void print_set(const struct set* set);
#endif
