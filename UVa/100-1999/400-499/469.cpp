#include <stdio.h>
#include <string.h>

char grid[105][105];
char grid_copy[105][105];
int X = 0, Y = 0;
int dx[] = {0, 1, 1 ,1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int floodfill(int x, int y, char c1, char c2){
  if(x < 0 || x >= X || y < 0 || y >= Y) return 0;
  if(grid_copy[x][y] != c1) return 0;
  int ans = 1;
  grid_copy[x][y] = c2;
  for(int d = 0; d < 8; d++) ans += floodfill(x+dx[d], y+dy[d], c1, c2);
  return ans;
}

int main(void){
	int TC;
  int x, y;
  char str[105];

  scanf("%d ", &TC);
  while(TC--){
    X = 0;
    memset(grid, 0, sizeof(grid));
    memset(grid_copy, 0, sizeof(grid_copy));
    while(fgets(str, 105, stdin)){
      if(str[0] == '\n') break;
      if(str[0] == 'L' || str[0] == 'W'){
        Y = strlen(str) - 1;
        sscanf(str, "%s", grid[X]);
        X++;
      }
      else{
        sscanf(str, "%d %d", &x, &y);
        for(int i = 0; i < X; i++) strcpy(grid_copy[i], grid[i]);
        printf("%d\n", floodfill(x-1, y-1, 'W', '.'));
      }
    }
    if(TC) printf("\n");
  }
  return 0;
}
