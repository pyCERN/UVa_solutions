// UVa 111 - History Grading
// Longest Increasing Sequence (LIS)
#include <cstdio>
#include <cstring>
using namespace std;

int seq[25], order[25], LIS_dp[25];
int n, maxLen;

int max(int a, int b){
    return a > b ? a : b;
}

// Max length of sequence starting from i
int LIS(int i){
    int LIS_i = 1;

    if(LIS_dp[i] != -1) return LIS_dp[i];
    for(int j = 1; j <= i; j++){
        if(order[seq[j]] < order[seq[i]]) LIS_i = max(LIS_i, LIS(j)+1);
    }
    LIS_dp[i] = LIS_i;
    maxLen = max(maxLen, LIS_dp[i]);

    return LIS_dp[i];
}

int main(void){
    int order_tmp, seq_tmp, flag = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &order[i]);
    }
    while(true){
        for(int i = 1; i <= n; i++){
            if(scanf("%d", &seq_tmp) != 1){
                flag = 1;
                break;
            }
            else seq[seq_tmp] = i;
        }
        if(flag) break;

        memset(LIS_dp, -1, sizeof(LIS_dp)); LIS_dp[1] = 1;

        maxLen = 1;
        for(int i = 1; i <= n; i++) LIS(i);
        printf("%d\n", maxLen);
    }

    return 0;
}