#include<iostream>
#include<vector>
using namespace std;

int brute_force(vector<int> & arr,vector<int> & pattern) {

    for(int i=0;i < arr.size();i++) {
        int j;
        for(j=0;j<pattern.size();j++){
            if(arr[i+j]!=pattern[j])
                break;
        }
        if(j==pattern.size()) return 1;
    }
    return 0;
}

int main(void) {
    vector<int> arr1={1,2,3,5,6,7,8,9,0,1,2,3,4,6};
    vector<int> pattern={1,3,4,9};
    vector<int> arr2 ={1,2,3,5,6,7,8,9,0,1,3,4,9,2};
    cout<<" "<<brute_force(arr2,pattern);
    cout<<" "<<brute_force(arr1,pattern);
    cout<<" "<<brute_force(pattern,pattern);

}
