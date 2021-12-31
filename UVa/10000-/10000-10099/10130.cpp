// UVa 10130 - SuperSale
// DP (knapsack problem)
#include <cstdio>
#include <cstring>
using namespace std;

int prices[1010][2], person[110], DP[110][1010][40];
int N, G;

int max(int a, int b){
    return a > b ? a : b;
}

void knapsack(void){
    for(int g = 1; g <= G; g++){
        for(int n = 1; n <= N; n++){
            for(int remMW = person[g]; remMW >= 0; remMW--){
                if(prices[n][1] > remMW) DP[g][n][remMW] = DP[g][n-1][remMW];
                else DP[g][n][remMW] = max(DP[g][n-1][remMW], prices[n][0] + DP[g][n-1][remMW-prices[n][1]]);
            }
        }
    }
}

int main(void){
    int TC, sum;

    scanf("%d", &TC);

	  while(TC--){
	      sum = 0;

	      scanf("%d", &N);
    	  for(int n = 1; n <= N; n++) scanf("%d %d", &prices[n][0], &prices[n][1]);

	      scanf("%d", &G);
    	  for(int g = 1; g <= G; g++) scanf("%d", &person[g]);

    	  knapsack();
    	  for(int g = 1; g <= G; g++) sum += DP[g][N][person[g]];
		    printf("%d\n", sum);
	  }

    return 0;
}
