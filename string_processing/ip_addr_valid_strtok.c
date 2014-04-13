#include<stdio.h>
#include<string.h>

int is_digit(char * s) {
    if(s==NULL || *s=='\0') return 0;
    for(;*s!='\0';s++){
        if(*s<'0' || *s>'9')
            return 0;
    }
    return 1;
}

void valid_ip(char * s) {
    char * holder=NULL;
    int dots=0;
    holder=strtok(s,".");
    if(!is_digit(holder))
        return ;
    int temp=atoi(holder);
    if(temp<0 || temp>255)
        return ;
    do {
       holder=strtok(NULL,".");
       if(!is_digit(holder)) 
           break;
       temp=atoi(holder);
       if(temp>=0 && temp<=255)
           dots++;
       else 
          break;
    } while(holder);
    if(dots==3) printf("valid");
    else printf("invalid");
}


int main() {
   char c []="236.0.0.225";
   valid_ip(c);

}

