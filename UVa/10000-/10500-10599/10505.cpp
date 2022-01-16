// UVa 10505 - Montesco vs Capuleto
// Bipartite graph
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
int N;

bool isEnemy(int i, int j){
    if(find(adjList[i].begin(), adjList[i].end(), j) != adjList[i].end())
        return true;
    else return false;
}

void bfs(void){
    int ans = 0;
    queue<int> q;
    vi color(N, -1);
    
    for(int s = 0; s < N; s++){ // search for all nodes
        bool isBipartite = true;
        if(color[s] != -1) continue;

        // calculate max num per connected graphs
        int nums[2] = {0, 0};
        q.push(s); color[s] = 0; nums[0]++;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < (int)adjList[u].size(); i++){
                int v = adjList[u][i];
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    nums[color[v]]++;
                    q.push(v);
                }
                else if(color[v] == color[u])
                    isBipartite = false;
            }
        }
        if(isBipartite) ans += max(nums[0], nums[1]);
    }
    printf("%d\n", ans);
}

int main(void){
    int TC, nEnemies;

    scanf("%d", &TC);

    while(TC--){
        scanf("%d", &N);
        adjList.assign(N, vi());

        for(int n = 0; n < N; n++){
            scanf("%d", &nEnemies);
            for(int i = 0; i < nEnemies; i++){
                int enemyIdx;
                scanf("%d", &enemyIdx); enemyIdx--;
                // Symmetric
                if(enemyIdx < N){
                    if(!isEnemy(n, enemyIdx))
                        adjList[n].push_back(enemyIdx);
                    if(!isEnemy(enemyIdx, n))
                        adjList[enemyIdx].push_back(n);
                }
            }
        }
        bfs();
    }

    return 0;
}