#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <bitset>
#define ABS(x) ((x) > 0 ? (x) : -(x))
using namespace std;

int N, nSol;
string board[20];
int bad[20][20], row[20]; // row[i] : col of queen at i-th row
bitset<20> place;

bool check(int r, int c){
    if(bad[r][c] == 1) return false;
    for(int prevRow = 0; prevRow < r; prevRow++){
        if(c == row[prevRow] || r-prevRow == ABS(c-row[prevRow])) return false;
    }
    return true;
}

void backtrack(int r){
    if(r == N){
        nSol++;
        return;
    }

    for(int c = 0; c < N; c++){
        if(check(r, c)){

            row[r] = c;
            backtrack(r+1);
        }
    }
}

int main(void){
    int TC = 1;

    while(scanf("%d", &N), N != 0){
        nSol = 0;
        place.set();
        memset(bad, 0, sizeof(bad)); memset(row, 0, sizeof(row));
        
        for(int r = 0; r < N; r++){
            cin >> board[r];
            for(int c = 0; c < N; c++){
                if(board[r][c] == '*') bad[r][c] = 1;
            }
        }

        backtrack(0);
        printf("Case %d: %d\n", TC++, nSol);
    }

    return 0;
}