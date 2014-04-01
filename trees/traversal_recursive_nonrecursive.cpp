#include <queue>
#include <iostream>
#include<stack>
using namespace std;




struct node {
    struct node * left;
    struct node * right;
    int data;
};

node * create_tree(void) {
    int i=0;
    node* root=new node();
    root->left=root->right=NULL;
    root->data=i++;
    queue<node *> q;
    q.push(root);
    while(i<14) {
        node * temp=q.front();
        q.pop();
        
        temp->left=new node ();
        q.push(temp->left);
        temp->left->left=temp->left->right=NULL;
        temp->left->data=i++;    
        
        temp->right=new node ();
        q.push(temp->right);
        temp->right->right=temp->right->left=NULL;
        temp->right->data=i++;    
    }
    return root;
}

void preorder_recursive(node * root) {
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
   
}
void preorder_non_recursive(node * root) {
    stack<node *> s;
    if(root==NULL) return;
    s.push(root);
    while(!s.empty()) {
        node * temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
}

void inorder_recursive(node * root) {
    if(root==NULL) return;
    inorder_recursive(root->left);
    cout<<root->data<<" ";
    inorder_recursive(root->right);
   
}
void inorder_non_recursive(node * root) {
    stack<node *> s;
    if(root==NULL) return;
    node * temp=root;
    s.push(temp);
    while(!s.empty()) {
        while(temp->left) {
            s.push(temp->left);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
 
        if(temp->right) {
            temp=temp->right;
            s.push(temp);
        }
    }

}

void postorder_recursive(node * root) {
    if(root==NULL) return;
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout<<root->data<<" ";
   
}
void postorder_non_recursive(node * root) {
    stack<node *> s;
    if(root==NULL) return;
    do {
    while(root) {
        if(root->right) s.push(root->right);
        if(root)s.push(root);
        root=root->left;
    }
    root=s.top();
    s.pop();
    if(root->right && !s.empty() &&root->right==(s.top())) {
        s.pop();
        s.push(root);
        root=root->right;
    }    
    else {
        cout<<root->data<<" ";
        root=NULL;
    }
    }while(!s.empty());
}

int main(void) {
    node * root=create_tree();
/*  node * root= new node();
    root->left= new node();
    root->right= new node();
    root->data=1;
    root->left->data=2;
    root->right->data=3;
    root->left->left=root->left->right=NULL;
    root->right->left=root->right->right=NULL;
*/    int size;
    cout<<endl;  
    preorder_recursive(root);
    cout<<endl;
    preorder_non_recursive(root);
    
    cout<<endl;  
    inorder_recursive(root);
    cout<<endl;
    inorder_non_recursive(root);
    cout<<endl;
  
    postorder_recursive(root);
    cout<<endl;
    postorder_non_recursive(root);
    return 0;
}
