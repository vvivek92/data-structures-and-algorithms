#include<iostream>
#include<string.h>
using namespace std;

/*
int is_rotation(const char * a ,const  char * b) {
    char temp[2] = {a[0],'\0'};
    const char * bi= strstr(b, temp );
    for(int i=0;a[i]!=0;i++) {
        if(bi[i]=='\0') bi=b-i;
        if(a[i] != bi[i])
            return 0;
    }  
    return 1;
}  
*/
int is_rotation(const char * a,const  char * b) {
    int l=strlen(a);
    int l2=strlen(b);
    if(l!=l2)
        return 0;
    char temp[2*l+1];
    strcpy(temp,a);
    strcat(temp,a);
    return (strstr(temp,b)!=NULL);
}



int main(void) {
    const char * a ="ABCD";
    const char * b ="CDAB";
    cout<<is_rotation(a,b);


}
