#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
struct node {
    int value;
    struct node * next;
    struct node * prev;
};

struct node * first,*second, *third;

void print_tower(void) {
    struct node * temp1,*temp2,*temp3;
    temp1=first;temp2=second;temp3=third;
    cout<<endl;
    
    while(temp1 || temp2 || temp3) {
        if(temp1)  { cout<< temp1->value; temp1=temp1->next;}
        cout<<"    | ";
        if(temp2) { cout<< temp2->value; temp2=temp2->next;}
        cout<<"    | ";
        if(temp3)  { cout<< temp3->value; temp3=temp3->next;}
        cout<<"     ";
        cout<<endl;
    }
}

struct node * getlast(struct node * n){
    if(n==NULL) return NULL;
    struct node * temp;
    for( temp=n;temp->next!=NULL;temp=temp->next);
    return temp;
}

void tower_of_hanoi(int number_rings,struct node ** src,struct node* *extra,struct node ** dest){
    struct node * n,* n2;
    if(number_rings==1) {
        n = getlast(*src);
        if(n->prev)n->prev->next=NULL;
        else *src=NULL;
        n2= getlast(*dest);
        if(n2) {
            n2->next=n;
            n->prev=n2;
            n->next=NULL;
        }
        else {
            *dest=n;
            n->prev=NULL;
            n->next=NULL;
        }
        return;
    }
    tower_of_hanoi(number_rings-1, src, dest,extra);
        n = getlast(*src);
        if(n->prev)n->prev->next=NULL;
        else *src=NULL;
        n2= getlast(*dest);
        if(n2) {
            n2->next=n;
            n->prev=n2;
            n->next=NULL;
        }
        else {
            *dest=n;
            n->prev=NULL;
            n->next=NULL;
        }
    tower_of_hanoi(number_rings-1,extra, src,dest);
    

}
int main() {
    first=second=third=NULL;
    int number_rings;
    while(true) {
        std::cout<<"Enter the number of rings:\n";
        std::string s;
        getline(std::cin, s);
        std::stringstream ss(s);
        ss>>number_rings;
        if(ss.fail()==false) 
                break;
    }
    for(int i=1;i<=number_rings;i++) {
        struct node * temp= new struct node;
        temp->value=i;
        temp->next=first;
        temp->prev=NULL;
        if(first!=NULL)first->prev=temp;
        first=temp;
    }
    print_tower();
    cout<<first<<second<<third<<endl;
    tower_of_hanoi(number_rings,&first,&second,&third);
    cout<<first<<second<<third<<endl;
    print_tower();
} 



