#include<iostream>
#include<vector>
using namespace std;


void counting_sort( vector<int> & v, int k) {
    vector<int> cumm_cnt(k+1,0);
    vector<int> temp(v.size());

    for(vector<int>::iterator itr=v.begin();itr!=v.end();itr++)
        cumm_cnt[*itr]++;

  //  for(vector<int>::iterator itr=cumm_cnt.begin()+1;itr!=v.end();itr++)
  //      *itr=(*itr+*(itr-1));
     for(int i=1;i<k+1;i++)
         cumm_cnt[i]+=cumm_cnt[i-1];
     for(auto itr=v.end()-1;itr>=v.begin();itr--) {
         cumm_cnt[*itr]--;
         temp[cumm_cnt[*itr]]=*itr;   
     }
     int i=0;
     for(auto itr=v.begin();itr!=v.end();itr++)
         *itr=temp[i++];
}

void bubble_sort( vector<int> & v, int k) {
    vector<int> cnt(k+1,0);
    vector<int> temp(v.size());

    for(vector<int>::iterator itr=v.begin();itr!=v.end();itr++)
        cnt[*itr]++;
   int j=0;
   for(int i=0;i<cnt.size();i++) {
       for(;j<v.size() && cnt[i]>0;j++)
           {v[j]=i;cnt[i]--;}
   }
}


int main() {
    int arr[]= { 0,1,2,1,2,2,1,0,0,0,1,2,1,0};
    vector<int> v(&arr[0],&arr[14]) ;
    vector<int>::iterator itr;
    cout<<endl;
    for(itr=v.begin();itr!=v.end();itr++)
        cout<<" "<<*itr;
    cout<<endl;
    //counting_sort(v,2);
    bubble_sort(v,2);
    cout<<endl;
    for(itr=v.begin();itr!=v.end();itr++)
        cout<<" "<<*itr;
    cout<<endl;
    
}




