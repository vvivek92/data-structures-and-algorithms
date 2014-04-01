//given two strings find percent match of words
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

struct trie_node {
    int value;
    trie_node* next[256];

};

trie_node * create_node(void) {
    trie_node * temp=new trie_node();
    temp->value=0;
    for(int i=0;i<256;i++)
        temp->next[i]=NULL;
    return temp;
}

trie_node * build_trie(trie_node * root, const char *c ) {
    

    if(!root)root=create_node();
    if(*c=='\0') {
        root->value=1;
        return root;
    }
    
    root->next[static_cast<int>(*c)]=build_trie(root->next[static_cast<int>(*c)], c+1);
    return root;
}


bool exists_in_trie(trie_node * root,const char * c) {
    if(root==NULL)
        return false;

    if(*c=='\0') {
        if(root->value) return true;
        else return false;
    }
    return exists_in_trie(root->next[(int)(*c)],c+1);

}

int main(void) {
    char s1 []="hey how are you today";
    char s2 []="hey vivek how are you";
    trie_node * root=NULL;
    char * temp=NULL;
    temp=strtok(s1," .,");
    while(temp!=NULL) {
        cout<<temp<<endl;
        root=build_trie(root,temp);
        temp=strtok(NULL," .,");
    } 
     temp=strtok(s2," .,");
    int hit=0,miss=0;
    while(temp!=NULL) {
        cout<<temp<<endl;
         if(exists_in_trie(root,temp))
             hit++;
         else
             miss++;
        temp=strtok(NULL," .,");
    }
    cout<<endl<<"hit n miss are "<<hit <<" "<<miss<<endl;

}
