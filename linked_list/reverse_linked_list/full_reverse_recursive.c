#include "reverse.h"
#include<stdlib.h>
struct node * full_reverse_recursive(struct node * head) {
    if(head==NULL || head->next==NULL) return head;
    node * temp=full_reverse_recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
     
}
