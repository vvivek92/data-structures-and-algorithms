#include<stdlib.h>
#include"reverse.h"
#include<stdio.h>
node * head;

void createlist(void){
    node * temp;
    int i;
    for(i=0;i<17;i++) {
        temp= malloc(sizeof(node));
        temp->i=i;
        if(head==NULL) {
            head=temp;    
            head->next=NULL;
        }
        else {
            temp->next=head;
            head=temp;
        }
}
}

void printlist(void) {
    node * temp=head;
    printf("\n");
    while(temp!=NULL) {
    printf(" %d",temp->i);
    temp=temp->next;
    }
    printf("\n");
}

int main(void) {
    head=NULL;
    createlist();
    printlist();
    //head=full_reverse_iterative(head);
    //head=full_reverse_recursive(head);
    //head=reverse_recursive_every_two_nodes(head);
    //head=reverse_iterative_every_two_nodes(head);
    //head=reverse_recursive_every_k_nodes(head,4);
    head=reverse_iterative_every_k_nodes(head,4);
    printlist();
}
