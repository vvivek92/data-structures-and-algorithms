#include <queue>
#include <iostream>
using namespace std;




struct node {
    struct node * left;
    struct node * right;
    int data;
};

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right =  NULL;
    return temp;
}
void print_inorder (node * root) {
    if(root==NULL) return;
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}

node * tree_to_c_dll (node * root) {
    if(root==NULL) return NULL;
    node * left=root, * right_tail=root;
    if(root->left) {
        left = tree_to_c_dll(root->left);
        node * left_tail=left->left;
        left_tail->right=root;
        root->left=left_tail;
        
    }
    if(root->right) {
        node * right =tree_to_c_dll(root->right);
        right_tail=right->left;
        right->left=root;
        root->right=right;
        
    }
    left->left=right_tail;
    right_tail->right=left;
    return left;    
}

int main(void) {

    node* root = newNode(1);
    root->left = newNode(100);
    root->right = newNode(2);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    cout<<endl;
    print_inorder(root);
    cout<<endl;
    root=tree_to_c_dll(root);     
    node * temp;
    
    for(temp=root;;) {
        if(temp){
            cout<<temp->data<<" ";
            temp=temp->right;
        }
        if(temp==NULL || temp==root)
            break;
    }            
    
}
