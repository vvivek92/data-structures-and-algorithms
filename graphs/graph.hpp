#include<vector>
using namespace std;

class graph {
    public:
        virtual void print()=0;
        virtual int is_connected(int x, int y)=0;
        virtual void add_edge(int x,int y,int weight)=0;
        virtual void remove_edge(int x, int y)=0;
        virtual void get_neighbours(int x, vector<int> &v)=0;
        virtual ~graph() {};
};
