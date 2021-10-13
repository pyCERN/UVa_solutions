#include <cstdio>
#include <vector>
using namespace std;

/*
AB, CE, DB, EC
A : B     adjList[0]
B : A, D  adjList[1]
C : E
D : B
E : C
*/
enum {UNVISITED = false, VISITED = true};

void dfs(vector<int> adjList[], bool visited[], int node){
    if(!visited[node]) visited[node] = VISITED;

    for(int i = 0; i < (int)adjList[node].size(); i++){
        if(!visited[adjList[node][i]]){
            printf("%d\n", adjList[node][i]);
            dfs(adjList, visited, adjList[node][i]);
        }
    }
}

int main(void){
    int TC;

    scanf("%d", &TC);
    while(TC--){
        char max_node;
        char edge[2];
        int num_sub = 0;

        scanf(" %c", &max_node);

        vector<int> adjList[(int)max_node];
        bool visited[(int)max_node];

        while(scanf("%s", edge) != EOF){
            int u = edge[0] - 65;
            int v = edge[1] - 65;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
            printf("%d %d\n", u, v);
        }
        for(int i = 0; i < (int)max_node; i++) visited[i] = UNVISITED;

        for(int i = 0; i < (int)max_node; i++){
            if(!visited[i]){
                dfs(adjList, visited, i);
                num_sub++;
            }
        }
        printf("%d\n", num_sub);
    }

    return 0;
}