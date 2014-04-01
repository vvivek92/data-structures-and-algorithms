#include<stdio.h>

int main(void) {
    static int i=5;
    if(--i)
        printf("%d",i);
   else
       return 0;
   main();



}
