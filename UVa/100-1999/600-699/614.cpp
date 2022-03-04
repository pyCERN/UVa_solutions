// UVa 614 - Mapping the Route
// DFS
#include <cstdio>
#include <cstring>
using namespace std;

enum {UNVISITED=0, VISITED};
enum {W=0, N, E, S};

// W, N, E, S
int dc[] = {-1, 0, 1, 0};
int dr[] = {0, -1, 0, 1};

int grid[13][13], wall[13][13], visited[13][13], ans[13][13];
int rows, cols;
int startRow, startCol, goalRow, goalCol;
bool flag = false;

void dfs(int r, int c, int dist){
    visited[r][c] = VISITED;
    ans[r][c] = dist;

    if(r == goalRow && c == goalCol){
        flag = true;
        return;
    }

    for(int i = 0; i < 4; i++){
        // cur direction eastern && cur wall on its eastern
        if(i == E){
            if(wall[r][c] == 1 || wall[r][c] == 3) continue;
        }

        // cur direction southern && cur wall on its southern
        if(i == S){
            if(wall[r][c] == 2 || wall[r][c] == 3) continue;
        }

        int rr = r + dr[i], cc = c + dc[i];

        if(rr < 1 || cc < 1 || rr > rows || cc > cols) continue;

        // cur direction northern && next wall on its southern
        if(i == N){
            if(wall[rr][cc] == 2 || wall[rr][cc] == 3) continue;
        }

        // cur direction western && next wall on its eastern
        if(i == W){
            if(wall[rr][cc] == 1 || wall[rr][cc] == 3) continue;
        }

        if(visited[rr][cc] == UNVISITED)
            dfs(rr, cc, dist+1);
            if(flag) return;
    }

    // if couldn't reach the goal and blocked
    ans[r][c] = 0;
}

void print(void){
    for(int c = 0; c < cols; c++){
        printf("+---");
    }
    printf("+\n");
    
    for(int r = 1; r <= rows; r++){
        printf("|");
        for(int c = 1; c <= cols; c++){
            // print cell
            if(visited[r][c] == VISITED){
                if(ans[r][c] != 0) printf("%3d", ans[r][c]); // (r, c) cell is in the path
                else printf("???");
            }
            else printf("   ");
            
            // print eastern wall
            if(c < cols){
                if(wall[r][c] == 1 || wall[r][c] == 3) printf("|");
                else printf(" ");
            }
        }
        printf("|\n");

        for(int c = 1; c <= cols; c++){
            // print southern part of the cell
            if(r < rows){
                if(wall[r][c] == 2 || wall[r][c] == 3) printf("+---");
                else printf("+   ");
            }
            else
                printf("+---");
        }
        printf("+\n");
    }
}

int main(void){
    int TC = 1;

    while(scanf("%d %d %d %d %d %d", &rows, &cols, &startRow, &startCol, &goalRow, &goalCol), rows != 0){
        printf("Maze %d\n\n", TC++);

        for(int r = 1; r <= rows; r++){
            for(int c = 1; c <= cols; c++)
                scanf("%d", &wall[r][c]);
        }

        memset(visited, UNVISITED, sizeof(visited));
        memset(ans, 0, sizeof(ans));
        flag = false;

        dfs(startRow, startCol, 1);
        print();
        printf("\n\n");
    }

    return 0;
}