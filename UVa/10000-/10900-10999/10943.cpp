#include <cstdio>
using namespace std;

// DP

int N, K;
/*
ways_dp[n][k]
num of ways of sum n using k nums
*/
int ways_dp[101][101];

int ways(int n, int k){
    if(n == 0) return 1;
    if(ways_dp[n][k] != -1) return ways_dp[n][k];
    long long way = 0;
    for(int x = 0; x <= n; x++){
        way = (way + ways(n-x, k-1)) % 1000000;
    }
    ways_dp[n][k] = way;

    return way;
}

int main(void){
    while(true){
        scanf("%d %d", &N, &K);
        if(N == 0 && K == 0) break;
        for(int n = 1; n <= N; n++){
            for(int k = 1; k <= K; k++){
                if(k == 1) ways_dp[n][k] = 1;
                if(n == 1) ways_dp[n][k] = k;
                else ways_dp[n][k] = -1;
            }
        }
        printf("%d\n", ways(N, K));
    }
    return 0;
}