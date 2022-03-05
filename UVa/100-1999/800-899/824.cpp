// UVa 824 Coast Tracker
// Simple graph traversal
#include <cstdio>
#include <cstring>

// N, NW, W, WS, S, SE, E, EN
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(void){
    int mat[3][3];
    int midX, midY, d;
    int x, y, s;

    while(scanf("%d", &midX), midX != -1){
        scanf("%d %d", &midY, &d);
        memset(mat, 0, sizeof(mat));

        for(int i = 0; i < 8; i++){
            scanf("%d %d %d", &x, &y, &s);
            mat[y-midY+1][x-midX+1] = s;
        }

        d = (d + 6) % 8; // rotate cur direction to right 90 degree

        while(true){
            int nextX = midX + dx[d], nextY = midY + dy[d];
            if(mat[nextY-midY+1][nextX-midX+1] == 1)
                break;
            d = (d + 1) % 8; // rotate ccw
        }

        printf("%d\n", d);
    }

    return 0;
}