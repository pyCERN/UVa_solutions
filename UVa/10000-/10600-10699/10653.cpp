// 10653 - Bombs! NO they are Mines!!

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1010*1010
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii map;
vii mine_list;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void bfs(ii start, ii end, int R, int C){
    vii dist;
    queue<int> q;

    dist.clear();
    for(int y = 0; y < R; y++){
        for(int x = 0; x < C; x++) {
            dist.push_back(INF);
        }
    }
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int cur_node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_node = adj_list[cur_node][i];
            if(dist[next_node] == INF){
                q.push(next_node);
                dist[next_node] = dist[cur_node] + 1;
            }
        }
    }
    printf("%d\n", dist[end]);
}

int main(void){
    int R, C;
    int row, col, rows, num_mines;
    int start_x, start_y, end_x, end_y;

    while(scanf("%d %d", &R, &C), R | C){
        mine_list.clear();
        scanf("%d", &rows);
        for(int i = 0; i < rows; i++){
            scanf("%d", &row);
            scanf("%d", &num_mines);
            for(int j = 0; j < num_mines; j++){
                scanf("%d", &col);
                mine_list.push_back(make_pair(row, col));
            }
        }
        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &end_x, &end_y);

        bfs(make_pair(start_x, start_y), make_pair(end_x, end_y), R, C);
    }

    return 0;
}