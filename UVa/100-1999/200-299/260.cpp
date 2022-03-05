// UVa 260 - Il Gioco dell'X
// Flood fill
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;

// Degree 0, 60, 120, 180, 240, 300
int dr[] = {0, -1, -1, 0, 1, 1};
int dc[] = {1, 0, -1, -1, 0, 1};

vs board;
int N;
bool blackWin;

void floodfill(int r, int c){
    board[r][c] = '.';

    for(int i = 0; i < 6; i++){
        int rr = r + dr[i], cc = c + dc[i];

        if(rr < 0 || cc < 0 || rr >= N || cc >= N) continue;

        if(board[rr][cc] == 'b'){
            if(rr == N-1){
                blackWin = true;
                return;
            }
            floodfill(rr, cc);
        }
    }
}

int main(void){
    int TC = 1;

    while(scanf("%d", &N), N != 0){
        board.clear(); board.assign(N, string());
        blackWin = false;

        for(int r = 0; r < N; r++)
            cin >> board[r];
        
        for(int c = 0; c < N; c++){
            if(board[0][c] == 'b'){
                floodfill(0, c);
            }
            if(blackWin) break;
        }

        printf("%d ", TC++);
        if(blackWin) printf("B\n");
        else printf("W\n");
    }

    return 0;
}