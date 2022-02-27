// UVa 11902 - Dominator
// DFS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

enum {UNVISITED=0, VISITED};
int adjList[101][101], dom[101][101];
int visited[101];
int N;

// Searches the path 0 -> dst
void dfs(int u, int dst){
	if(u == dst) return;
	visited[u] = VISITED;
	for(int i = 0; i < N; i++){
		if(adjList[u][i] == 1 && visited[i] == UNVISITED)
			dfs(i, dst);
	}
}

int main(void){
	int TC;
FILE *fp = fopen("ans.txt", "w");
	
	scanf("%d", &TC);
	
	for(int tc = 1; tc <= TC; tc++){
		fprintf(fp, "Case %d:\n", tc);
		scanf("%d", &N);
		memset(adjList, 0, sizeof(adjList)); memset(dom, 0, sizeof(dom));

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++) scanf("%d", &adjList[i][j]);
		}

		for(int i = 0; i < N; i++){		// whether the path 0 -> i contains j (0 <= j < N)
			memset(visited, UNVISITED, sizeof(visited));
			dfs(0, i);
			fprintf(fp, "+");
			for(int k = 0; k < 2*N-1; k++) fprintf(fp, "-");
			fprintf(fp, "+\n");
			fprintf(fp, "|");
			for(int j = 0; j < N; j++){
				if(adjList[i][j] == 1 && !visited[j]) fprintf(fp, "%c", 'Y');
				else fprintf(fp, "%c", 'N');
				fprintf(fp, "|");
			}
			fprintf(fp, "\n");
		}

		// for(int i = 0; i < N; i++){
		// 	fprintf(fp, "+");
		// 	for(int k = 0; k < 2*N-1; k++) fprintf(fp, "-");
		// 	fprintf(fp, "+\n");
		// 	fprintf(fp, "|");
		// 	for(int j = 0; j < N; j++){
		// 		// fprintf(fp, "%c", !dom[j][i] ? 'Y': 'N');
		// 		fprintf(fp, "%d", dom[i][j]);
		// 		fprintf(fp, "|");
		// 	}
		// 	fprintf(fp, "\n");
		// }
		fprintf(fp, "+");
		for(int k = 0; k < 2*N-1; k++) fprintf(fp, "-");
		fprintf(fp, "+\n");
	}

fclose(fp);
	return 0;
}