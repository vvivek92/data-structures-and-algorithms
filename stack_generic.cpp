#include<iostream>
#include<memory>
using namespace std;

template<class T>
struct node {
    T data;
    node<T> * next;
};

template <class T>
class stack_generic {
    private:
       node<T> *  head;
    public:
       stack_generic():head(NULL) {}
       void push(T x) {
           node<T> * temp(new node<T>());
           temp->data=x;
           temp->next=head;
           head=temp;
       }           
       T pop(void) {
           T x=T();
           if(head==NULL) {cout<<"underflow!"; return x;}
           else {
                 
               node<T> * temp=head;
               head=head->next;
               x=temp->data;
               delete temp;
               return x;
           }
       }
};

int main(){
    stack_generic<int> s;
    s.push(1);s.push(2);
    cout<<s.pop();
    cout<<s.pop();

    
}



