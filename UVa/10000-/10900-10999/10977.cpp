// UVa 10977 - Enchanted Forest
// Calculate shortest path
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int R, C, m, n;
int blocked[210][210] = {0,};
// E, N, W, S
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

void bfs(int row, int col){
    queue<pair<int, int>> q;
    int dist[210][210];

    memset(dist, -1, sizeof(dist));
    q.push(make_pair(row, col));
    dist[row][col] = 0;

    while(!q.empty()){
        pair<int, int> cur_node = q.front();
        int r = cur_node.first, c = cur_node.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int rr = r + dr[i], cc = c + dc[i];
            if(rr < 1 || rr >= R+1 || cc < 1 || cc >= C+1) continue;
            if(blocked[rr][cc]) continue;
            if(dist[rr][cc] == -1){
                q.push(make_pair(rr, cc));
                dist[rr][cc] = dist[r][c] + 1;
            }
        }
    }
    if(dist[R][C] == -1) printf("Impossible.\n");
    else printf("%d\n", dist[R][C]);
}

int main(void){
    int r, c, L;

    while(scanf("%d %d", &R, &C), R | C){
        scanf("%d", &m);
        memset(blocked, 0, sizeof(blocked));
        for(int i = 0; i < m; i++){
            scanf("%d %d", &r, &c);
            blocked[r][c] = 1;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &r, &c, &L); // center : (r, c)
            int c_min = c-L, c_max = c+L;
            for(int j = max(1, c_min); j <= min(C, c_max); j++){
                int r_min = r - (int)sqrt(L*L - (c-j)*(c-j));
                int r_max = 2*r - r_min;
                for(int k = max(1, r_min); k <= min(R, r_max); k++) blocked[k][j] = 1;
            }
        }

        bfs(1, 1);
    }

    return 0;
}