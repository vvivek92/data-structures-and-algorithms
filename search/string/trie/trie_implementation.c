#include<stdlib.h>
#include<stdio.h>
// associative array between name and age 
#include<assert.h>
typedef struct trie_node{
    char c;
    int value;
    struct trie_node * arr[27];// 26 alphabets /0 
} trie_node;

trie_node * getnode(void) {
    trie_node * node = malloc(sizeof(trie_node));
    int i;
    for(i=0;i<27;i++)
        node->arr[i]=NULL;
    return node;
}

void insert(trie_node * node, char * key, int age) {
    assert(node);
    assert((*key <='z' && *key>='a') || *key=='\0');
    if(*key=='\0') {
        if(!node->arr[26]) 
            node->arr[26]=getnode();
        node->arr[26]->c='\0';
        node->arr[26]->value=age;
        return;
    }
    else {
        if(!node->arr[*key-'a']) 
            node->arr[*key-'a']=getnode();
        node->arr[*key-'a']->c=*key;
        insert(node->arr[*key-'a'],key+1,age);
    } 
}

int search (trie_node * node, char * key) {
    assert(node);
    assert((*key <='z' && *key>='a') || *key=='\0');
    if(*key=='\0') {
        if(node->arr[26])
            return node->arr[26]->value;
        else
            return -1;
    }
    if(node->arr[*key-'a'])
        return search(node->arr[*key-'a'], key+1);
    else
        return -1;    
}



int main() {
    trie_node * root;
    root=getnode();
    insert(root,"andrew",26);  
    insert(root,"ela",22);  
    insert(root,"andrew",34);  
    insert(root,"pita",22);
    printf("\n%d",search(root,"andrew"));
    printf("\n%d",search(root,"nomchin"));
   

}


