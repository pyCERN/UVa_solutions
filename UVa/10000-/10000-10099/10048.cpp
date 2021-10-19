// Audiophobia

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, ii>> vii;

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

int main(void){
    int TC = 1;
    int C, S, Q, c1, c2, d;
    vii edge_list;

    while(scanf("%d %d %d", &C, &S, &Q), C | S | Q){
        edge_list.clear();

        for(int i = 0; i < S; i++){
            scanf("%d %d %d", &c1, &c2, &d);
            edge_list.push_back(make_pair(d, make_pair(c1, c2)));
        }
        
    }
}