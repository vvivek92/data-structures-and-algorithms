#include<vector>
#include<algorithm>
#include "graph_adj_directed.cpp"
#include "disjoint_set.cpp"
#include <stack>
using namespace std;

void dfs_visit(shared_ptr<graph> & g,int i,vector<int> & seen,vector<int> &parent,vector<int> &dt,vector<int> &ft,int & time,stack<int> &s) {
    time+=1;
    dt[i]=time;
    seen[i]=1;
        vector<int> neigh;
        cout<<" "<<i;
        g->get_neighbours(i, neigh);
        while(neigh.size()) {
            if(seen[neigh.back()]==0) {
                parent[neigh.back()]=i;
                dfs_visit(g,neigh.back(),seen,parent,dt,ft,time,s);
            }
            else {
                if(dt[neigh.back()] !=-1 && ft[neigh.back()] == -1) {
                    cout<<"we have a cycle in the graph";
                }
            }
            neigh.pop_back();
        }
    s.push(i);
    time+=1;
    ft[i]=time;
}
void dfs(shared_ptr<graph> & g, int x) {
    stack<int> s;
    vector<int> seen(7,0);
    vector<int> parent(7,-1);
    vector<int> dt(7,-1);
    vector<int> ft(7,-1);
    int time=0;
    for(int i=0;i<7;i++) {  // iterating through all vertices
        if(seen[i]==0)
            dfs_visit(g,i,seen,parent,dt,ft,time,s);
    }
    vector<int>::iterator i;
    cout<<endl;
    for(i=parent.begin();i!=parent.end();i++)
        cout<<" "<<*i;
    cout<<endl;
    cout<<endl;
    for(i=dt.begin();i!=dt.end();i++)
        cout<<" "<<*i;
    cout<<endl;
    cout<<endl;
    for(i=ft.begin();i!=ft.end();i++)
        cout<<" "<<*i;
    cout<<endl;

    cout<<endl;
    while(!s.empty()) {
        cout<<" "<<s.top();
        s.pop();
    }
    cout<<endl;

}

int main () {
    shared_ptr<graph> g (new graph_adj_directed(7));
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
    dfs( g,0 );
    return 0;    
}
