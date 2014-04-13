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

node * util(node * root) {
    if(root==NULL) return NULL;
    if(root->left) {
        node * left = util(root->left);
        while(left->right)
            left=left->right;
        left->right=root;
        root->left=left;
    }
    if(root->right) {
        node * right =util(root->right);
        while(right->left)
            right=right->left;
        right->left=root;
        root->right=right;
    }    
    return root;
}


node * tree_to_bst(node * root) {
    root=util(root);
    while(root->left)
        root=root->left;
    return root;

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
    root=tree_to_bst(root);     
    node * temp;
    for(temp=root;temp!=NULL;temp=temp->right)
        cout<<temp->data<<" ";

}
