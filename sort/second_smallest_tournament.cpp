#include<iostream>
#include<vector>
using namespace std;






void create_tournament(vector<int> &v, vector<int> & tournament) {
    

}


int main(void ) {
    vector<int> v;
    for(int i=500;i>=0;i--)
        v.push_back(i);

    vector<int> tournament;
    create_tournament(v, tournament);
    cout<< second_largest(tournament);
    return 0;
}



















