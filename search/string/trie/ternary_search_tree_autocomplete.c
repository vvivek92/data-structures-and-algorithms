#include<stdio.h>
// associative array between name and age 
#include<assert.h>
#include<stdlib.h>
typedef struct tst_node{
    int is_end;
    char c;
    int value;
    struct tst_node * arr[3];//lo eq hi pointers 
} tst_node;

tst_node * getnode(void) {
    tst_node * node = malloc(sizeof(tst_node));
    int i;
    for(i=0;i<3;i++)
        node->arr[i]=NULL;
    return node;
}

tst_node *  insert(tst_node * node, char * key, int age) {
    assert((*key <='z' && *key>='a') );
    if(*key =='\0')return node;
    if(node==NULL) {
        node=getnode();
        node->c=*key;
        node->is_end=0;
    }
    if(node->c==*key)
        if(*(key+1)=='\0')
            {node->is_end=1;node->value=age;}
        else 
            node->arr[1]= insert(node->arr[1],key+1,age);
    else if (*key < node->c)
        node->arr[0]= insert(node->arr[0],key,age);
    else if(*key > node->c)
        node->arr[2]= insert(node->arr[2],key,age);
    return node;
}

int search (tst_node * node, char * key) {
    if(node==NULL) return -1;
    assert((*key <='z' && *key>='a') );
    assert(*key !='\0');
 
    if(*key==node->c)
        if(*(key+1)=='\0')
            if( node->is_end)
                return 1;
            else
                return -1;
        else
            return search(node->arr[1],key+1);
    else if(*key < node->c)
        return search(node->arr[0],key);
    else if(*key > node->c)
        return search(node->arr[2],key);
}

tst_node * lnode(char * start, tst_node * node) {
    assert(node);
    if(*start=='\0') 
            return node;
    if(*start == node->c)
            if(*(start+1)=='\0')
                return node ;
             else
                return lnode(start+1,node->arr[1]);
    else if(*start < node->c)
        return lnode(start,node->arr[0]);
    else if(*start > node->c)
        return lnode(start,node->arr[2]);
}

void print(char * start, tst_node * lnode, char * s, int index) {
    if(lnode==NULL) return;
    if(lnode->is_end) {
        printf("\n");
        for(int i=0;start[i+1]!='\0';i++)
            printf("%c",start[i]);
       for(int i=0;i<index;i++)
            printf("%c",s[i]);
       printf("%c",lnode->c);
    }
    if(lnode->arr[0]) {
        print(start,lnode->arr[0],s,index);
    }
    if(lnode->arr[2]) {
        print(start,lnode->arr[2],s,index);
    }
    if(lnode->arr[1]) {
        s[index++]=lnode->c;
        print(start,lnode->arr[1],s,index);
    }

}

void autocomplete(char * start,tst_node  * root) {
    char s[100];
    int index=0;
    if(*start=='\0')print(start,root,s,index);
    tst_node * lastnode = lnode(start,root);
    printf("\n%c",lastnode->c);
    if(lastnode)print(start,lastnode, s,  index);
}


int main() {
    tst_node * root;
    root=NULL;
    root=insert(root,"andrew",26);  
    root=insert(root,"ela",22);  
    root=insert(root,"elmond",22);  
    root=insert(root,"eljuan",22);  
    root=insert(root,"el",22);  
    root=insert(root,"elmon",22);  
    root=insert(root,"elm",22);  
    
    root=insert(root,"andrew",34);  
    root=insert(root,"pita",22);
    printf("\n%d",search(root,"andrew"));
    //for(tst_node * i=root;i!=NULL;i=i->arr[1])
    //printf("\n %c",i->c);
    printf("\n%d",search(root,"nomchin"));
    autocomplete("el",root); 
    //printf("\n %d %c",root->arr[2]->arr[1]->arr[1]->arr[2]->is_end,root->arr[2]->arr[1]->arr[1]->arr[2]->c);
}


