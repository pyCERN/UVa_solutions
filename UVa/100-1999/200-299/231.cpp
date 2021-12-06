#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector<int> sortedSeq;
    int num, LIS;
    int TC = 0;
    FILE *fp = fopen("ans.txt", "w");

    while(scanf("%d", &num) == 1){
        LIS = 1; sortedSeq.clear();
        if(num < 0) break;
        num = -num; // to make increasing order
        sortedSeq.push_back(num);

        while(scanf("%d", &num) == 1){
            if(num < 0) break;
            num = -num;
            if(num >= sortedSeq[LIS-1]){
                sortedSeq.push_back(num);
                LIS++;
            }
            else{
                auto it = lower_bound(sortedSeq.begin(), sortedSeq.end(), num);
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