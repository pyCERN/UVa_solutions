// UVa 990 - Diving for Gold
// DP (0-1 knapsack problem)
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

pair<int, int> treasures[35];
stack<pair<int, int>> ans;
int DP[35][1010] = {0,};
int time, w, n;

void knapsack(void){
    for(int i = 1; i <= n; i++){
        for(int t = 0; t <= time; t++){
            if(3*w*treasures[i].first > t) DP[i][t] = DP[i-1][t];
            else DP[i][t] = max(DP[i-1][t], treasures[i].second + DP[i-1][t-3*w*treasures[i].first]);
        }
    }
}

int main(void){
    int maxGold, amount, TC = 0;
    string s;

    while(scanf("%d %d", &time, &w) == 2){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d %d", &treasures[i].first, &treasures[i].second);
        amount = 0;
        getline(cin, s); getline(cin, s);

        knapsack();

        maxGold = DP[n][time];

        if(TC) printf("\n");
        printf("%d\n", maxGold);

        for(int i = 1; i <= n; i++) DP[i][0] = 0;

        for(int i = n, t = time; i > 0; i--){
            if(DP[i-1][t] == maxGold) continue;
            else{
                maxGold -= treasures[i].second;
                ans.push(treasures[i]);
                t -= 3*w*treasures[i].first;
                amount++;
            }
        }
        
        printf("%d\n", amount);

        while(!ans.empty()){
            printf("%d %d\n", ans.top().first, ans.top().second);
            ans.pop();
        }
        TC++;
    }

    return 0;
}