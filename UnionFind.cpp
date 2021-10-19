#include <vector>
using namespace std;

typedef vector<int, int> vi;

class UnionFind{
private:
    vi parent, rank;
public:
    UnionFind(int N){
        parent.assign(N, 0); rank.assign(N, 0);
        for(int i = 0; i < N; i++) parent[i] = i;
    }
    int findSet(int u){
        if(parent[u] == u) return u;
        else{
            parent[u] = findSet(parent[u]);
            return parent[u];
        }
    }
    bool isSameSet(int u, int v){
        return (findSet(u) == findSet(v));
    }
    void unionSet(int u, int v){
        int x = findSet(u), y = findSet(v);
        if(x != y){
            if(rank[x] > rank[y]) parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};