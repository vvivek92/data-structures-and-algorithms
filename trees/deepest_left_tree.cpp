#include <stdio.h>
#include <iostream>
using namespace std;
 
struct Node
{
    int val;
    struct Node *left, *right;
};
 
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}
 
 
char deepest_recursive(Node * root,Node **n,int *depth){
    if(root==NULL) {
        (*depth)=0;
        return '\0';
    }

    char left='\0',right='\0';
    Node ** n_left=new Node *,**n_right=new Node *;
    int * depth_left=new int, * depth_right=new int;

    left= deepest_recursive(root->left,n_left,depth_left);
    right= deepest_recursive(root->right,n_right,depth_right);
    if(left=='L' && right=='L') {
        if(depth_left> depth_right) {
            *depth=(*depth_left)++;
            *n=*n_left;
            return 'L';
        }
        else {
            *depth=(*depth_right)++;
            *n=*n_right;
            return 'L';
        }
   }
   else if(left=='L') {
        *depth=(*depth_left)++;
        *n=*n_left;
        return 'L';
   }


   else if(right=='L') {
        *depth=(*depth_right)++;
        *n=*n_right;
        return 'L';
    }
    else if(!root->left && ! root->right ) {
        *depth=1;
        *n=root;
        return 'F';
    }
    else if(left=='F') {
        *depth=2;
        *n=*n_left;
        //cout<<"n_left "<<*n<<"data "<<(*n)->val;
        return 'L';
    }
    else {
        *depth=0;
        *n=NULL;
        return '\0';
    }

}
Node* deepestLeftLeaf(Node *root)
{
    Node ** n=new Node *;
    int * depth=new int;
    char c='\0';
    c= deepest_recursive(root,n,depth);
    if(c=='L' || c=='F') return *n;
    else return NULL;
}
 
// Driver program to test above function
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    Node *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->val;
    else
        cout << "There is no left leaf in the given tree";
 
    return 0;
}
