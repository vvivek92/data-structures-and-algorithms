#include<stdio.h>



int atoi(const char * c) {
    if(c==NULL) return 0;
    int temp=0;
    while(*c ==' ' && *c !='\0')
        c++;
    if(*c=='\0')
        return temp;
    while(*c<='9' && *c>='0' && *c !='\0') {
        temp=10*temp+ *c-'0';
        c++;
    }
    return temp;

}

int main() {
    printf("%d\n",atoi(" 12345"));
    printf("%d\n",atoi("  178"));
    printf("%d\n",atoi("  123asd4"));
    printf("%d",atoi("12f33"));
}



