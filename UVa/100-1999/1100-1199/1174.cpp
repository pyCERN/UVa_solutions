// IP-TV
// Minimum Spanning Tree (MST)

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

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
    int TC, n_city, min_cost;
    int M, N, C;
    char v1[10], v2[10];
    int v1_ind, v2_ind;
    unordered_map<string, int> city_name;
    vii edge_list;
    

    scanf("%d", &TC);
    while(TC--){
        min_cost = 0; n_city = 0;
        city_name.clear();
        edge_list.clear();

        scanf("%d", &M);
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%s", v1);
            scanf("%s", v2);
            scanf("%d", &C);
            if(city_name.find(v1) == city_name.end()) city_name[v1] = n_city++;
            if(city_name.find(v2) == city_name.end()) city_name[v2] = n_city++;
            edge_list.push_back(make_pair(C, make_pair(city_name[v1], city_name[v2])));
        }
        sort(edge_list.begin(), edge_list.end(), compare);

        // Kruskal's algorithm
        UnionFind uf(M);
        for(int i = 0; i < edge_list.size(); i++){
            pair<int, ii> edge = edge_list[i];
            if(!uf.isSameSet(edge.second.first, edge.second.second)){
                min_cost += edge.first;
                uf.unionSet(edge.second.first, edge.second.second);
            }
        }
        printf("%d\n", min_cost);
        if(TC) printf("\n");
    }
    return 0;
}