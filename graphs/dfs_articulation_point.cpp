#include<vector>
#include<algorithm>
#include "graph_adj.cpp"
#include "disjoint_set.cpp"
#include <queue>
using namespace std;

void dfs_visit(shared_ptr<graph> & g,int i,vector<int> & seen,vector<int> &parent,vector<int> &dt,vector<int> &low) {
    static int time=0;
    dt[i]=low[i]=++time;
    seen[i]=1;
    int children=0;
        vector<int> neigh;
        g->get_neighbours(i, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==0) {
                children++;
                parent[neigh.back()]=i;
                dfs_visit(g,neigh.back(),seen,parent,dt,low);
                low[i]=min(low[i],low[neigh.back()]);
                if(parent[i]== -1 && children >1)
                    cout<<"ap found at "<<i ;
                if(low[neigh.back()] > dt[i]) 
                    cout<<"ap found at "<<i ;
            }
            else if(parent[i]!= neigh.back() )
                low[i]=min(low[i], dt[neigh.back()]);
            neigh.pop_back();
        }
}
void dfs(shared_ptr<graph> & g, int x) {
    vector<int> seen(7,0);
    vector<int> parent(7,-1);
    vector<int> dt(7,-1);
    vector<int> low(7,-1);
    for(int i=0;i<7;i++) {  // iterating through all vertices
        if(seen[i]==0)
            dfs_visit(g,i,seen,parent,dt,low);
    }

}

int main () {
    shared_ptr<graph> g (new graph_adj(7));
    g->add_edge(0,2,7);
    g->add_edge(0,1,5);
    g->add_edge(1,2,8);
    g->add_edge(0,3,11);
    g->add_edge(4,3,8);
    dfs( g,0 );
    return 0;    
}
