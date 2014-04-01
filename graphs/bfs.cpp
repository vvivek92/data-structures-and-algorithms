#include<vector>
#include<algorithm>
#include "graph_adj.cpp"
#include "disjoint_set.cpp"
#include <queue>
using namespace std;

void bfs(shared_ptr<graph> & g, int x) {
    queue<int> q;
    vector<int> seen(7,0);
    vector<int> parent(7,-1);
    vector<int> distance(7,-1);
    
    q.push(x);
    seen[x]=1;
    distance[x]=0; 
    cout<<endl;
    while(!q.empty()) {
        vector<int> neigh;
        int temp=q.front();
        q.pop();
        cout<<" "<<temp;
        g->get_neighbours(temp, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==0) {
                q.push(neigh.back());
                parent[neigh.back()]=temp;
                distance[neigh.back()]=distance[temp]+1;
                seen[neigh.back()]=1;
            }
            neigh.pop_back();
        }
    }
    vector<int>::iterator i;
    cout<<endl;
    for(i=parent.begin();i!=parent.end();i++)
        cout<<" "<<*i;
    cout<<endl;
    cout<<endl;
    for(i=distance.begin();i!=distance.end();i++)
        cout<<" "<<*i;
    cout<<endl;
}
int main () {
    shared_ptr<graph> g (new graph_adj(7));
    g->add_edge(0,2,7);
    g->add_edge(0,3,5);
    g->add_edge(1,2,8);
    g->add_edge(1,4,5);
    g->add_edge(4,2,7);
    g->add_edge(3,2,9);
    g->add_edge(3,4,15);
    g->add_edge(3,5,6);
    g->add_edge(4,6,9);
    g->add_edge(5,6,11);
    g->add_edge(4,5,8);
    bfs( g,0 );
    
    
    return 0;    
}
