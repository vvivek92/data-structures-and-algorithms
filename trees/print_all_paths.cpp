#include <queue>
#include <iostream>
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

struct node_ll {
    int data;
    struct node_ll * next;
};
void print_l (node_ll ** a, int size) {
    for(int i=0;i<size;i++) {
        node_ll *b=a[i];
        cout<<endl;
        while(b!=NULL) {
            cout<<b->data<<" ";
            b=b->next;
        }
        cout<<endl;
    }
}

node_ll ** print_all_paths(node * root, int & size) {
    if(root==NULL) return NULL;
    int lsize=0,rsize=0;
    node_ll ** ret_val;
    node_ll ** left= print_all_paths(root->left,lsize);
    node_ll ** right= print_all_paths(root->right,rsize);
    if(!left && !right) {
        ret_val= new node_ll * [1];
        ret_val[0]=new node_ll();
        ret_val[0]->data=root->data;
        ret_val[0]->next=NULL;
        size=1;
    }
    else if(!left && right) {
         ret_val= right;
         for(int i=0;i<rsize;i++) {
             node_ll * temp= new node_ll();
             temp->data=root->data;
             temp->next=ret_val[i];
             ret_val[i]=temp;
         }
         size = rsize;
    }
    else if(left && !right) {
         ret_val= left;
         for(int i=0;i<lsize;i++) {
             node_ll * temp= new node_ll();
             temp->data=root->data;
             temp->next=ret_val[i];
             ret_val[i]=temp;
         }
         size = lsize;
    }
    else {
         ret_val=new node_ll * [lsize + rsize];
         size=rsize+lsize;
         for(int i=0; i <lsize ; i++) {
             ret_val[i]=left[i];
             left[i]=NULL;
         }
         delete [] left;
         for(int i=0; i <rsize ; i++) {
             ret_val[i+lsize]=right[i];
             right[i]=NULL;
         }
         delete [] right;
         for(int i=0;i<size;i++) {
             node_ll * temp= new node_ll();
             temp->data=root->data;
             temp->next=ret_val[i];
             ret_val[i]=temp;
         }
    }
    return ret_val;
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
    node_ll ** a=  print_all_paths(root, size);
    if(a)    print_l(a,size);
    else cout<<"LOL";
     return 0;
}
