#include "reverse.h"
#include<stdlib.h>
struct node * reverse_iterative_every_k_nodes(struct node * head,int k) {
    node * previous=NULL,*current=head, * curr,*prev=NULL,*succr,*ret=NULL;

    while(current!=NULL) {
    int i=0;
    curr=current;
    prev=NULL;
    while(curr!=NULL && i<k) {
        succr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succr;
        i++;
    }
    if(previous==NULL) 
        ret=prev;
    else
        previous->next=prev;
    previous=current;
    current=curr;
    }
    return ret;
}
