#include <stdlib.h>

#include "set_link.h"
#include "link.h"


struct set set__empty() {
    struct set to_return;
    struct link* idkwhatImdoing = malloc(sizeof(struct link));
    *idkwhatImdoing = lnk__empty();
    to_return.l = idkwhatImdoing;
    return (to_return);
}

int set__is_empty(struct set to_test) {
    return (llm__is_end_mark(to_test.l->head));
}

int set__add(struct set where_to, int i) {
    struct lelement* to_add = malloc(sizeof(struct lelement));
    to_add->next=NULL;
    to_add->data=i;

    struct lelement* ptr = where_to.l->head;	    
    if (ptr->data>i)
	lnk__add_head(where_to.l,to_add);
    while (!llm__is_end_mark(ptr->next)) {
	if (ptr->next->data>i) {
	    lnk__add_after(ptr,to_add);
	    return i;
	}
	else
	    ptr=llm__next(*ptr);
    }
    lnk__add_tail(to_add, where_to.l);
    return i;
}

int set__remove(struct set source, int i) {
    struct lelement* ptr = source.l->head;
    while (!llm__is_end_mark(ptr->next)) {
	if (ptr->next->data == i) {
	    lnk__remove_after(ptr);
	    return (i);
	}	
	else
	    ptr = llm__next(*ptr);	    
    }
    return(-1);
}

int set__find(struct set place, int i) {
    struct lelement* ptr = place.l->head;
    while (!llm__is_end_mark(ptr)) {
	if (ptr->data == i)
	    return 1;
	else
	    ptr = llm__next(*ptr);
    }
    return 0;
}

int set__size(struct set to_test) {
    int size = 0;
    struct lelement* ptr = to_test.l->head;
    while (!llm__is_end_mark(ptr)) {
	size++;
	ptr = llm__next(*ptr);
    }
    return size;
}
