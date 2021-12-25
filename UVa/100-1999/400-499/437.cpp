// UVa - The Tower of Babylon
/*
height + 2개 dim
10 20 30
(20 30) (10 20)
연속으로 같은 height x

모든 pair
6 8 10
5 5 5
(8 10) (6 8) (5 5)
10 8
8 6
6 10
5 5
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> iii;

vector<iii> dims;
int LIS_dp[200];

bool compare(const iii &a, const iii &b){
    // return a.first.first * a.first.second < b.first.first * b.first.second;
    return a.first.first < b.first.first;
}

int LIS(int i){
    if(LIS_dp[i] != -1) return LIS_dp[i];
    LIS_dp[i] = 1;
    for(int j = 0; j < i; j++){
        if(dims[j].first.first < dims[i].first.first && dims[j].first.second < dims[i].first.second) LIS_dp[i] = max(LIS_dp[i], LIS(j)+1);
    }

    return LIS_dp[i];
}

int main(void){
    int nTypes, d1, d2, d3;
    int maxLIS = 0, maxH = 0;
    int TC = 1;
    FILE *fp = fopen("ans.txt", "w");

    while(true){
        scanf("%d", &nTypes);
        if(nTypes == 0) break;
        maxLIS = maxH = 0;
        dims.clear();

        for(int i = 0; i < nTypes; i++){
            vector<int> tmp;
            scanf("%d %d %d", &d1, &d2, &d3); tmp.push_back(d1); tmp.push_back(d2); tmp.push_back(d3);
            sort(tmp.begin(), tmp.end());
            d1 = tmp[0]; d2 = tmp[1]; d3 = tmp[2];
            dims.push_back(make_pair(make_pair(d1, d2), d3)); dims.push_back(make_pair(make_pair(d2, d3), d1)); dims.push_back(make_pair(make_pair(d3, d1), d2));
            // dims.push_back(make_pair(make_pair(d2, d1), d3)); dims.push_back(make_pair(make_pair(d3, d2), d1)); dims.push_back(make_pair(make_pair(d1, d3), d2));
        }
        // sort by first base dim
        sort(dims.begin(), dims.end(), compare);

        // LIS by second base dim
        memset(LIS_dp, -1, sizeof(LIS_dp)); LIS_dp[0] = 1;
        for(int i = 0; i < dims.size(); i++) maxLIS = max(maxLIS, LIS(i));

        for(int i = 0; i < dims.size(); i++) fprintf(fp, "%d %d %d %d\n", dims[i].first.first, dims[i].first.second, dims[i].second, LIS_dp[i]);
        fprintf(fp, "\n");

        int t = -1;
        int lis = 1;
        for(int i = dims.size()-1; i >= 0; i--){
            if(LIS_dp[i] == maxLIS && t != dims[i].first.first){
                maxH += dims[i].second;
                fprintf(fp, "%d %d %d\n", dims[i].first.first, dims[i].first.second, dims[i].second);
                maxLIS--; t = dims[i].first.first;
                if(maxLIS == 0) break;
            }
        }
        // for(int i = 0; i < dims.size(); i++){
        //     if(LIS_dp[i] == lis && t != dims[i].first.first){
        //         maxH += dims[i].second;
        //         fprintf(fp, "%d %d %d\n", dims[i].first.first, dims[i].first.second, dims[i].second);
        //         lis++; t = dims[i].first.first;
        //         if(lis > maxLIS) break;
        //     }
        // }
        fprintf(fp, "Case %d: maximum height = %d\n", TC, maxH);
        TC++;
    }
    fclose(fp);
    return 0;

}