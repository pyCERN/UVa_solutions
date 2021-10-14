#include <cstdio>
#include <cstring>
using namespace std;

char grid[105][105];
char grid_copy[105][105];

// E, W, S, N, EN, WN, WS, ES
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

int n = 0, m = 0;

int floodfill(int x, int y, char c1, char c2){ // Color component with query x, y
    int ans = 1;

    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(grid_copy[x][y] != c1) return 0;
    grid_copy[x][y] = c2;
    for(int i = 0; i < 8; i++){
        ans += floodfill(x+dx[i], y+dy[i], c1, c2);
    }

    return ans;
}

int main(void){
    int TC;
    int x, y;
    char str[105];

    scanf("%d ", &TC);
    while(TC--){
        n = 0; m = 0;
        memset(grid, 0, sizeof(grid));
        memset(grid_copy, 0, sizeof(grid_copy));
        while(fgets(str, 105, stdin)){
            if(str[0] == '\n') break;
            if(str[0] == 'L' || str[0] == 'W'){
                m = strlen(str) - 1;
                sscanf(str, "%s", grid[n]);
                n++;
            }
            else{
                sscanf(str, "%d %d", &x, &y);
                for(int i = 0; i < n; i++) strcpy(grid_copy[i], grid[i]);
                printf("%d\n", floodfill(x-1, y-1, 'W', '.'));
            }
        }
        if(TC) printf("\n");
    }

    return 0;
}