#include<vector>
#include<algorithm>
#include "graph_adj.cpp"
#include "heap.cpp"
#include<climits>
using namespace std;



void prim_mst(shared_ptr<graph> & g, int x) {
    pq pq_inst(7);
    vector<int> seen(7,0);
    vector<int> parent(7,-1);
    for(int i=0;i<7;i++)
        pq_inst.insert(i,INT_MAX);
    pq_inst.update_weight(x,0);
    int mst=0;
    while(pq_inst.size()) {
        vector<int> neigh;
        int a,b;
        pq_inst.find_min(a,b);
        mst+=b;
        seen[a]=1;
        pq_inst.delete_min();
         
        g->get_neighbours(a, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==0) {
                if(pq_inst.find_weight(neigh.back())> g->is_connected(neigh.back(),a) ) {
                    pq_inst.update_weight(neigh.back(),g->is_connected(neigh.back(),a));
                    parent[neigh.back()]=a;
                }
            }
            neigh.pop_back();
        }
    }
    cout<<"the mst is: "<<mst<<endl;
    for(int i=0;i<7;i++)
        cout<<" "<<parent[i];
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
    prim_mst( g,0 );
    
    
    return 0;    
}
