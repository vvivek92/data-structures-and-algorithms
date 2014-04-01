#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
    int key;
    struct node * left, * right;
};

struct node * newNode (int key) {
    struct node * temp =( node*)malloc(sizeof(node));
    temp->key=key;
    temp->left=temp->right=NULL;
    return temp;
}

node * rotateRight(node * x) {
    node * temp=x->left;
    x->left=temp->right;
    temp->right=x;
    return temp;
}
node * rotateLeft(node * x) {
    node * temp=x->right;
    x->right=temp->left;
    temp->left=x;
    return temp;
}

void preOrder(node * root) {
    if(root!=NULL) {
        cout<<" "<<root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}
/*** search for a key and makes it the top, else makes the last key seen before NULL as top **/
node * splay(node * root, int key ) {
    if(root==NULL|| root->key == key ) return root;
    if(root->key > key) {
        if(root->left==NULL) return root;
        if(root->left->key > key) {
            root->left->left=splay(root->left->left,key);
            root=rotateRight(root);    
        }
        else if(root->left->key < key ) {
            root->left->right=splay(root->left->right,key);
            if(root->left->right) rotateLeft(root->left);   
        }        
        if(root->left) root=rotateRight(root);
        return root;
    }
    if(root->key < key) {
        if(root->right==NULL) return root;
        if(root->right->key < key) {
            root->right->right=splay(root->right->right,key);
            root=rotateLeft(root);    
        }
        else if(root->right->key > key ) {
            root->right->left=splay(root->right->left,key);
            if(root->right->left) rotateRight(root->right);   
        }        
        if(root->right) root=rotateLeft(root);
        return root;
    }
}

node * search (node * root, int key) {
    return splay(root,key);
}
int main() {
    node * root= newNode(100);
    root->left=newNode(50);
    root->right=newNode(200);
    root->left->left=newNode(40);
    root->left->left->left=newNode(30);
    root->left->left->left->left=newNode(20);
    preOrder(root);
    root=search(root,20);
    cout<<endl;
    preOrder(root);
    return 0;
}














