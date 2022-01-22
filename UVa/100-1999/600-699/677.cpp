// UVa 677 - All Walks of length "n" from the first node
// Backtracking
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

int N, nWalks;
int mat[11][11];
vector<int> ans;
bitset<10> visited;
bool flag;

void backtrack(int walk, int node){ // A^(walk)
    if(walk == nWalks){
        printf("(");
        for(int i = 0; i < ans.size()-1; i++) printf("%d,", ans[i]+1);
        printf("%d)\n", ans[ans.size()-1]+1);
        flag = true;
        
        return;
    }

    for(int next_node = 0; next_node < N; next_node++){
        if(visited[next_node] == 0 && mat[node][next_node] == 1){
            visited[next_node] = 1; ans.push_back(next_node);
            backtrack(walk+1, next_node);
            visited[next_node] = 0; ans.pop_back();
        }
    }
}

int main(void){
    int TC = 0;
    int trash;

    while(scanf("%d %d", &N, &nWalks) == 2){
        if(TC > 0) printf("\n");
        flag = false;
        ans.clear(); visited.reset();

        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++) scanf("%d", &mat[r][c]);
        }

        visited[0] = 1; ans.push_back(0);
        backtrack(0, 0);
        if(!flag) printf("no walk of length %d\n", nWalks);

        scanf("%d", &trash);
        TC++;
    }

    return 0;
}