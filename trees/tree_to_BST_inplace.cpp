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
    cout<<root->data<<" ";
    print_inorder(root->left);
    print_inorder(root->right);
}

void root tree_to_dll(node * root,node ** head, node ** tail) {
    if(root==NULL) *head=*tail=NULL;
    
    

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
    node ** head,**tail;
    tree_to_dll(root,head,tail);
    node * root=mergesort_ll(root);
    node * root = dll_to_root(root);
 

    cout<<endl;
    print_inorder(root);
    cout<<endl;


}
