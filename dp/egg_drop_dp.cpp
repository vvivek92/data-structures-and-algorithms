#include<vector>
#include<iostream>
#include<climits>
using namespace std;
int egg_drop(int k, int n) {
    int arr[k+1][n+1];
    for(int i=1;i<=n;i++) {
        arr[0][n]=0;
        arr[1][n]=1;
    } 
    for(int i=1;i<=k;i++)
        arr[i][1]=i;
    int min=INT_MAX,temp=0;
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=k;j++) {
            min=INT_MAX;
            for(int x=1;x<=j;x++) {
                temp = max(1+ arr[x-1][i-1],1+arr[j-x][i]);
                if(min>temp) {
                    min=temp;
                }
            }
            arr[j][i]=min;
        }
    }  
    return arr[k][n];
}
int main() {
    cout<<egg_drop(100,2);
}




