#include<stdlib.h>
#include"reverse.h"
struct node * reverse_recursive_every_two_nodes(struct node * head) {
    if(head==NULL || head->next ==NULL) return head;
    node * head_temp=head->next;
    head_temp->next= reverse_recursive_every_two_nodes(head_temp->next);
    head->next=head_temp->next;
    head_temp->next=head;
    return head_temp;
}
