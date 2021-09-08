#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// Calculate minimum candies for Alice
// by searching for all possible grids using backtracking

int N, min_candy;
int board[8][8];
int row[8];

bool check(int r, int c){
    for(int i = 0; i < r; i++){
        if(row[i] == c) return false;
    }
    return true;
}

void backtrack(int r, int s){
    if(r == N){
        min_candy = min(min_candy, s);
        return;
    }
    for(int c = 0; c < N; c++){
        if(check(r, c)){
            row[r] = c;
            backtrack(r+1, s+board[r][c]);
        }
    }
}

int main(void){
    int TC;

    scanf("%d", &TC);

    while(TC--){
        scanf("%d", &N);
        min_candy = 10000000;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &board[i][j]);
            }
        }
        if(N == 1){
            printf("%d\n", board[0][0]);
            continue;
        }

        backtrack(0, 0);
        printf("%d\n", min_candy);
    }
    return 0;
}
