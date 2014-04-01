#include "reverse.h"
#include<stdlib.h>
struct node * reverse_recursive_every_k_nodes(struct node * head,int k) {
    if(head==NULL || head->next==NULL) return head;
    struct node * prev=NULL, * curr=head,*succr,*temp;
    int i=0;
    while(curr!=NULL && i < k) {
        succr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succr;
        i++;
    }
    if(curr!=NULL) {
        head->next=reverse_recursive_every_k_nodes(curr,k);
        return prev;    
    }
    else {
        return prev;
    }
}
