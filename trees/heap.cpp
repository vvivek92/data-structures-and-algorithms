#include<vector>
#include<utility>
#include<iostream>
using namespace std;
// min heap

void print(const vector<int>& heap) {
    vector<int>::const_iterator i;
    cout<<endl;
    for(i=heap.begin();i!=heap.end();i++)
        cout<<" "<<*i;
    cout<<endl;
}
void insert(vector<int> & heap, int data) {
    heap.push_back(data);
    int j=heap.size()-1;
    int parent_j = (j-1)/2;
    while(parent_j>=0 && heap[j]< heap[parent_j]) {
        swap(heap[j],heap[parent_j]);
        j=parent_j;
        parent_j=(j-1)/2;
    }
}

int find_min(vector<int> & heap) {
    if(heap.size())return heap[1];
    return -100;
}

int get_min_trio(vector<int> & heap,int curr) {
    int left_child= (curr+1)*2 -1;
    int right_child=left_child+1;
    int min=curr;
    if(left_child < heap.size())
        if(heap[left_child] < heap[min])
            min=left_child;
    if(right_child < heap.size())
        if(heap[right_child] < heap[min])
            min=right_child;
    return min;
}
int delete_min(vector<int> & heap) {
    if(heap.size()==0) {
        return -100;
    }
    if(heap.size()==1) {
        int temp=heap[0];heap.pop_back();return temp;
    }
    int temp=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    int curr=0;
    int min=get_min_trio(heap,curr);
    while(curr!=min) {
        swap(heap[curr],heap[min]);
        curr=min;
        min=get_min_trio(heap,curr);
    }
    return temp;
}

void heapify(vector<int > & heap,vector<int> & given) {
    vector<int>::iterator i;
    //int last_index=heap.size()-1;
    for(i=given.begin();i != given.end(); i++) {
        heap.push_back(*i);
    }
    int index= ((heap.size()/2)-1);
    
    for(int j= index; j>=0;j--) {

        int curr=j;
        int min=get_min_trio(heap,curr);
        while(curr!=min) {
            swap(heap[curr],heap[min]);
            curr=min;
            min=get_min_trio(heap,curr);
        }
    }
} 

int main() {
    vector<int> heap;
    vector<int> given;
    for(int i=10;i>=0;i--)
    //    insert(heap,i);
         given.push_back(i);
    heapify(heap,given);
    print(heap);

    for(int i=7;i<=10;i++)
        delete_min(heap);


    print(heap);
    cout<<endl;
    cout<<heap[0];


}
