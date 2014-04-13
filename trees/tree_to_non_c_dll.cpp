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

void tree_to_non_c_dll (node * root,node *& prev,node*&head) {
   if(root==NULL) return;
   if(root->left) tree_to_non_c_dll(root->left,prev,head);
   if(prev) {prev->right=root;root->left=prev;}
   else {root->left=NULL;head=root;}
   prev=root;
   if(root->right) tree_to_non_c_dll(root->right,prev,head);
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
    node * prev=NULL;
    node * head=NULL;
    tree_to_non_c_dll(root,prev,head);
    root=head;
    node * temp;
    
    for(temp=root;temp!=NULL;temp=temp->right) {
            cout<<temp->data<<" ";
        }
    
}
