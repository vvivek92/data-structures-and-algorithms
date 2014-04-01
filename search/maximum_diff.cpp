// given an array A[] find maximum j-i such that A[j] > A[i]

#include<iostream>
using namespace std;

int find(int arr[], int begin, int end) {
    if(end<=begin) return -1;
    else if(arr[begin] <  arr[end-1]) 
        return end-1-begin;
    else if(arr[begin+1] <  arr[end-1] || arr[begin] <  arr[end-2]) 
        return end-2-begin;
    else
        return find(arr, begin+1,end-1);
}
int main(void) {
    int arr[] = {34,8,10,3,2,80,30,33,1};
    cout<<find(arr,0,sizeof(arr)/sizeof(arr[0]));

}
