#include<stdlib.h>
#include "reverse.h"
struct node * full_reverse_iterative(struct node * head) {
    struct node * prev=NULL, * curr=head, * succ;
    while(curr != NULL) {
        succ=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succ;
    }
    return prev;
}
