// UVa 11049 - Basic wall maze
// Find shortest path
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define NUM 6
using namespace std;

// E, N, W, S
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
char dir[] = "ENWS";

pair<int, int> s;
pair<int, int> e;
pair<int, int> w_s[3], w_e[3];
vector<char> path;
int dir_grid[NUM+1][NUM+1]; // store directions

bool check_wall(int r, int c, int rr, int cc){
    for(int j = 0; j < 3; j++){
        if(w_s[j].first == w_e[j].first){ // horizontal wall
            if(c > w_s[j].second && c <= w_e[j].second){ // if same column with the wall
                if((w_s[j].first >= r && w_s[j].first < rr) || (w_s[j].first >= rr && w_s[j].first < r)) // and row passes through the wall
                    return false;
            }
        }
        else{ // vertical wall
            if(r > w_s[j].first && r <= w_e[j].first){
                if((w_s[j].second >= c && w_s[j].second < cc) || (w_s[j].second >= cc && w_s[j].second < c))
                    return false;
            }
        }
    }
    return true;
}

void backtrack(int row, int col, int d){
    if(s == make_pair(row, col)) return;
    int r = row + dr[d], c = col + dc[d];
    backtrack(r, c, (dir_grid[r][c]+2)%4);
    path.push_back(dir[(d+2)%4]);
}

void bfs(int row, int col){
    queue<pair<int, int>> q;
    bool visited[NUM+1][NUM+1];

    memset(visited, false, sizeof(visited));
    memset(dir_grid, -1, sizeof(dir_grid));

    q.push(make_pair(row, col));
    visited[row][col] = true;

    while(!q.empty()){
        pair<int, int> cur_node = q.front();
        int r = cur_node.first, c = cur_node.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int rr = r + dr[i], cc = c + dc[i];
            if(rr < 1 || rr >= NUM+1 || cc < 1 || cc >= NUM+1) continue;
            if(!check_wall(r, c, rr, cc)) continue;
            if(!visited[rr][cc]){
                q.push(make_pair(rr, cc));
                visited[rr][cc] = true;
                dir_grid[rr][cc] = i;
                if(e == make_pair(rr, cc)){
                    backtrack(rr, cc, (i+2)%4); // opposite direction
                    return;
                }
            }
        }
    }
}

int main(void){
    while(scanf("%d %d", &s.second, &s.first), s.first | s.second){; // r, c
        scanf("%d %d", &e.second, &e.first);
        for(int i = 0; i < 3; i++)
            scanf("%d %d %d %d", &w_s[i].second, &w_s[i].first, &w_e[i].second, &w_e[i].first);
        path.clear();
        bfs(s.first, s.second);
        for(int i = 0; i < path.size(); i++) printf("%c", path[i]);
        printf("\n");
    }

    return 0;
}