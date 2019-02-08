#include "set_sentinel.h"
#include "../set/set.h"
#include <stdlib.h>
#include <stdio.h>

struct set set__empty() {
    struct set set={{0}};
    for (int k=0;k<SET_SIZE;k+=1)
	set.s[k] = -1;
    return set;
}

int set__is_empty(const struct set* set) {
    return(set->s[0]==-1);
}

int set__find (const struct set* set, int e) {
    for (int i=0;i<SET_SIZE;i+=1) {
	if (set->s[i]==-1)
	    return 0;
	else if (set->s[i]==e)
	    return 1;
    }
    return -1;
}

size_t set__size (const struct set* set) {
    for (int i=0;i<SET_SIZE;i+=1)
	if (set->s[i]==-1)
	    return i;
    return -1;
}

void permute(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int set__add(struct set* set, int e) {
    if (e<0)
	return -1;
    if (set__find(set, e)==1)
	return -1;
    if (set__is_empty(set)) {
	set->s[0]=e;
	return 0;
    }

    int k=SET_SIZE-1;
    while(set->s[k]==-1&&k>0)
	k-=1;
    if(k==SET_SIZE-2)
	return -1;
    k++;
    set->s[k]=e;
    for(;k>1;k-=1)
	if(set->s[k-1]>set->s[k])
	    permute(&set->s[k-1],&set->s[k]);
    return 0;
}


int set__remove(struct set* set, int e) {
    int flag=0;
    for (int k=0;k<SET_SIZE-1;k+=1) {
	if (set->s[k]==-1&&flag==0)
	    return -1;
	if (set->s[k]==e) {
	    flag=1;
	    set->s[k]=-1;
	}
	if (flag==1)
	    permute (&set->s[k],&set->s[k+1]);
    }
    return 0;
}

//debug function
void print_set(const struct set* set) {
    printf("\n [");
    for (int k=0;k<SET_SIZE;k+=1) {
	printf("%d, ",set->s[k]);
    }
    printf("]\n\n");
}

void set__free(struct set* set){}
