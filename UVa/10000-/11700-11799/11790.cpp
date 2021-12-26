// UVa 11790 - Murcia's Skyline
// LIS + LDS
#include <cstdio>
#include <cstring>
using namespace std;

int LIS_dp[10000], LDS_dp[10000], height[10000], width[10000], nBuilding;
int maxSumInc, maxSumDec;

int max(int a, int b){
    return a > b ? a : b;
}

void LIS(void){
    for(int i = 0; i < nBuilding; i++){
        for(int j = i+1; j < nBuilding; j++){
            if(height[i] < height[j]) LIS_dp[j] = max(LIS_dp[j], LIS_dp[i]+width[j]);
        }
        maxSumInc = max(maxSumInc, LIS_dp[i]);
    }
}

void LDS(void){
    for(int i = 0; i < nBuilding; i++){
        for(int j = i+1; j < nBuilding; j++){
            if(height[i] > height[j]) LDS_dp[j] = max(LDS_dp[j], LDS_dp[i]+width[j]);
        }
        maxSumDec = max(maxSumDec, LDS_dp[i]);
    }
}

int main(void){
    int tc = 0, TC;

    scanf("%d", &TC);

    while(tc++ < TC){
        scanf("%d", &nBuilding);
        
        for(int i = 0; i < nBuilding; i++) scanf("%d", &height[i]);
        for(int i = 0; i < nBuilding; i++){
            scanf("%d", &width[i]);
            LIS_dp[i] = LDS_dp[i] = width[i];
        }
        maxSumInc = maxSumDec = 0;

        LIS(); LDS();

        if(maxSumInc >= maxSumDec) printf("Case %d. Increasing (%d). Decreasing (%d).\n", tc, maxSumInc, maxSumDec);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", tc, maxSumDec, maxSumInc);
    }

    return 0;
}