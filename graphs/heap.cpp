#include<vector>
#include<utility>
#include<iostream>
using namespace std;
// min heap
struct node {
    int vertex;
    int weight;
};
class pq {
    private:
        vector<node> heap;
        vector<int> vertex_to_heap_index;
    public:

    pq(int size):vertex_to_heap_index(size,-1) {
    }
    void print(void) {
        vector<node>::const_iterator i;
        cout<<endl;
        for(i=heap.begin();i!=heap.end();i++)
            cout<<" "<<(*i).vertex<<"with weight"<<(*i).weight;
        cout<<endl;
    }
    int size(void) {return heap.size();}
    void insert(int vertex, int weight) {
        node n;
        n.weight=weight;
        n.vertex=vertex;
        heap.push_back(n);
        vertex_to_heap_index[vertex]=heap.size()-1;
        int j=heap.size()-1;
        int parent_j = (j-1)/2;
        while(parent_j>=0 && heap[j].weight< heap[parent_j].weight) {
            swap(heap[j],heap[parent_j]);
            vertex_to_heap_index[heap[j].vertex]=j;
            vertex_to_heap_index[heap[parent_j].vertex]=parent_j;
            j=parent_j;
            parent_j=(j-1)/2;
        }
    }

    bool find_min(int & vertex,int & weight ) {
        if(heap.size()) {
            vertex=heap[0].vertex;
            weight=heap[0].weight;
            return true;
        }
        return false;
    }

    int get_min_trio(int curr) {
        int left_child= (curr+1)*2 -1;
        int right_child=left_child+1;
        int min=curr;
        if(left_child < heap.size())
            if(heap[left_child].weight < heap[min].weight)
                min=left_child;
        if(right_child < heap.size())
            if(heap[right_child].weight < heap[min].weight)
                min=right_child;
        return min;
    }
    void delete_min(void) {
        if(heap.size()==0) {
            return;
    } 
        if(heap.size()==1) {
            node temp=heap[0];heap.pop_back();vertex_to_heap_index[temp.vertex]=-1;return ;
    }
        node temp=heap[0];
        vertex_to_heap_index[heap.back().vertex]=0;
        vertex_to_heap_index[heap[0].vertex]=-1;
        swap(heap[0],heap[heap.size()-1]);
    
        heap.pop_back();
        int curr=0;
        int min=get_min_trio(curr);
        while(curr!=min) {
            swap(heap[curr],heap[min]);
            vertex_to_heap_index[heap[curr].vertex]=curr;
            vertex_to_heap_index[heap[min].vertex]=min;
 
            curr=min;
            min=get_min_trio(curr);
        }
        return;
    }
    int find_weight(int vertex) {
        return heap[vertex_to_heap_index[vertex]].weight;
    }
    void update_weight(int vertex,int weight) {
        if(vertex_to_heap_index[vertex]==-1) return;
        int init_weight= heap[vertex_to_heap_index[vertex]].weight;
        heap[vertex_to_heap_index[vertex]].weight=weight;
        if(init_weight==weight) return;
        else if(init_weight > weight) {
            int j=vertex_to_heap_index[vertex];
            int parent_j = (j-1)/2;
            while(parent_j>=0 && heap[j].weight< heap[parent_j].weight) {
                swap(heap[j],heap[parent_j]);
                vertex_to_heap_index[heap[j].vertex]=j;
                vertex_to_heap_index[heap[parent_j].vertex]=parent_j;
                j=parent_j;
                parent_j=(j-1)/2;
            }
       }
       else {
            int curr=vertex_to_heap_index[vertex];
            int min=get_min_trio(curr);
            while(curr!=min) {
                swap(heap[curr],heap[min]);
                vertex_to_heap_index[heap[curr].vertex]=curr;
                vertex_to_heap_index[heap[min].vertex]=min;
                curr=min;
                min=get_min_trio(curr);
           }
       }
    }
};

/*
int main() {
    pq pq_inst(11);
    for(int i=10;i>=0;i--)
    //    insert(heap,i);
         pq_inst.insert(i,i);
    pq_inst.print();
    for(int i=7;i<=10;i++) {
         int a,b;
        pq_inst.find_min(a,b);
        cout<<"min "<<a<<" "<<b;
         pq_inst.delete_min();
    }
    pq_inst.update_weight(5,100);
    pq_inst.update_weight(9,-100);
    cout<<endl;
    pq_inst.print();
    cout<<endl;
}

*/
