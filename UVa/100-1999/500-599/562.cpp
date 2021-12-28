// UVa 562 - Dividing coins
// DP (Knapsack problem)
#include <cstdio>
#include <cstring>
using namespace std;

int DP[105][100*500+1] = {0,}, V[105];
int m, sum, target;

int max(int a, int b){
    return a > b ? a : b;
}

void knapsack(void){
    for(int id = m-1; id >= 0; id--){
        for(int v = sum/2; v >= 0; v--){
            if(V[id] > v) DP[id][v] = DP[id+1][v];
            else DP[id][v] = max(DP[id+1][v], V[id] + DP[id+1][v-V[id]]); // max(ignore, take)
        }
    }
}

int main(void){
    int TC;
    
    scanf("%d", &TC);

    while(TC--){
        scanf("%d", &m);
        memset(DP, 0, sizeof(DP));
        sum = 0;

        for(int i = 0; i < m; i++){
            scanf("%d", &V[i]);
            sum += V[i];
        }
        knapsack();
        
        printf("%d\n", sum - 2*DP[0][sum/2]);
    }

    return 0;
}