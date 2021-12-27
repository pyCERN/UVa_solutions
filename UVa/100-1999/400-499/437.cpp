// UVa 437 - The Tower of Babylon
// LIS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> iii;

vector<iii> dims;
int LIS_dp[200];
int nTypes, maxHeight;

void LIS(void){
    for(int i = 0; i < 6*nTypes; i++){
        for(int j = i+1; j < 6*nTypes; j++){
            if(dims[i].first.first < dims[j].first.first && dims[i].first.second < dims[j].first.second)
                LIS_dp[j] = max(LIS_dp[j], LIS_dp[i]+dims[j].second);
        }
        maxHeight = max(maxHeight, LIS_dp[i]);
    }
}

int main(void){
    int d1, d2, d3;
    int TC = 1;

    while(true){
        scanf("%d", &nTypes);
        if(nTypes == 0) break;
        maxHeight = 0;
        dims.clear();

        for(int i = 0; i < nTypes; i++){
            scanf("%d %d %d", &d1, &d2, &d3);
            dims.push_back(make_pair(make_pair(d1, d2), d3)); dims.push_back(make_pair(make_pair(d2, d3), d1)); dims.push_back(make_pair(make_pair(d3, d1), d2));
            dims.push_back(make_pair(make_pair(d2, d1), d3)); dims.push_back(make_pair(make_pair(d3, d2), d1)); dims.push_back(make_pair(make_pair(d1, d3), d2));
        }
        // sort by first base dim
        sort(dims.begin(), dims.end());

        // LIS by second base dim
        for(int i = 0; i < 6*nTypes; i++) LIS_dp[i] = dims[i].second;
        LIS();

        printf("Case %d: maximum height = %d\n", TC, maxHeight);
        TC++;
    }

    return 0;

}