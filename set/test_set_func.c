#include "set.h"
#ifdef SENTINEL
#include "../sentinel/set_sentinel.h"
#elif defined DYNAMIC
#include "../dynamic/set_dynamic.h"
#elif defined LINK
#include "../link/set_link.h"
#endif

#include <stdlib.h>


int test_set_empty_and_set_is_empty() {
    return(set__is_empty(set__empty()));
}

int test_adding_in_empty_set() {
    struct set empty_set = set__empty();
    set__add(empty_set, rand());
    return(!set__is_empty(empty_set));
}

int test_finding_in_empty_set() {
    struct set empty_set = set__empty();
    set__find(empty_set, rand());
}

int test_find() {
    struct set set = set__empty();
    int to_find = rand();
    set__add(set, to_find);
    return (set__find(set, to_find));
}





int main(void) {
    printf("set__is_empty() returns an empty set : %d\n", test_set_empty_and_set_is_empty());
    printf("adding in an empty set makes it not-empty : %d\n", test_adding_in_empty_set());
    printf("finding in an empty set returns false : %d\n", test_finding_in_empty_set());
    printf("finding in a set containing i returns true : %d\n", test_find());
}
