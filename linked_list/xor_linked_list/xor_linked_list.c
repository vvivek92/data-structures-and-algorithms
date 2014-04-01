#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int i;
    struct node * ptrdiff;
} node ;

node * head;

void add_from_front(int i){
    node * mynode = malloc(sizeof(node));
    mynode->i=i;
    if(head==NULL) {
        mynode->ptrdiff=(node *)((uintptr_t)(void * )NULL ^(uintptr_t)(void * )NULL);
    }
    else {
        mynode->ptrdiff=(node *)((uintptr_t)(void * )NULL ^(uintptr_t)(void * )head);
        head->ptrdiff=(node *)((uintptr_t)(void * )mynode ^(uintptr_t)(void * )(head->ptrdiff));
    }
    head=mynode;
}

void print(void) {
    node * temp=head;
    node * prev_temp=NULL;
    node * next_temp;
    printf("\n");
    while(temp!=NULL) {
        printf("%d ",temp->i);
        next_temp=(node *)((uintptr_t)(void * ) temp->ptrdiff ^ (uintptr_t)(void * )prev_temp);
        prev_temp=temp;
        temp=next_temp;
    }
    printf("\n");
}

void delete(void) {
     node * temp=head;
    node * prev_temp=NULL;
    node * next_temp;
    while(temp!=NULL) {
        next_temp=(node *)((uintptr_t)(void * ) temp->ptrdiff ^ (uintptr_t)(void * )prev_temp);
        prev_temp=temp;
        free(temp);
        temp=next_temp;
    }
   
}

int main(void) {
    head=NULL;
    int j;
    for(j=0;j<=12;j++)
        add_from_front(j);
    print();
    delete();
    return 0;
}
