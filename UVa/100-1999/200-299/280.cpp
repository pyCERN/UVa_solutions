// UVa 280 Vertex
// DFS
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

enum {UNVISITED=0, VISITED};
int cnt;
vi visited;

void dfs(int u, vvi adjList){
    for(int j = 0; j < (int)adjList[u].size(); j++){
        int v = adjList[u][j];
        if(visited[v] == UNVISITED){
            visited[v] = VISITED;
            cnt++;
            dfs(v, adjList);
        }
    }
}

int main(void){
    int N, u, v;
    int nQueires;

    while(scanf("%d", &N), N != 0){
        vvi adjList(N+1, vi());

        while(scanf("%d", &u), u != 0){
            while(scanf("%d", &v), v != 0)
                adjList[u].push_back(v);
        }

        scanf("%d", &nQueires);
        
        for(int i = 0; i < nQueires; i++){
            cnt = 0;

            visited.assign(N+1, UNVISITED);

            scanf("%d", &u);
            dfs(u, adjList);

            printf("%d", N-cnt);
            for(int j = 1; j <= N; j++){
                if(visited[j] == UNVISITED) printf(" %d", j);
            }
            printf("\n");
        }
    }

    return 0;
}