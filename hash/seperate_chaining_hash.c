#include<stdlib.h>
#include<stdio.h>


typedef struct node {
    int key;
    int value;
    struct node * next;
} node;

typedef struct hash_table {
    int table_size;
    int count;
    node ** table;
} hash_table;

hash_table * create(int table_size) {
    hash_table * hashTable= malloc(sizeof(hash_table));
    hashTable->count=0;
    hashTable->table_size=table_size;
    hashTable->table= malloc(sizeof(node *) * table_size);
    if(!(hashTable || hashTable->table)) printf("err");
    int i=0;
    for(;i<table_size;i++)
        hashTable->table[i]=NULL;
    return hashTable;
}
void print(hash_table * hashTable) {
   int i=0;
   printf("printing...");
   for(;i<(hashTable->table_size);i++) {
       node * temp;
       for(temp=hashTable->table[i];temp!=NULL;temp=temp->next) {
           printf("%d %d ",temp->key,temp->value); 
       }
       printf("\n");
   }
}
int hash (int key, int table_size) {
    return key % table_size;    
}

void insert(int key, int value, hash_table *h) {
    node * temp;
    temp=malloc(sizeof(node));
    temp->key=key;
    temp->value=value;
    int index=hash(key,h->table_size);
    temp->next=h->table[index];
    h->table[index]=temp;
}

hash_table * rehash(hash_table * h) {
    hash_table * t;
    t=create(h->table_size * 2);
   int i=0; 
   for(;i<(h->table_size);i++) {
       node * temp;
       for(temp=h->table[i];temp!=NULL;) {
           int index=hash(temp->key,t->table_size);
           node * a=t->table[index];   
           t->table[index]=temp;
           temp=temp->next;
           t->table[index]->next=a;  
       }
   }
   return t;


}
int main(void) {
    hash_table * h = create(11);
    h->count=0;
  //  print(h);
    int i=1;
    for(;i<100;i*=2)
        insert(i,i,h);
    print(h);
    hash_table * t= rehash(h);
    print(t);   
}




