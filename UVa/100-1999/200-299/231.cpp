#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector<int> ans;
    int num, LIS = 1;
    int TC = 0;
    FILE *fp = fopen("ans.txt", "w");

    while(scanf("%d", &num) == 1){
        LIS = 1; ans.clear();
        if(num < 0) break;
        num = -num; // to make increasing order
        ans.push_back(num);

        while(scanf("%d", &num) == 1){
            if(num < 0) break;
            num = -num;
            if(num >= ans[LIS-1]){
                ans.push_back(num);
                LIS++;
            }
            else{
                auto it = lower_bound(ans.begin(), ans.end(), num);
                *it = num;
            }
        }
        if(TC) fprintf(fp, "\n");
        // printf("Test #%d:\n", TC++);
        // printf("  maximum possible interceptions: %d\n", LIS);
        fprintf(fp, "Test #%d:\n", ++TC);
        fprintf(fp, "  maximum possible interceptions: %d\n", LIS);
    }
    fclose(fp);
    return 0;
}