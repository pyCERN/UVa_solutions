// UVa 11456 - Trainsorting
// LIS + LDS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int LIS_dp[2010], LDS_dp[2010], train[2010];
int nTrain;

int LIS(int i){
    if(LIS_dp[i] != -1) return LIS_dp[i];
    LIS_dp[i] = 1;
    
    for(int j = i+1; j < nTrain; j++){
        if(train[i] > train[j]) LIS_dp[i] = max(LIS_dp[i], LIS(j)+1);
    }

    return LIS_dp[i];
}

int LDS(int i){
    if(LDS_dp[i] != -1) return LDS_dp[i];
    LDS_dp[i] = 1;
    
    for(int j = i+1; j < nTrain; j++){
        if(train[i] < train[j]) LDS_dp[i] = max(LDS_dp[i], LDS(j)+1);
    }

    return LDS_dp[i];
}

int main(void){
    int TC, maxTrain;

    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &nTrain);
        memset(LIS_dp, -1, sizeof(LIS_dp)); memset(LDS_dp, -1, sizeof(LDS_dp));
        maxTrain = 0;

        for(int i = 0; i < nTrain; i++) scanf("%d", &train[i]);
        for(int i = 0; i < nTrain; i++) maxTrain = max(maxTrain, LIS(i)+LDS(i)-1);
        printf("%d\n", maxTrain);
    }

    return 0;
}
