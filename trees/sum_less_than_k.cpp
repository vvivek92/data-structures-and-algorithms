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

node * create_tree(void) {
    int i=0;
    node* root=new node();
    root->left=root->right=NULL;
    root->data=i++;
    queue<node *> q;
    q.push(root);
    while(i<13) {
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

node * remove(node * root, int sum, int k) {
    if(root==NULL) return NULL;
    int sum_new=sum+ root->data;
    if(sum_new>=k) return root;
    root->left=remove(root->left,sum_new,k);
    root->right=remove(root->right,sum_new,k);
    if(!root->right && !root->left) {
        delete root;
        return NULL;
    }
    else 
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
 
    print(root);
    int sum=0;
    root=remove(root,sum,99);
    cout<<root->data<<"  00000000000000000000"<<endl;
    print(root);
}
