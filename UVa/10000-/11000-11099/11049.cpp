// UVa 11049 - Basic wall maze
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define NUM 6
using namespace std;

// (5, 1) (6, 1) => (6, 1) -> (6, 2) x
// (5, 1) (5, 2) => (6, 2) -> (5, 2) x

// E, N, W, S
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
char dir[] = {'E', 'N', 'W', 'S'};

pair<int, int> s;
pair<int, int> e;
pair<int, int> w_s[3], w_e[3];
vector<char> path;

bool check_wall(int r, int c, int rr, int cc){
    for(int j = 0; j < 3; j++){
        printf("%d %d %d %d %d %d %d %d\n", r, c, rr, cc, w_s[j].first, w_s[j].second, w_e[j].first, w_e[j].second);
        if(w_s[j].first == w_e[j].first){ // horizontal
            if() return false;
        }
        else{ // horizontal
            if(r == rr) return false;
        }
    }
    return true;
}

void bfs(int row, int col){
    queue<pair<int, int>> q;
    bool visited[NUM+1][NUM+1];

    for(int i = 1; i <= NUM; i++){
        for(int j = 1; j <=NUM; j++) visited[i][j] = false;
    }
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
                path.push_back(dir[i]);
                if(rr == e.first && cc == e.second) return;
            }
        }
    }
}

int main(void){
    scanf("%d %d", &s.first, &s.second);
    scanf("%d %d", &e.first, &e.second);
    for(int i = 0; i < 3; i++)
        scanf("%d %d %d %d", &w_s[i].first, &w_s[i].second, &w_e[i].first, &w_e[i].second);
    path.clear();
    bfs(s.first, s.second);
    for(int i = 0; i < path.size(); i++) printf("%c", path[i]);
    printf("\n");

    return 0;
}