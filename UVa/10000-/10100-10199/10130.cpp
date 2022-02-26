// UVa 10130 - SuperSale
// DP (Knapsack problem)
#include <cstdio>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int PW[1001][2];        // price & weight
int DP[1001][101][31];  // [N (<= 1000)][G (<= 100)][MW (<= 30)]
int MW[101];            // max weight (<= 30)

void knapsack(int N, int G){
    for(int n = 1; n <= N; n++){
        for(int g = 1; g <= G; g++){
            for(int remW = MW[g]; remW >= 0; remW--){
                if(PW[n][1] > remW) DP[n][g][remW] = DP[n-1][g][remW];
                else DP[n][g][remW] = MAX(DP[n-1][g][remW], PW[n][0] + DP[n-1][g][remW-PW[n][1]]);
            }
        }
    }
}

int main(void){
    int TC;

    scanf("%d", &TC);
    while(TC--){
        int N, G, sum = 0;

        scanf("%d", &N);
        for(int i = 1; i <= N; i++) scanf("%d %d", &PW[i][0], &PW[i][1]);

        scanf("%d", &G);
        for(int i = 1; i <= G; i++) scanf("%d", &MW[i]);

        knapsack(N, G);
        for(int g = 1; g <= G; g++) sum += DP[N][g][MW[g]];
        printf("%d\n", sum);
    }

    return 0;
}