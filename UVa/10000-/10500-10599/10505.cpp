#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
int N;

bool isEnemy(int i, int j){
    if(find(adjList[i].begin(), adjList[i].end(), j) != adjList[i].begin())
        return true;
    else return false;
}

void bfs(void){
    queue<int> q; q.push(0);
    vi color(N, INF); color[0] = 0;
    bool isBipartite = true;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)adjList[u].size(); i++){
            int v = adjList[u][i];
            if(color[v] == INF){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                isBipartite = false;
                break;
            }
        }
    }
    for(int i = 0; i < N; i++) printf("%d ", color[i]);
    printf("\n");
}

int main(void){
    int nEnemy;

    scanf("%d", &N);
    adjList.assign(N, vi());

    for(int n = 0; n < N; n++){
        scanf("%d", &nEnemy);
        for(int i = 0; i < nEnemy; i++){
            int enemyIdx;
            scanf("%d", &enemyIdx); enemyIdx--;
            // Symmetric
            if(!isEnemy(n, enemyIdx))
                adjList[n].push_back(enemyIdx);
            if(!isEnemy(enemyIdx, n))
                adjList[enemyIdx].push_back(n);
        }
    }
    bfs();

    return 0;
}