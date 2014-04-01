#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_val(int sum, vector<int> &v, int begin) {
    if(begin==v.size()) return sum;
    int temp= max(max_val(sum + v[begin],v, begin+1), max_val(v[begin],v, begin+1 ) ) ;
    return max(temp,sum);
}


int main(void ) {
    //assuming atleast one positive number exists
    vector<int > v= {-2,11,-4,13,-5,2};
    
    cout<<" "<<max_val(0,v,0);


}
