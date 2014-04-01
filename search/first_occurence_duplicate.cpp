#include<iostream>
using namespace std;

int search(int arr[], int begin, int end, int data) {
    if(end<=begin) return -1;
    int mid = begin + (end-begin)/2;
    if(arr[mid] ==data && begin ==mid || arr[mid]==data && arr[mid-1] < data)
        return mid;
    
    if(arr[mid] >= data)
        return search(arr,begin,mid-1,data);
    else {
        return search(arr,mid+1,end,data);
   }
}

int main(void) {
    int arr[] = {0,1,4,5,5,5,5,5,7,8,10};
    int index=search(arr,0,sizeof(arr)/sizeof(arr[0]),5 );
    cout<<endl<<index<<" "<<arr[index]<<endl;
}


