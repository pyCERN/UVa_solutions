// UVa 11902 - Dominator
// DFS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

enum {UNVISITED=0, VISITED};
int adjList[101][101], initialVisited[101], visited[101];
int N;

void dfs(int u, int dst){
	if(u == dst) return;
	visited[u] = VISITED;
	for(int i = 0; i < N; i++){
		if(adjList[u][i] && !visited[i])
			dfs(i, dst);
	}
}

int main(void){
	int TC;
	
	scanf("%d", &TC);
	
	for(int tc = 1; tc <= TC; tc++){
		printf("Case %d:\n", tc);
		scanf("%d", &N);
		memset(adjList, 0, sizeof(adjList));
		memset(initialVisited, UNVISITED, sizeof(initialVisited)); memset(visited, UNVISITED, sizeof(visited));

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++) scanf("%d", &adjList[i][j]);
		}

		dfs(0, -1);	// all nodes initially reachable from 0
		for(int i = 0; i < N; i++) initialVisited[i] = visited[i]; // stores initial reachability of all nodes

		for(int i = 0; i < N; i++){		// whether the path 0 -> i contains j (0 <= j < N)
			memset(visited, UNVISITED, sizeof(visited));

			printf("+");
			for(int k = 0; k < 2*N-1; k++) printf("-");
			printf("+\n");
			printf("|");

			dfs(0, i); // all nodes still reachable with outgoing edges of i removed

			for(int j = 0; j < N; j++){
				if(initialVisited[j] && !visited[j]) printf("%c", 'Y');
				else printf("%c", 'N');

				printf("|");
			}
			printf("\n");
		}

		printf("+");
		for(int k = 0; k < 2*N-1; k++) printf("-");
		printf("+\n");
	}

	return 0;
}