#include<iostream>
#include<queue>
#include<vector>
#define V 4
using namespace std;
bool isBipartite(int G[][V], int start) {
   vector<int> color(V,-1);
   color[start]=0;
   queue<int> q;
   q.push(start);
   while(!q.empty()) {
        int temp=q.front();
        q.pop();
        for(int i=0;i<V;i++) {
            if(G[temp][i] && color[i]==-1) {
                color[i]=1-color[temp];
                q.push(temp);
            }
            else if(G[temp][i] && color[i]==color[temp])
                return false;
        }
   }
   return true; 
}

int main() {
    int G[][V] = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0},
     };
    isBipartite(G,0)? cout<<"Yes":cout<<"No";
    return 0;
}
