// UVa 10131 - Is Bigger Smarter?
// Sort + Longest Decreasing Sequence (LDS)
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> iii;

vector<iii> elephants;
int LIS_dp[1010];
int N, nLIS;

bool compare(const iii &a, const iii &b){
    return a.first.first < b.first.first;
}

void LIS(void){
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            // if weight/IQ in increasing/decreasing order
            if(elephants[i].first.first < elephants[j].first.first && elephants[i].first.second > elephants[j].first.second) LIS_dp[j] = max(LIS_dp[j], LIS_dp[i]+1);
        }
        nLIS = max(nLIS, LIS_dp[i]);
    }
}

int main(void){
    int w, iq, idx = 1;
    stack<int> ans;

    while(scanf("%d %d", &w, &iq) == 2){
        elephants.push_back(make_pair(make_pair(w, iq), idx++));
    }
    
    N = elephants.size(); nLIS = 0;
    sort(elephants.begin(), elephants.end());

    for(int i = 0; i < N; i++) LIS_dp[i] = 1;

    LIS();
    printf("%d\n", nLIS);

    for(int i = N-1; i >= 0; i--){
        if(LIS_dp[i] == nLIS){
            ans.push(elephants[i].second);
            nLIS--;
            if(nLIS == 0) break;
        }
    }
    
    while(!ans.empty()){
        printf("%d\n", ans.top());
        ans.pop();
    }

    return 0;
}
