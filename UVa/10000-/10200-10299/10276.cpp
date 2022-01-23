// UVa 10276 - Hanoi Tower Troubles Again!
// Backtracking
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int N, maxNum;
int pegs[51] = {0,};

void backtrack(int num){
    for(int i = 0; i < N; i++){
        int sq = sqrt(pegs[i] + num);

        if(pegs[i] == 0 || sq*sq == pegs[i]+num){
            pegs[i] = num;
            backtrack(num+1);
            return;
        }
    }
    maxNum = MAX(maxNum, num);
}

int main(void){
    int TC;

    scanf("%d", &TC);
    
    while(TC--){
        scanf("%d", &N);
        memset(pegs, 0, sizeof(pegs));

        backtrack(1);
        printf("%d\n", maxNum-1);
    }

    return 0;
}