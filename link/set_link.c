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

int set__is_empty(const struct set* s) {
    return (llm__is_end_mark(lnk__first(s->l)));
}

int set__add(struct set* set, int e) {
    struct lelement* to_add = malloc(sizeof(struct lelement));
    to_add->next=NULL;
    to_add->data=e;

    struct lelement* ptr = set->l->head;	    
    if (ptr->data>e)
	lnk__add_head(set->l,to_add);
    while (!llm__is_end_mark(ptr->next)) {
	if (ptr->next->data>e) {
	    lnk__add_after(ptr,to_add);
	    return e;
	}
	else
	    ptr=llm__next(*ptr);
    }
    lnk__add_tail(to_add, set->l);
    return e;
}

int set__remove(struct set* set, int e) {
    struct lelement* ptr = set->l->head;
    while (!llm__is_end_mark(ptr->next)) {
	if (ptr->next->data == e) {
	    lnk__remove_after(ptr);
	    return (e);
	}	
	else
	    ptr = llm__next(*ptr);	    
    }
    return(-1);
}

int set__find(const struct set* set, int e) {
    struct lelement* ptr = set->l->head;
    while (!llm__is_end_mark(ptr)) {
	if (ptr->data == e)
	    return 1;
	else
	    ptr = llm__next(*ptr);
    }
    return 0;
}

int set__size(const struct set* set) {
    int size = 0;
    struct lelement* ptr = set->l->head;
    while (!llm__is_end_mark(ptr)) {
	size++;
	ptr = llm__next(*ptr);
    }
    return size;
}

void set__free(struct set* set) {
    struct lelement* ptr = set->l->head;
    struct lelement* ptr_next = ptr->next;
    while (!llm__is_end_mark(ptr_next->next)) {
	ptr_next = ptr->next;
	free(ptr);
	ptr = ptr_next;
    }
    free(set->l);
}
