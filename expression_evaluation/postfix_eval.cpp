#include<stack>
#include<string>
#include<iostream>
using namespace std;
// Making asumptions about string, proper implementation 
//would involve string streams
void eval (string & post_fix) {
    stack<int> s;
    int a,b,c;
    for(int i=0;post_fix[i]!='\0';i++) {
        if(post_fix[i]<='9' && post_fix[i] >='0') {
            s.push(post_fix[i]-'0');
        }
        else {
            if(!s.empty()) {a =s.top();s.pop();}
            if(!s.empty()) {b =s.top();s.pop();}
            if(post_fix[i]=='+')
                c=a+b;    
            else if(post_fix[i]=='-')
                c=b-a;
            else if(post_fix[i]=='*')
                c=a*b;
            s.push(c);
       }   
    }
    cout<<"\nThe expression 345*+123+*-1- equals"<<s.top()<<endl;
}


int main() {
    string s= "3+4*5-1*(2+3)-1";
    string post_fix="345*+123+*-1-";
    eval(post_fix);
    return 0;
}
