#include<algorithm>
#include<iostream>
#include<climits>
#include <queue>
using namespace std;
struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};

void print_lvl_queue (node * root) {
    if(root==NULL) return ;
    queue<node *> q;
    q.push(root);
    while(!q.empty()) {
        node * temp=q.front();
        q.pop();
        cout<<temp->height<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}
node * rotate_left(node * root) {
    node * new_root=root->right;
    node * shift_node=new_root->left;
    new_root->left=root;
    root->right=shift_node;
    return new_root;
}

node * rotate_right(node * root) {
    node * new_root=root->left;
    node * shift_node=new_root->right;
    new_root->right=root;
    root->left=shift_node;
    return new_root;
}
void print(node * root) {
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);

}
int find_balance_factor(node * root) {
    int lh=0,rh=0;
    if(root->left) lh=root->left->height;
    if(root->right) rh=root->right->height;
    return lh-rh;
}

int find_height(node * root) {
    int lh=0,rh=0;
    if(root->left) lh=root->left->height;
    if(root->right) rh=root->right->height;
    return (1+max(lh,rh));

}
node * insert(node * root, int data) {
    if(root==NULL) {
        root=new node();
        root->height=1;
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(root->data==data) {
        return root;
    }
    else if(root->data < data) {
        root->right=insert(root->right,data);
    }
    else if(root->data > data)
        root->left=insert(root->left,data);

    int balance_factor;
    balance_factor=find_balance_factor(root);
    if(balance_factor==2) {
        if(find_balance_factor(root->left)==-1) {
            root->left=rotate_left(root->left);
            root->left->left->height=find_height(root->left->left);
            //root->left->height=find_height(root->left);
        }
        root=rotate_right(root);
        root->right->height=find_height(root->right);
    
    }
    else if(balance_factor==-2) {
        if(find_balance_factor(root->right)==1) {
            root->right=rotate_right(root->right);
            root->right->right->height=find_height(root->right->right);
            //root->right->height=find_height(root->right);
        }
        root=rotate_left(root);
        root->left->height=find_height(root->left);
    }
    root->height=find_height(root);        
    return root; 
}


int main() {
    node * root=NULL;
    int i;
    for( i=0;i<7;i++)
        root=insert(root,i);
    cout<<endl;
    print(root);   
    cout<<endl;
    cout<<endl;
    cout<<root->height;
    cout<<endl;
    cout <<"P";
    print_lvl_queue(root);
}



