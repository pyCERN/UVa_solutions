#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// String input!

enum {UNVISITED = false, VISITED = true};

void dfs(vector<int> adjList[], bool visited[], int node){
    if(!visited[node]) visited[node] = VISITED;

    for(int i = 0; i < (int)adjList[node].size(); i++){
        if(!visited[adjList[node][i]]){
            dfs(adjList, visited, adjList[node][i]);
        }
    }
}

int main(void){
    int TC;

    scanf("%d", &TC);
    while(TC--){
        int max_node;
        string edge, s;
        int num_sub = 0;

        cin >> s;
        max_node = s[0] - 65;

        vector<int> adjList[30];
        bool visited[30];

        getline(cin, s);
        while(getline(cin, edge)){
            if(edge.length() == 0) break;
            int u = edge[0] - 65;
            int v = edge[1] - 65;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int i = 0; i <= (int)max_node; i++) visited[i] = UNVISITED;

        for(int i = 0; i <= (int)max_node; i++){
            if(!visited[i]){
                dfs(adjList, visited, i);
                num_sub++;
            }
        }
        printf("%d\n", num_sub);

        if(TC != 0) printf("\n");
    }

    return 0;
}