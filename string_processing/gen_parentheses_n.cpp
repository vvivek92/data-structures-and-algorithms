#include<iostream>


void gen_par(int open, int close, int pair, char * s) {
    if(open==pair && close==pair) {
        std::cout<<s-6<<std::endl;
    }
    if(open<pair) {
        *s='(';
        gen_par(open+1,close,pair,s+1);
    }
    if(close < open) {
        *s=')';
        gen_par(open,close+1,pair,s+1);
    }

}
int main() {
    char s[7];
    s[6]='\0';
    gen_par(0,0,3,s);

}
