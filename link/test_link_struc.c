#include "link.h"
#include <stdlib.h>

int main() {
    //--------exo2 : Init/head/sentinel--------//
    struct link test = lnk__empty();
    printf("The first cell of an empty queue is sentinel : %d \n",llm__is_end_mark(lnk__first(&test)));
    
    //--------exo3 : Add/rm/next--------------//
    int length = 5;
    int value[5] = {4,2,1,3,7};
    //remplissage
    for (int k=0;k<length;k+=1) {
	struct lelement* newcell = malloc(sizeof(struct lelement));
	newcell->data=value[k];					   
	lnk__add_head(&test,newcell);
    }
    int bool_test = 1;
    struct lelement buffer=*(test.head);
    //parcours
    for (int k=length-1;k>=0;k-=1) {
	bool_test = bool_test && (buffer.data == value[k]);
	buffer = *buffer.next;
    }
    printf("Browsing through the pile works and values are sorted as planned : %d \n", bool_test);
    //vidage
    bool_test = 1;
    struct lelement* buffer_ptr;
    for (int k=length-1;k>=0;k-=1) {
	buffer_ptr = lnk__remove_head(&test);
	bool_test = bool_test&&(buffer_ptr->data==value[k]);
	free(buffer_ptr);
    }
    printf("Depiled value are in inverted orders compared to empiled values : %d \n", bool_test);
    


    return 0;
}
