#ifndef LINK_H
#define LINK_H

#include <stdio.h>

struct lelement {
    int data;
    struct lelement* next;
};

struct link {
    struct lelement* head;
};

//-----func prototypes----------//
struct link lnk__empty();
struct lelement* lnk__first(const struct link* link);
int llm__is_end_mark(const struct lelement* to_test);
void lnk__add_head(struct link* dest,  struct lelement* to_add);
struct lelement* lnk__remove_head(struct link* source);
struct lelement* llm__next(struct lelement current);
void lnk__add_after(struct lelement* where_to, struct lelement* what_to);
struct lelement* lnk__remove_after(struct lelement* where_to);
void lnk__add_tail(struct lelement* to_add, struct link* dest);
struct lelement* lnk__remove_tail(struct link* source);

#endif
