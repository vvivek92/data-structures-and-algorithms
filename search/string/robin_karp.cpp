#include<iostream>
#include<vector>
using namespace std;


int find_hash(vector<int> & v, int begin, int end) {
    int sum=0;
    for(int i=begin;i<end;i++) {
        sum=10*sum+v[i];
    }
    return sum;
}

int compare(vector<int> & v, int index, vector<int> & pattern) {
    int j;
    for( j=0;j<pattern.size() && v[index+j] == pattern[j];j++);
    if(j== pattern.size()) return 1;
    return 0;
}
int robin_karp(vector<int> & arr,vector<int> & pattern) {

    int p_hash= find_hash(pattern,0,pattern.size());

    int text_hash=find_hash(arr,0,pattern.size());
    if(p_hash == text_hash)
         if( compare(arr,0,pattern))
             return 1;
    int prev_text_hash=text_hash;
    for(int i=1;i < arr.size()-pattern.size() +1 ;i++) {
        text_hash=( prev_text_hash - 1000*arr[i-1] )*10;
        text_hash+=arr[i+pattern.size()-1];   
    
    if(p_hash == text_hash)
         if( compare(arr,i,pattern))
             return 1;
    prev_text_hash=text_hash;
     
    }
    return 0;
}

int main(void) {
    vector<int> arr1={1,2,3,5,6,7,8,9,0,1,2,3,4,6};
    vector<int> pattern={1,3,4,9};
    vector<int> arr2 ={1,2,3,5,6,7,8,9,0,1,3,4,9,2};
    cout<<" "<<robin_karp(arr2,pattern);
    cout<<" "<<robin_karp(arr1,pattern);
    cout<<" "<<robin_karp(pattern,pattern);

}
