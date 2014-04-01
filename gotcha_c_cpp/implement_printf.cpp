#include<sstream>
#include<iostream>
#include<string>
#include<cstdarg>
using namespace std;

string my_printf(const char * s,...) {
    stringstream ss;
    va_list arguments;
    va_start(arguments,s);
    for(int i=0;s[i]!=0;i++) {
        if(s[i]=='%' && s[i+1] =='d') {
            i++;
            ss<<va_arg(arguments,int);
        }
        else if(s[i]=='%' && s[i+1] =='s') {
            i++;
            ss<<va_arg(arguments,char *);
        }
        else {
            ss<<s[i];
        }
 

    }

    va_end(arguments);
    return ss.str();
}



int main() {
    string s=my_printf("hello world %d %s",12,"wert");
    cout<<s;


}

