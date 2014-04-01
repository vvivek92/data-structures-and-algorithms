#include <iostream>
using namespace std;
#include<climits>

int find_majority(int arr[],int begin,int end) {
    int count=0; int elem =-1;
    for(int i=begin;i!=end;i++) {
        if(count==0) {
           elem=i;
           count++;
        }
        if(count!=0) {
            if(arr[elem]==arr[i]) count++;
            else count--;
        }
    } 
    count=0;
    for(int i=begin;i!=end;i++) {
        if(arr[i]==arr[elem])count++;
    }
    if(count >= (end-begin)/2)
        return arr[elem];
    else
        return INT_MIN;
    
}


int main(void) {
   int arr[] = {1,2,1,1,3,5,1,6,1,7};
   cout<<find_majority(arr,0,10);

}


