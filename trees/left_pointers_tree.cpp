#include <queue>
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

struct node {
    struct node * left;
    struct node * right;
    struct node * left_side;
    struct node * right_side;
    int data;
};


void inorder(node * root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    root->left_side=NULL;
    root->right_side=NULL;
    inorder(root->right);
}

void level_order(node * root) {
    queue<node *> n1,n2;
    n1.push(root);
    cout<<endl;
    while(!n1.empty()) {
        node * temp = n1.front();
        n1.pop();        
        cout<<temp->data<<" ";
        if(temp->left)n2.push(temp->left);
        if(temp->right)n2.push(temp->right);
        if(n1.empty()) { 
            cout<<endl;
            swap(n1,n2);
        } 
        else {
            temp->right_side=n1.front();
            n1.front()->left_side=temp;    
        }
    }
}

void level_order_ptr(node * root) {
    queue<node *> n1,n2;
    n1.push(root);
    cout<<endl;
    while(!n1.empty()) {
        node * temp = n1.front();
        n1.pop();
        cout<<temp->data<<" ";
        if(temp->left)n2.push(temp->left);
        if(temp->right)n2.push(temp->right);
        if(n1.empty()) { 
            cout<<endl;
            swap(n1,n2);
        }
    }
}


int main(void) {
    node * root=new node();
    root->data=2;
    root->left=new node();
    root->left->data=5;
    root->left->left=NULL;  
    root->left->right=NULL;  
    root->right=new node();
    root->right->data=7;
    root->right->left=new node();
    root->right->left->data=9;
    root->right->left->left=NULL;
    root->right->left->right=NULL;

    root->right->right=new node();
    root->right->right->data=9;
    root->right->right->left=NULL;
    root->right->right->right=NULL;
 
    
    cout<<endl;
    inorder(root);
    cout<<endl;
    level_order(root);
    cout<<root->data<<endl;
    cout<<root->left->left_side<<" ";
    cout<<root->left->right_side<<" ";
    cout<<root->right->right_side;
}
