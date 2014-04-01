#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


int partition(vector<int> &v, int begin, int end) {
    if(begin==end-1) return begin;
    int i=begin;
    int itr=begin+1;
    for(; itr<end;itr++) {
        if(v[itr]<=v[begin]) {
            i++; 
            swap(v[itr],v[i]);
        }
    }
    swap(v[begin],v[i]);
    return i;
}



int quickselect(vector<int> & v,int begin, int end, int k) {
    if(k<begin || k>=end) return -1;
    int median_medians= find_median(v,begin, end);
    swap(v[begin],v[ median_medians]);
    int partition_index=partition(v,begin, end);
    if(partition_index==k) return v[partition_index];
    int a,b;
    if(partition_index>k) {a=begin;b=partition_index;}
    if(partition_index<k) {a=partition_index+1;b=end;}
    return quickselect(v,a,b,k); 
}

int main(void) {
    vector<int> v;
    for(int i=0;i<12;i++)
        v.push_back(i);
    random_shuffle(v.begin(), v.end());
    for(int i=0;i<12;i++)
        cout<<v[i];
    cout<<endl<<quickselect(v,0,v.size(),3);
}
