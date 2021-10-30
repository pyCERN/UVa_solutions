// UVa 11450 - Wedding shopping
// Dynamic Programming
#include <cstdio>
using namespace std;

int dp[210][25];   // dp[M <= 200][C <= 25]
int price[25][25]; // price[C <= 25][K <= 25]
int M, C, K;

int shop(int money, int g){
    if(g == C) return 0;
    
}

int main(void){
    int N;

    scanf("%d %d", &M, &C);
    for(int i = 0; i < C; i++){
        scanf("%d", &price[i][0]);
        for(int j = 1; j <= K; j++) scanf("%d", &price[i][j]);
    }

}