#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// DFS

typedef pair<int, int> ii;
typedef vector<int> vi;

enum { UNVISITED = -1, VISITED = 1 };

vector<vi> AdjList;
vi dfs_num;
int domer, domee;
bool first;

void print(int N){
	printf("+");
	for(int i = 0; i < 2*N-1; i++) printf("-");
	printf("+\n");
}

void initialize(int N){
	for(int i = 0; i < N; i++){
		vi v;
		for(int j = 0; j < N; j++){
			int x;
			scanf("%d", &x);
			if(x) v.push_back(j);
		}
		AdjList.push_back(v);
	}
}

void dfs(int u){
	if(!first && u == domer) return;
	dfs_num[u] = VISITED;
	for(int i = 0; i < AdjList[u].size(); i++){
		int x = AdjList[u][i]; if(dfs_num[x] == UNVISITED) dfs(x);
	}
}

bool canReach(int target){
	first = true;
	dfs(0);
	if(dfs_num[target] == UNVISITED) return false;
	return true;
}	

int main(void){
	int TC, N, c = 1;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &N);
		AdjList.clear();
		initialize(N);

		printf("Case %d:\n", c++);
		for(int i = 0; i < N; i++){
			domer = i;
			print(N); printf("|");
			for(int j = 0; j < N; j++){
				dfs_num.assign(N, UNVISITED);
				if(!canReach(j)) { printf("N|"); continue; }
				first = false;
				dfs_num.assign(N, UNVISITED);
				domee = j;
				dfs(0); 
				if(dfs_num[j] == VISITED) printf("N|");
				else printf("Y|");
			}
			printf("\n");
		}
		print(N);
	}
	return 0;
}
