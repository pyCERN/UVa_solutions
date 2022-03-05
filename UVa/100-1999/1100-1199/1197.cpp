// UVa 1197 - The Suspects
// DFS
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

enum {UNVISITED=0, VISITED};

vvi adjList;
vi visited;
int ans;

void dfs(int u){
    visited[u] = VISITED;
    
    for(int i = 0; i < (int)adjList[u].size(); i++){
        int v = adjList[u][i];

        if(visited[v] == UNVISITED){
            ans++;
            dfs(v);
        }
    }
}

int main(void){
    int n, m;
    
    while(scanf("%d %d", &n, &m), n | m){
        adjList.clear(); visited.clear();
        adjList.assign(n, vi()); visited.assign(n, UNVISITED);
        ans = 1;
        
        for(int i = 0; i < m; i++){
            int nMembers;
            scanf("%d", &nMembers);

            int currID, prevID;
            for(int j = 0; j < nMembers; j++){
                scanf("%d", &currID);
                if(j > 0){
                    adjList[currID].push_back(prevID);
                    adjList[prevID].push_back(currID);
                }
                prevID = currID;
            }
        }
        
        dfs(0);
        printf("%d\n", ans);
    }

    return 0;
}