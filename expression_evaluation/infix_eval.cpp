
#include<stack>
#include<string>
#include<iostream>
using namespace std;
// Making asumptions about string, proper implementation 
//would involve string streams 
int get_priority(char c) {
    if(c== '+' || c=='-')
        return 1;
    if(c=='*')
        return 2;
    else 
        return -1;
}
int calculate(int i, int y, char c) {
    if(c== '+')
        return (i+y);
    if(c== '-')
        return (y-i);
    if(c== '*')
        return (i*y);
}
int eval (string  infix) {
    stack<char> opt_stk;
    stack<int> opd_stk;
    for(int i=0; infix[i]!='\0';i++) {
        if(infix[i] <='9' && infix[i]>='0') {
            opd_stk.push(infix[i]-'0');
        }
        else {
            if(infix[i] == ')') {
                char c;
                //stk.pop();
                while((c=opt_stk.top())!='(') {
                    int i= opd_stk.top();
                    opd_stk.pop();
                    int y= opd_stk.top();
                    opd_stk.pop();
                    int final= calculate(i,y,c);
                    opd_stk.push(final);
                    opt_stk.pop();
                }
                opt_stk.pop();
            }
            else if(infix[i] == '(')
                opt_stk.push(infix[i]);
            
            else {
                while(!opt_stk.empty() && get_priority(infix[i])<= get_priority(opt_stk.top())) {
                    char c=opt_stk.top();
                    int i= opd_stk.top();
                    opd_stk.pop();
                    int y= opd_stk.top();
                    opd_stk.pop();
                    int final= calculate(i,y,c);
                    opd_stk.push(final);
                    opt_stk.pop();
                }
                opt_stk.push(infix[i]);
            }
       }
    }
    
    while(!opt_stk.empty()) {
        char c=opt_stk.top();
        int i= opd_stk.top();
        opd_stk.pop();
        int y= opd_stk.top();
        opd_stk.pop();
        int final= calculate(i,y,c);
        opd_stk.push(final);
        opt_stk.pop();
    }
    return opd_stk.top();    
}


int main() {
    string infix= "3+4*5-1*(2+3)-1";
    string post_fix="345*+123+*-1-";
    int i=eval(infix);
    //if(post_fix.compare(s)==0) 
    cout<<endl<<" "<<i<<endl;
    return 0;
}
