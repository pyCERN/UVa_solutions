#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii AdjList; // [node, edge_weight]
bool *visited; // initially set to 0

// O(V+E)

void dfs(int node){ // all nodes connected to node
    if(!visited[node])
        visited[node] = true;

    for(int i = 0; i < AdjList[node].size(); i++){
        ii next_node = AdjList[node][i];
        printf("%d ", next_node.first);
        if(!visited[next_node.first])
            dfs(next_node.first);
    }
    printf("\n");
}