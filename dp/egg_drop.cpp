#include<vector>
#include<iostream>
#include<climits>
using namespace std;
static vector<int> drop_floor;
int egg_drop(int k, int n) {
    if(k==0 || k==1)
        return k;
    if(n==1)
        return k;
    int min=INT_MAX,temp=0;
    for(int x=1;x<=k;x++) {
        temp = max(1+ egg_drop(x-1,n-1),1+egg_drop(k-x,n));
        if(min>temp) {
            min=temp;
        }
    }
    return min;
}
int main() {
    cout<<egg_drop(100,2);
}




