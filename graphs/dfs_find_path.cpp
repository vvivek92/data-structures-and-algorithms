#include<vector>
#include<algorithm>
#include "graph_adj.cpp"
using namespace std;

int dfs(shared_ptr<graph> & g,int from,int to) {
    static vector<int> seen(7,-1);
    if(from==to ){
        cout<<endl<<" "<<from;
        return 1;
    }
        seen[from]=1;
        vector<int> neigh;
        g->get_neighbours(from, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==-1) {
                if(dfs(g,neigh.back(),to)) {
                    cout<<" "<<from;
                    return 1;

                }
            }
            neigh.pop_back();
        }
        return 0;
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
    if(dfs( g,0,1 )) cout<<"found";
    return 0;    
}
