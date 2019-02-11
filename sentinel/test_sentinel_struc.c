#include "../set/set.h"
#include "set_sentinel.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    struct set test_set = set__empty();
    print_set(&test_set);
    int a = rand()%100;
    int ret;
    ret = set__add(&test_set, a);
    fprintf(stderr,"Adding an integer is done in the first emplacement of set : %d\n", test_set.s[0]==a);
    fprintf(stderr,"Returned value is the integer added : %d\n", ret==a);
    if (ret!=a)
	fprintf(stderr,"Actually returned value was %d\n", ret);
    fprintf(stderr,"Sentinel still there : %d\n", test_set.s[1]==-1);
    print_set(&test_set);
    ret = set__add(&test_set, a);
    fprintf(stderr,"Adding an integer already in the set returns an error : %d\n", ret==-1);
    print_set(&test_set);
    for (int k=1;k<SET__SIZE+1;k+=1)
	set__add(&test_set, a+k);
    fprintf(stderr, "The set is full : %d\n", test_set.s[SET__SIZE-2]!=-1);
    ret = set__add(&test_set, a+SET__SIZE+2);
    fprintf(stderr,"Adding an integer in an already full set returns an error : %d\n", ret==-1);
    fprintf(stderr, "Sentinel still there : %d\n",test_set.s[SET__SIZE-1]==-1);
    print_set(&test_set);
    set__remove(&test_set, a);
    fprintf(stderr,"Removing an integer from a set actually removes it : %d\n", ((test_set.s[SET__SIZE-2]==-1)&&(test_set.s[0]==a+1)));
    print_set(&test_set);

    //Adding elements one by one conserve order
    test_set = set__empty();
    set__add(&test_set,a);
    set__add(&test_set,a+2);
    set__add(&test_set,a+1);
    print_set(&test_set);
    fprintf(stderr,"Adding several integers conserves order : %d\n", test_set.s[0]<test_set.s[1]&&test_set.s[1]<test_set.s[2]);
}
