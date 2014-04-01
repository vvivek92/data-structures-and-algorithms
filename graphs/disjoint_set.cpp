#include<vector>
#include<iostream>

using namespace std;

class disjoint_set {
    private:
        vector<int> parent;
    public:
        disjoint_set(const int & size);
        int find(int x);      
        void unionof(int a, int b);
        void print(void);
};
 
disjoint_set::disjoint_set(const int & size):parent(size,-1) {
}
int disjoint_set::find(int x) {
    if(parent[x] < 0) return x;
    else 
        return (parent[x]=find(parent[x])); 
}
void disjoint_set::unionof(int a, int b) {
    int parent_a=find(a);
    int parent_b=find(b);
    if(parent_a == parent_b) return;
    cout<<" verte"<<a<<"verte"<<b;
    if(parent[parent_a] < parent[parent_b]) {
        parent[parent_a]+= parent[parent_b];
        parent[parent_b]=parent_a;
    }
    else  {
        parent[parent_b]+= parent[parent_a];
        parent[parent_a]=parent_b;
    }
    
}
        
void  disjoint_set:: print(void) {
    vector<int>::const_iterator i;
    cout<<endl;
    for(i=parent.begin();i!=parent.end();i++)
        cout<<" "<<*i;
    cout<<endl;
}

