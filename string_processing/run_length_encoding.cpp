#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
void rle(char * s,char *d ) {
    int is=0,id=0;
    while(s[is]!='\0') {
        d[id++]=s[is++];
        int count=1;
        while(s[is]==s[is-1]) {
            count++;
            is++;
        }
        char c[5];
        sprintf(c,"%d",count);
        int i=0;
        while(c[i]!='\0')
            d[id++]=c[i++];
    }
    d[id]='\0';

}

int main() {
    char s[100] ="geeksforgeeks";
    char d[100];
    rle(s,d);
    std::cout<<d;
}
