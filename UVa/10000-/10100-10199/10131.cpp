// UVa 10131 - Is Bigger Smarter?
// Sort + Longest Decreasing Sequence (LDS)
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> iii;

vector<iii> ele;
int LIS_dp[1010];
int N;

bool compare(const iii &a, const iii &b){
    return a.first.first < b.first.first;
}

int LIS(int i){
    if(LIS_dp[i] != -1) return LIS_dp[i];
    LIS_dp[i] = 1;
    for(int j = i+1; j < N; j++){
        // if weight/IQ in increasing/decreasing order
        if(ele[i].first.first < ele[j].first.first && ele[i].first.second > ele[j].first.second){
            LIS_dp[i] = max(LIS_dp[i], LIS(j)+1);
        }
    }

    return LIS_dp[i];
}

int main(void){
    int w, iq, idx = 1;
    int maxLIS = 0;

    while(scanf("%d %d", &w, &iq) == 2){
        ele.push_back(make_pair(make_pair(w, iq), idx++));
    }
    
    N = ele.size();
    sort(ele.begin(), ele.end());
    memset(LIS_dp, -1, sizeof(LIS_dp));

    for(int i = 0; i < N; i++) maxLIS = max(maxLIS, LIS(i));
    printf("%d\n", maxLIS);

    for(int i = 0; i < N; i++){
        if(LIS_dp[i] == maxLIS){
            printf("%d\n", ele[i].second);
            maxLIS--;
            if(maxLIS == 0) break;
        }
    }

    return 0;
}
