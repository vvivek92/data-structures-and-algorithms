#include<stdlib.h>
#include<stdio.h>
// associative array between name and age 
#include<assert.h>
typedef struct trie_node{
    int is_end;
    char c;
    int value;
    struct trie_node * arr[26];// 26 alphabets /0 
} trie_node;

trie_node * getnode(void) {
    trie_node * node = malloc(sizeof(trie_node));
    int i;
    for(i=0;i<26;i++)
        node->arr[i]=NULL;
    return node;
}

void insert(trie_node * node, char * key, int age) {
    assert(node);
    assert((*key <='z' && *key>='a') || *key=='\0');
    if(*key=='\0') {
        node->is_end=1;
        node->value=age;
        return;
    }
    else {
        if(!node->arr[*key-'a']) 
            node->arr[*key-'a']=getnode();
        node->arr[*key-'a']->c=*key;
        node->arr[*key-'a']->is_end=0;
        insert(node->arr[*key-'a'],key+1,age);
    } 
}

int search (trie_node * node, char * key) {
    assert(node);
    assert((*key <='z' && *key>='a') || *key=='\0');
    if(*key=='\0')
        if(node->is_end==1) 
            return node->value;
        else
            return -1;
    if(node->arr[*key-'a'])
        return search(node->arr[*key-'a'], key+1);
    else
        return -1;    
}

trie_node * lnode(char * start, trie_node * node) {
    assert(node);
    if(*start=='\0' ) 
            return node;
    
    if(node->arr[*start-'a'])
        return lnode(start+1,node->arr[*start-'a']);
    else
        return 0;    
}
void print(char * start, trie_node * lnode, char * s, int index) {
    if(lnode==NULL) return;
    s[index++]=lnode->c;
    if(lnode->is_end) {
        printf("\n");
        for(int i=0;start[i]!='\0';i++)
            printf("%c",start[i]);
       for(int i=1;i<index;i++)
            printf("%c",s[i]);
    }
    for(int i=0;i<26;i++)
        print(start,lnode->arr[i],s,index);
}


void autocomplete(char * start,trie_node  * root) {
    char s[100];
    int index=0;
    if(*start=='\0')print(start,root,s,index);
    trie_node * lastnode = lnode(start,root);
    if(lastnode)print(start,lastnode, s,  index);
}


int main() {
    trie_node * root;
    root=getnode();
    root->is_end=0;
    insert(root,"andrew",26);  
    insert(root,"ela",22);  
    insert(root,"elmond",22);  
    insert(root,"eljuan",22);  
    insert(root,"el",22);  
    insert(root,"elmon",22);  
    
    insert(root,"andrew",34);  
    insert(root,"pita",22);
//    printf("\n%d",search(root,"andrew"));
//    printf("\n%d",search(root,"nomchin"));
    autocomplete("el",root); 

}


