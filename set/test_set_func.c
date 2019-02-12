#include "set.h"
#ifdef SENTINEL
#include "../sentinel/set_sentinel.h"
#elif defined DYNAMIC
#include "../dynamic/set_dynamic.h"
#elif defined LINK
#include "../link/set_link.h"
#endif

#include <stdio.h>
#include <stdlib.h>


int test_set_empty_and_set_is_empty() {
    struct set empty_set = set__empty();
    return(set__is_empty(&empty_set));
}

int test_adding_in_empty_set() {
    struct set empty_set = set__empty();
    set__add(&empty_set, rand());
    return(!set__is_empty(&empty_set));
}

int test_finding_in_empty_set() {
    struct set empty_set = set__empty();
    return(set__find(&empty_set, rand()));
}

int test_find() {
    struct set set = set__empty();
    int to_find = rand();
    set__add(&set, to_find);
    return (set__find(&set, to_find));
}

/* int test_add_when_already_there() {  //doesn't make much sense in dynamically allocated memory implementation, as far as I think, I'd need a function actually comparing the content of the sets, like set__equal or something alike. Still makes sense in statically allocated memory implementation, which is why it's there. Also it's an axiom. */
/*     struct set set = set__empty(); */
/*     int to_add = rand(); */
/*     set__add(&set, to_add); */
/*     struct set set2 = set; */
/*     set__add(&set2,to_add); */
/*     return (set2==set); */
/* } */

int test_removing_from_empty_set() {
    struct set set = set__empty();
    int to_remove = rand();
    set__remove(&set, to_remove);
    return (set__is_empty(&set));
}

/* int test_adding_then_removing() { //same issue as test_add_when_already_there */
/*     struct set set = set__empty(); */
/*     int element = rand(); */
/*     set__add(&set,rand()); */
/*     struct set set2 = set; */
/*     set__add(&set, element); */
/*     set__remove(&set, element); */
/*     return(set==set2); */
/*}*/

int test_size_of_empty_set() {
    struct set set = set__empty();
    return(set__size(&set));
}

int test_size_increase_when_adding() {
    struct set set = set__empty();
    int cur_size = set__size(&set);
    set__add(&set,rand());
    int new_size = set__size(&set);
    return(new_size==cur_size+1);
}

int main(void) {
    printf("set__is_empty() returns an empty set : %d\n", test_set_empty_and_set_is_empty());
    printf("adding in an empty set makes it non-empty : %d\n", test_adding_in_empty_set());
    printf("finding in an empty set returns false : %d\n", !test_finding_in_empty_set());
    printf("finding in a set containing i returns true : %d\n", test_find());
    //printf("adding an element in a set that already contains said element doesn't change said set : %d\n", test_add_when_already_there());
    printf("removing an element from an empty set does nothing : %d\n", test_removing_from_empty_set());
    //printf("adding then removing a given element does not change set : %d\n", test_adding_then_removing());
    printf("the empty set has a size 0 : %d\n", !test_size_of_empty_set());
    printf("adding an element to a set increase size by 1 : %d\n", test_size_increase_when_adding());    
}
