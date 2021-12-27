// UVa 497 - Strategic Defense Initiative
// LIS O(n^2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

int LIS_dp[10000], height[10000];
int nMissile, maxHeight;

void LIS(void){
    for(int i = 0; i < nMissile; i++){
        for(int j = i+1; j < nMissile; j++){
            if(height[i] < height[j]) LIS_dp[j] = max(LIS_dp[j], LIS_dp[i]+1);
        }
        maxHeight = max(maxHeight, LIS_dp[i]);
    }
}

int main(void){
    int TC = 0;
    stack<int> ans;
    string s;

    scanf("%d", &TC);
    getline(cin, s); getline(cin, s);

    while(TC--){
        nMissile = maxHeight = 0;
        while(true){
            getline(cin, s);
            if(s == "\0") break;
            sscanf(s.c_str(), "%d", &height[nMissile]);
            LIS_dp[nMissile] = 1;
            nMissile++;
        }

        LIS();
        printf("Max hits: %d\n", maxHeight);
        for(int i = nMissile-1; i >= 0; i--){
            if(LIS_dp[i] == maxHeight){
                ans.push(height[i]);
                maxHeight--;
            }
        }
        while(!ans.empty()){
            printf("%d\n", ans.top());
            ans.pop();
        }
        if(TC) printf("\n");
    }

    return 0;
}