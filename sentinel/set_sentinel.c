#include "set_sentinel.h"

struct set set__empty() {
    struct set set;
    for (int k=0;k<SET_SIZE;k+=1)
	set.s[k] = -1;
}

int set__is_empty(struct set set) {
    return(set.s[0]==-1);
}

void permute(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int set__add(struct set set, int i) {
    int k=SET_SIZE;
    while(set.s[k]==-1&&k>0)
	k-=1;
    if(k==SET_SIZE)
	return -1;
    set.s[k]=i;
    for(;k>1;k-=1)
	if(set.s[k-1]>set.s[k])
	    permute(&set.s[k-1],&set.s[k]);
    return(i);
}
