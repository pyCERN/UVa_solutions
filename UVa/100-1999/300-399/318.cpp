// UVa 318 Domino Effect
// Incomplete
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii; // (end_node, time)
typedef vector<vii> vvii;

enum {UNVISITED=0, VISITED};

// vi visited;
vvii edgeList;
int firstMax, secondMax;
int firstNode, secondNode; // farthest / second farthest node from 1
int n, m; // num of nodes, num of edges

// void dfs(int u, int nVisited, int time, vvii edgeList){
//     visited[u] = VISITED;

//     for(int i = 0; i < (int)edgeList[u].size(); i++){
//         int v = edgeList[u][i].first;
//         int t = edgeList[u][i].second;

//         if(visited[v] == UNVISITED)
//             dfs(v, nVisited+1, time+t, edgeList);
//     }

//     if(nVisited == n-1){
//         if(time > firstMax){
//             firstMax = time;
//             firstNode = u;
//         }
//         if(time > secondMax && secondMax < firstMax){
//             secondMax = time;
//             secondNode = u;
//         }
//     }
// }

void bfs(vvii edgeList){
    vi visited(n+1, UNVISITED); visited[1] = VISITED;
    vi time(n+1); time[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int i = 0; i < (int)edgeList[u].size(); i++){
            int v = edgeList[u][i].first;
            int t = edgeList[u][i].second;
            time[v] = time[u] + t;
            printf("%d %d\n", v, time[v]);

            if(visited[v] == UNVISITED){
                visited[v] = VISITED;
                q.push(v);
            }
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    edgeList.assign(n+1, vii());
    // visited.assign(n+1, UNVISITED);

    for(int i = 0; i < m; i++){ 
        int a, b, l; // start_node, end_node, time of a -> b
        scanf("%d %d %d", &a, &b, &l);
        edgeList[a].push_back(make_pair(b, l));
        if(a != 1) edgeList[b].push_back(make_pair(a, l));
    }

    bfs(edgeList);
    // dfs(1, 0, 0, edgeList);
    // printf("%d %d %d %d\n", firstMax, secondMax, firstNode, secondNode);

    return 0;
}