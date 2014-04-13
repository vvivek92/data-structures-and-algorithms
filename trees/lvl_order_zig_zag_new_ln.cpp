#include <queue>
#include <iostream>
#include<algorithm>
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

void print (node * root) {
    if(root==NULL) return;
    cout<<endl<<root->data<<endl;
    print(root->left);
    print(root->right);
}
void print_lvl_queue (node * root) {
    if(root==NULL) return ;
    queue<node *> q1;
    queue<node *> q2;
    q1.push(root);
    while(!q1.empty()) {
        node * temp=q1.front();
        q1.pop();
        cout<<temp->data<<" ";
        if(temp->left)q2.push(temp->left);
        if(temp->right)q2.push(temp->right);
        if(q1.empty()) {
            swap(q1,q2);
            cout<<endl;
        }
    }
}
void print_lvl_zigzag (node * root) {
    if(root==NULL) return ;
    stack<node *> q1;
    stack<node *> q2;
    q1.push(root);
    bool left_right=true;
    while(!q1.empty()) {
        node * temp=q1.top();
        q1.pop();
        cout<<temp->data<<" ";
        if(left_right) {
            if(temp->left) q2.push(temp->left);
            if(temp->right)q2.push(temp->right);
        }
        if(!left_right) {
            if(temp->right)q2.push(temp->right);
            if(temp->left) q2.push(temp->left);
        }
        if(q1.empty()) {
            swap(q1,q2);
            left_right=!left_right;
            cout<<endl;
        }
    }
}

int print_lvl(node * root, int i) {
    if(root==NULL) return 0;
    if(i==0) {
        cout<<endl<<root->data<<endl;
        return 1;
    }
    int k=0,j=0;
    if(root->left)k=print_lvl(root->left,i-1);
    if(root->right)j=print_lvl(root->right,i-1);
    return k||j;
}
void print_lvl_without_queue(node * root) {
    int i=0;
    while(1) {
        if(print_lvl(root,i)==0)
            break;
        i++;
    }
}
int main(void) {
    node * root=create_tree();
    print_lvl_queue(root);
    print_lvl_zigzag(root);
    //have to delete the tree
}
