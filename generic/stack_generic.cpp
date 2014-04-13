#include<iostream>
#include<memory>
#include<stdexcept>
#include<exception>
using namespace std;

template<class T>
struct node {
    T data;
    unique_ptr< node<T> >  next;
};

template <class T>
class stack_generic {
    private:
       unique_ptr<node<T> >  head;
    public:
       stack_generic() {}
       void push(T x) {
           unique_ptr< node<T>  > temp((new node<T>()));
           temp->data=x;
           temp->next=move(head);
           head=move(temp);
       }           
       T top(void) {
           if(head==NULL) {throw runtime_error("error");}
           else {
               return head->data;
           }
       }
       void pop(void) {
           if(head==NULL) {throw runtime_error("error");}
           else {
               unique_ptr<node<T> > temp=move(head);
               head=move(temp->next);
               temp.reset();
           }

       }
};

int main(){
    stack_generic<int> s;
    s.push(1);s.push(2);
    cout<<s.top();
    s.pop();
    cout<<s.top();
    s.pop();
    
}



