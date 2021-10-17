#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

// Check bipartite graph

typedef vector<int> vi;
vi graph[200];

bool bfs(int N){
    queue<int> q;
    int color[200];
    q.push(0);

    for(int i = 0; i < N; i++) color[i] = -1;
    color[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        // All nodes connected to u
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(color[v] == -1){
                color[v] = !color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }

    return true;
}

int main(void){
    int N, l;

    while(true){
        scanf("%d", &N);
        if(N == 0) break;
        scanf("%d", &l);

        for(int i = 0; i < N; i++) graph[i].clear();

        for(int i = 0; i < l; i++){
            int u1, u2;
            scanf("%d %d", &u1, &u2);
            graph[u1].push_back(u2);
            graph[u2].push_back(u1);
        }
        if(bfs(N)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

    return 0;
}