#include "reverse.h"
#include <stdlib.h>
struct node * reverse_iterative_every_two_nodes(struct node * head ) {
   if(head==NULL || head->next==NULL) return head;
   node * head_temp=head->next;
   node * prev=NULL;
   while(head!=NULL && head->next!=NULL) {
      node * succr=head->next;
      if(prev!=NULL) prev->next=succr;
      prev=head;
      head->next=succr->next;
      succr->next=head;
      head=head->next;
   }
   prev->next=head;
   return head_temp;
}
