#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// Minimum Spanning Tree (MST)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, ii>> vii;

bool compare(const pair<int, ii> &a, const pair<int, ii> &b){
    return a.first < b.first;
}

class UnionFind{
private:
    vi parent, rank;
public:
    UnionFind(int N){
        parent.assign(N+1, 0); rank.assign(N+1, 0);
        for(int i = 1; i <= N; i++) parent[i] = i;
    }
    bool isSameSet(int u, int v){
        return (findSet(u) == findSet(v));
    }
    int findSet(int u){
        if(parent[u] == u) return u;
        else{
            parent[u] = findSet(parent[u]);
            return parent[u];
        }
    }
    void unionSet(int u, int v){
        if(!isSameSet(u, v)){
            int x = findSet(u), y = findSet(v);
            if(rank[x] > rank[y]) parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(void){
    int N, M, K;
    int TC = 0;
    vii edge_list;

    while(scanf("%d", &N) == 1){
        int v1, v2, cost, orig_min_cost = 0;
        int new_min_cost = 0;

        for(int i = 0; i < N-1; i++){
            scanf("%d %d %d", &v1, &v2, &cost);
            orig_min_cost += cost;
        }
        edge_list.clear();

        if(TC++) puts("");
        scanf("%d", &K);
        for(int i = 0; i < K; i++){
            scanf("%d %d %d", &v1, &v2, &cost);
            edge_list.push_back(make_pair(cost, make_pair(v1, v2)));
        }

        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &v1, &v2, &cost);
            edge_list.push_back(make_pair(cost, make_pair(v1, v2)));
        }
        sort(edge_list.begin(), edge_list.end(), compare);

        UnionFind uf(M+K);

        // Kruskal's algorithm
        for(int i = 0; i < edge_list.size(); i++){
            pair<int, ii> edge = edge_list[i];
            
            if(!uf.isSameSet(edge.second.first, edge.second.second)){
                new_min_cost += edge.first;
                uf.unionSet(edge.second.first, edge.second.second);
            }
        }
        printf("%d\n%d\n", orig_min_cost, new_min_cost);
    }

    return 0;
}