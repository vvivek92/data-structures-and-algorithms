#include<iostream>
#include<queue>
#include<cmath>
#define NDEBUG
#include<cassert>
using namespace std;

int get_digit(int num, int place) {
    // 1257   place=3    ( 1257% 10^place) / 10^(place-1)
    assert(place>=1);
    return (num%static_cast<int>(pow(10,place)))/static_cast<int>(pow(10, place-1));

}


void radix_sort(int arr[], int begin, int end) {
    if(end<=begin) return;
    static vector<queue<int> > v_q(10);
    for(int place=1;;place++) {
        for(int i=begin;i!=end;i++) {
            v_q[get_digit(arr[i],place)].push(arr[i]);
        }
        if(v_q[0].size()==end-begin) break;
    int j=begin;
        for(int i=0;i<10;i++) {
            while(v_q[i].size()) {
                arr[j++]=v_q[i].front();
                v_q[i].pop();
            }
        }
   }
   for(int i=begin;v_q[0].size();i++) {
       arr[i]=v_q[0].front();
       v_q[0].pop(); 
   }
}

int main() {
    int arr[5]={802,8,127,35,22};
    radix_sort(arr,0,5);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<endl;
}
