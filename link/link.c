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
    return(to_test==SENTINEL);
}

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
