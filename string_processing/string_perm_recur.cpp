#include<iostream>
#include<cstring>

using namespace std;

void permu(char * s, int begin, size_t size ) {
    if(begin==size) {
        cout<<s<<endl;
    }
   else {
       int i;
       for(i=begin;i<size;i++) {
           iter_swap(s+i,s+begin);
           permu(s,begin+1,size);
           iter_swap(s+i,s+begin);
       }
   }
}


int main(void) {
    char s [] ="bii";
    permu(s,0,strlen(s));

}
