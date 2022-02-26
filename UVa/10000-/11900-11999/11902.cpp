// UVa 11902 - Dominator
// DFS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

enum {UNVISITED = 0, VISITED};
int adjList[101][101], dom[101][101];
int visited[101];
int N;

// whether the path 0 -> Y contains X
void dfs(){

}

int main(void){
FILE *fp = fopen("ans.txt", "w");
	scanf("%d", &N);
	memset(adjList, 0, sizeof(adjList)); memset(dom, 0, sizeof(dom));

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) scanf("%d", &adjList[i][j]);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
		{
			memset(visited, UNVISITED, sizeof(visited));
			dfs(i, j);
			fprintf(fp, "%d ", dom[i][j]);
		}
		fprintf(fp, "\n");
	}
fclose(fp);
	return 0;
}