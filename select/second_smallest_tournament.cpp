#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<climits>




void create_tournament(vector<int> &v, vector<int> & tournament) {
    vector<int>::iterator itr;
    int i=v.size();
    for(itr=v.begin();itr!=v.end();itr++)
        tournament[i++]=*itr;
    i=v.size()-1;
    for(;i>0;i--)
        tournament[i]=max(tournament[2*i], tournament[2*i+1]);
}

int second_largest(vector<int> & tournament) {
    if(tournament.size() ==2) cout<<"doesnt exist";
    int second_large=INT_MIN;
    int i=1;
    while(2*i< tournament.size()) {
        int temp=INT_MIN;
        if(2* i+1 < tournament.size()) {
            if(tournament[2*i]==tournament[1]) {temp = 2*i+1;i*=2;}
            else {temp=2*i;i=i*2+1;}
            if(tournament[temp] > second_large) second_large=tournament[temp];
        }
        else i=2*i; 
    }
    return second_large;
}

int main(void ) {
    vector<int> v;
    for(int i=300;i>=0;i--)
        v.push_back(i);
    int size= v.size()*2;
    vector<int> tournament(size);
    create_tournament(v, tournament);
    cout<< second_largest(tournament);
    return 0;
}



















