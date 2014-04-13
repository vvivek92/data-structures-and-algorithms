#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}



Node * find_lca(Node * root,int a, int b, int &a_seen, int & b_seen) {
    if(root==NULL) return NULL;
    if(root->key ==a) {
        a_seen=1;
        return root;
    }
    if(root->key ==b) {
        b_seen=1;
        return root;
    }
    Node * left= find_lca(root->left,a,b,a_seen,b_seen);
    Node * right= find_lca(root->right,a,b,a_seen,b_seen);
    if(left && right) return root;
    return (left?left:right);

}
Node * find(Node * root, int x) {
    if(root==NULL) 
        return NULL;
    else if(root->key==x) 
        return root;
    else {
        Node * temp=NULL;
        if(temp = find(root->left,x))
            return temp;
        if(temp = find(root->right,x))
            return temp;
    }
    return NULL;
}

Node * lca(Node * root, int a, int b) {
     int a_seen=0,b_seen=0;
    Node * n=find_lca(root,a,b,a_seen,b_seen);
    if(a_seen && b_seen)
        return n;
    else if(!a_seen && !b_seen)
        return NULL;
    else {
        if(a_seen)
            if(find(n,b))
                return n;
        if(b_seen)
            if(find(n,a))
                return n;
    }
    return NULL;
}

int findDistance(Node * root, int a , int b) {
    cout<<"lca "<<lca(root,a,b)->key<<endl;
    return 0;
}


int main() {
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
} 




