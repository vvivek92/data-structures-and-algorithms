#include<iostream>
using namespace std;

int isPalindrome(int x) {
    if(x==0 || x/10==0) return 1;
    int last=10,first=10;
    while(x/first)
        first*=10;
    first/=10;

    while(first>= last) {
        int a = x/first;
        a=a%10;
        int b=x%last;
        b=b/(last/10);
        if(a!=b)
            return 0;
        first/=10; last*=10;

    }
    return 1;

}


int main(void) {
    cout<<isPalindrome(11211);
}


