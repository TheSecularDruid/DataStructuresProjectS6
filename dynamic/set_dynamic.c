#include "set_dynamic.h"
#include <stdlib.h>

struct set set__empty(){
    struct set set;
    set.capacity=0;
    set.size=0;
    set.s=NULL;
}

int set__is_empty(struct set set) {
    return(set.capacity==0);
}

int set__add(struct set set, int i) {
    if (i<0)
	return(NEGATIVE_INT);
    if (set.size=set.capacity) {
	set.capacity *= 2;
	set.s = realloc(set.s,set.capacity*sizeof(int));
    }
    set.size+=1;
    set.s[set.size] = i;
    int* ptr = &set.s[set.size];
    while(*ptr<*(ptr-1)&&(*ptr>0)) {
	int temp=*ptr;
	*ptr=*(ptr-1);
	*(ptr-1)=temp;
	ptr--;
    }
}

int set__remove(struct set set, int i) {
    int* ptr = set.s;
    int k = 0;
    while (*ptr<i) {
	ptr++;
	k++;
    }
    if (*ptr!=i)
	return NEGATIVE_INT;
    for (;k<size;k+=1) {
	*ptr = *(ptr+1);
	ptr++;
    }
    set.size-=1;
    if (set.size<set.capacity/2) {
	set.capacity/=2;
	set.s = realloc(set.s,set.capacity*sizeof(int));
    }	
}

int set_find(struct set set, int i) {
    int* ptr = set.s;
    while (*ptr<i)
	ptr++;
    return(*ptr==i);
}

int set__size(struct set set) {
    return(set.size);
}
