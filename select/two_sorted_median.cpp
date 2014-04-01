#include<iostream>
using namespace std;



double find_median(int arr1[],int arr2[], int begin1, int end1, int begin2, int end2) {
    int median1=begin1+(end1-begin1)/2;
    int median2=begin2+(end2-begin2)/2;
   // cout<<begin1<<" "<<median1<<" "<<end1<<endl;
    if(median1+1==end1 && median2+1==end2) {
        cout<<median1<<" "<<median2<<endl;
        return (static_cast<double>(arr1[median1] + arr2[median2]))/2;
}
    if(arr1[median1] < arr2[median2])
        return find_median(arr1,arr2,median1+1, end1, begin2, median2);
   else 
       return  find_median(arr1, arr2, begin1, median1, median2+1,end2);
}




int main(void) {

    int arr1[]={1,2,3,4,5,6,10};
    int arr2[]={23,41,67,98,100,103,127};
//    int arr1[] = {2,3,7};
 //   int arr2[] = {6,9,10};
    cout<<find_median(arr1,arr2,0,sizeof(arr1)/sizeof(arr1[0]),0,sizeof(arr2)/sizeof(arr2[0]));

}
