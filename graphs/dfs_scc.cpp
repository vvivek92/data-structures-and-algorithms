#include<vector>
#include<algorithm>
#include "graph_adj_directed.cpp"
#include "disjoint_set.cpp"
#include <stack>
using namespace std;

void dfs_visit(shared_ptr<graph_adj_directed> & g,int i,vector<int> & seen,stack<int> &s) {
    seen[i]=1;
        vector<int> neigh;
        cout<<" "<<i;
        g->get_neighbours(i, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==0) {
                dfs_visit(g,neigh.back(),seen,s);
            }
            neigh.pop_back();
        }
    s.push(i);
}

void dfs_visit(shared_ptr<graph_adj_directed> & g,int i,vector<int> & seen) {
    seen[i]=1;
        vector<int> neigh;
        cout<<" "<<i;
        g->get_neighbours(i, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==0) {
                dfs_visit(g,neigh.back(),seen);
            }
            neigh.pop_back();
        }
}

shared_ptr<graph_adj_directed> reverse(shared_ptr<graph_adj_directed> & g) {
    shared_ptr<graph_adj_directed> g2(new graph_adj_directed(5));
    list<edge>::iterator j;
    for(int i=0;i<5;i++)
        for(j=g->adj[i].begin();j!=g->adj[i].end();j++) {
            int from=i;
            int to=(*j).vertex;
            int weight=(*j).weight;
            g2->add_edge(to,from,weight);
        }
      return g2; 

}
void dfs(shared_ptr<graph_adj_directed> & g, int x) {
    stack<int> s;
    vector<int> seen(5,0);
    for(int i=0;i<5;i++) {  // iterating through all vertices
        if(seen[i]==0)
            dfs_visit(g,i,seen,s);
    }
    shared_ptr<graph_adj_directed> g2= reverse(g);
    for(int i=0;i<5;i++)
        seen[i]=0;
    while(!s.empty()) {
        int temp=s.top();
        s.pop();
        if(seen[temp]==0) {
            cout<<endl<<"scc ";
            dfs_visit(g2,temp,seen); 
        }

    }
}

int main () {
    shared_ptr<graph_adj_directed> g (new graph_adj_directed(5));
    g->add_edge(0,2,7);
    g->add_edge(1,0,5);
    g->add_edge(2,1,8);
    g->add_edge(0,3,5);
    g->add_edge(3,4,7);
    dfs( g,0 );
    return 0;    
}
