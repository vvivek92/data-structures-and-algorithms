#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_val(int sum, vector<int> &v, int i) {
    vector<int> prev_in(v.size());
    vector<int> prev_out(v);
    int maxi=-1;

    prev_in[0]=v[0];
    maxi=prev_out[0];
    for(i=1;i<v.size();i++) {
        prev_in[i] = max(prev_in[i-1]+ v[i], prev_out[i-1] + v[i]);
        if(prev_in[i] > maxi) maxi=prev_in[i];
        if(prev_out[i] > maxi) maxi=prev_out[i];
    }
    return maxi;    
}


int main(void ) {
    //assuming atleast one positive number exists
    vector<int > v= {-2,11,-4,13,-5,2};
    
    cout<<" "<<max_val(0,v,0);


}
