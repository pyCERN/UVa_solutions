// UVa 11450 - Wedding shopping
// Dynamic Programming
#include <cstdio>
#include <cstring>
#define MIN -10000000
using namespace std;

int dp[210][25];   // dp[M <= 200][C <= 25]
int price[25][25]; // price[C <= 25][K <= 25]
int M, C;

int max(int a, int b){
    return a > b ? a : b;
}

// max cost in state of g-th garment and remaining money
int shop(int money, int g){
    if(money < 0) return MIN;
    if(g == C) return 0;
    if(dp[money][g] != -1) return dp[money][g];
    for(int model = 1; model <= price[g][0]; model++){
        int next_shop = shop(money-price[g][model], g+1);
        if(next_shop != -1)
            dp[money][g] = max(dp[money][g], next_shop+price[g][model]);
    }
    return dp[money][g];
}

int main(void){
    int N;

    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &M, &C);
        memset(price, 0, sizeof(price));
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < C; i++){
            scanf("%d", &price[i][0]);
            for(int j = 1; j <= price[i][0]; j++) scanf("%d", &price[i][j]);
        }
        shop(M, 0);
        if(dp[M][0] == -1) printf("no solution\n");
        else printf("%d\n", dp[M][0]);
    }

    return 0;
}