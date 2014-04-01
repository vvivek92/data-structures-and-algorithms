#include<vector>
#include<algorithm>
#include "graph_adj.cpp"
#include "disjoint_set.cpp"
using namespace std;

struct edgel {
    int weight;
    int vertex_a;
    int vertex_b;
};

void add_edge(int vertex_a, int vertex_b, int weight, vector<edgel> & list) {
    edgel e;
    e.weight=weight;
    e.vertex_a=vertex_a;
    e.vertex_b=vertex_b;
    list.push_back(e);
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
    //g->print();
    //g->print();
    disjoint_set dset(7);
    vector<edgel> edge_list;
    add_edge(0,2,7,edge_list);
    add_edge(0,3,5,edge_list);
    add_edge(1,2,8,edge_list);
    add_edge(1,4,5,edge_list);
    add_edge(4,2,7,edge_list);
    add_edge(3,2,9,edge_list);
    add_edge(3,4,15,edge_list);
    add_edge(3,5,6,edge_list);
    add_edge(4,6,9,edge_list);
    add_edge(5,6,11,edge_list);
    add_edge(4,5,8,edge_list);
    sort(edge_list.begin(), edge_list.end(), [] (const edgel & lhs, const edgel & rhs) {return lhs.weight < rhs.weight;});
    for(auto i=edge_list.begin();i!=edge_list.end();i++)
        dset.unionof((*i).vertex_a,(*i).vertex_b);
    dset.print();

    
    return 0;    
}
