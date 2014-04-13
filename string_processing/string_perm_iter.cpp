#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

void permu(char * s, size_t len) {
    sort(s,s+len);
    do {
        cout<<s<<endl;

    }while(next_permutation(s,s+len));

}


int main() {
    char s [] ="bii";
    permu(s,strlen(s));

}
