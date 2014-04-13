#include<iostream>
#include<cstdlib>
using namespace std;


struct node {
    int data;
    node * left;
    node * right;
};



node * traversal_from_root(node * n, node * root,node * parent) {
    node * temp=NULL;
    if(root==NULL || n==NULL) return NULL;
    if(n==root) return parent;
    if((temp=traversal_from_root(n,root->right,parent)))
        return temp;
    

    if((temp=traversal_from_root(n,root->left,root)))
        return temp;
    return NULL;
}

node * min_sub_tree(node * n) {
 // trivial
    return NULL;
}

node * inorder_successor(node * n,node * root) {
    if(n==NULL) return n;
    if(n->right) return min_sub_tree(n->right);
    return traversal_from_root(n,root,NULL);
}

int main() {
    node * h=new node;
    h->data=1;
    h->right=new node;
    h->right->left=NULL;
    h->right->right=NULL;
    h->left=new node;
    h->left->right=NULL;
    h->left->left=new node;
    h->left->data=12;
    h->left->left->left=NULL;
    h->left->left->right=NULL;
    h->left->left->data=100;
    node * n =inorder_successor(h->left->left,h);
    cout<<n->data;
}

