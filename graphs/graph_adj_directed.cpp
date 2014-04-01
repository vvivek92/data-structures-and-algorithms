#include<vector>
#include<list>
#include<iostream>
#include "graph.hpp"
#include <memory>
using namespace std;

struct edge {
    int vertex;
    int weight;
};

class graph_adj_directed: public graph {
    public:
        virtual void print();
        virtual int is_connected(int x, int y);
        virtual void add_edge(int x,int y, int weight);
        virtual void remove_edge(int x, int y);
        graph_adj_directed(int vertices);
        virtual ~graph_adj_directed();
        virtual void get_neighbours(int x, vector<int> &v);
    //private:
        vector<list<edge> > adj;
};

void graph_adj_directed::get_neighbours(int x, vector<int> &v) {
    for(auto i= adj[x].begin();i!=adj[x].end();i++)
        v.push_back((*i).vertex);
}
void graph_adj_directed::print() {
    int index=0;
    cout<<endl<<"printing adjacency list" <<endl;
    for(auto i = adj.begin();i!=adj.end();i++) {
        cout<<endl;
        cout<<index++ <<" ";
        for(auto j=(*i).begin();j!=(*i).end();j++) {
            cout<<" "<<(*j).vertex;
        }
        cout<<endl;
    }
}

int graph_adj_directed::is_connected(int x, int y) {
    for(auto i= adj[x].begin();i!=adj[x].end();i++)
        if((*i).vertex==y) return (*i).weight;
    return 0;
}
void graph_adj_directed::add_edge(int x,int y,int weight) {
    edge e;
    e.vertex=y;
    e.weight=weight;
    adj[x].push_front(e);
}
void graph_adj_directed::remove_edge(int x, int y) {
    for(auto i=adj[x].begin();i!=adj[x].end();i++) {
        //cout<<endl<<"YO "<<(*i).vertex<<endl;
        if((*i).vertex==y) {
           adj[x].erase(i);
           break;
        }
    }
}
graph_adj_directed::graph_adj_directed(int vertices): adj(vertices) {}
graph_adj_directed::~graph_adj_directed() { }


