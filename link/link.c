#include "link.h"

static const struct lelement sentinel={-1, (struct lelement *) &sentinel};
#define SENTINEL ((struct lelement*) &sentinel)

struct link lnk__empty() {
    struct link empty = {SENTINEL};
    return empty;
}

struct lelement* lnk__first(const struct link* link) {
    return link->head;
}

int llm__is_end_mark(const struct lelement* to_test) {
    return(to_test==SENTINEL);}


void lnk__add_head(struct link* dest, struct lelement* to_add) {
    to_add->next = dest->head;
    dest->head = to_add;
}

struct lelement* lnk__remove_head(struct link* source) {
    struct lelement* to_return = source->head;
    source->head = to_return->next;
    if (to_return == SENTINEL)
	return SENTINEL;
    to_return->next = NULL;
    return to_return;
}

struct lelement* llm__next(struct lelement current) {
    return current.next;
}

void lnk__add_after(struct lelement* where_to, struct lelement* what_to) {
    what_to->next = where_to->next;
    where_to->next = what_to;
}

struct lelement* lnk__remove_after(struct lelement* where_to) {
    if (where_to->next==SENTINEL)
	return SENTINEL;
    struct lelement* buffer = where_to->next;
    where_to->next = buffer->next;
    return buffer;   
}

void lnk__add_tail(struct lelement* to_add, struct link* dest) {
    struct lelement* ptr = dest->head;
    if (ptr==SENTINEL) {
	dest->head = to_add;
	to_add->next = SENTINEL;
    }
    else {
	while (ptr->next!=SENTINEL) {
	    ptr = ptr->next;
	}
	ptr->next = to_add;
	to_add->next = SENTINEL;
    }
}

struct lelement* lnk__remove_tail(struct link* source) {
    struct lelement* ptr = source->head;
    if (ptr==SENTINEL)
	return SENTINEL;
    if (ptr->next==SENTINEL) {   //liste de 1 élément
	ptr->next = NULL;
	source->head = SENTINEL;
	return ptr;
    }
    while (ptr->next->next!=SENTINEL) {
	ptr = ptr->next;
    }
    struct lelement* to_return = ptr->next;
    to_return->next = NULL;
    ptr->next = SENTINEL;
    return to_return;
}
