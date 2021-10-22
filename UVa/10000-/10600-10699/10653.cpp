// 10653 - Bombs! NO they are Mines!!
// Shortest Path

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1010*1010
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi mine_list[1010];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs(int start_r, int start_c, int end_r, int end_c, int R, int C){
    vi dist;
    queue<int> qr, qc;

    int start = start_r*C + start_c;
    int end = end_r*C + end_c;

    dist.clear();
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++) dist.push_back(INF);
    }
    dist[start] = 0;
    qr.push(start_r); qc.push(start_c);

    while(!qr.empty()){
        int cur_node_r = qr.front();
        int cur_node_c = qc.front();
        int cur_node = cur_node_r*C + cur_node_c;
        qr.pop(); qc.pop();

        for(int i = 0; i < 4; i++){
            int next_node_r = cur_node_r + dr[i], next_node_c = cur_node_c + dc[i];
            int next_node = next_node_r*C + next_node_c;
            if(next_node_r < 0 || next_node_r >= R || next_node_c < 0 || next_node_c >= C) continue;
            if(find(mine_list[next_node_r].begin(), mine_list[next_node_r].end(), next_node_c) != mine_list[next_node_r].end()) continue;

            if(dist[next_node] == INF){
                qr.push(next_node_r); qc.push(next_node_c);
                dist[next_node] = dist[cur_node] + 1;
                if(next_node == end){
                    printf("%d\n", dist[end]);
                    return;
                }
            }
        }
    }
}

int main(void){
    int R, C;
    int row, col, rows, num_mines;
    int start_c, start_r, end_c, end_r;

    while(scanf("%d %d", &R, &C), R | C){
        for(int r = 0; r < R; r++) mine_list[r].clear();

        scanf("%d", &rows);
        for(int i = 0; i < rows; i++){
            scanf("%d", &row);
            scanf("%d", &num_mines);
            for(int j = 0; j < num_mines; j++){
                scanf("%d", &col);
                mine_list[row].push_back(col);
            }
        }
        scanf("%d %d", &start_r, &start_c);
        scanf("%d %d", &end_r, &end_c);

        bfs(start_r, start_c, end_r, end_c, R, C);
    }

    return 0;
}