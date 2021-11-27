// UVa 481 - What Goes Up
// Longest Increasing Subsequence (LIS) + Greedy O(nlogn)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 1000000000
using namespace std;

int main(void){
    int LIS = 0, len = 0, pos, num;
    vector<int> seq, sortedSeq, idx;
    stack<int> ans;

    sortedSeq.push_back(-INF);

    while(scanf("%d", &num) == 1){
        seq.push_back(num);

        if(num > sortedSeq[len]){
            sortedSeq.push_back(num);
            len++; LIS++;
            idx.push_back(LIS);
        }
        else{
            auto it = lower_bound(sortedSeq.begin(), sortedSeq.end(), num);
            if(*it != num){
                *it = num;
                idx.push_back(it-sortedSeq.begin());
            }
            else idx.push_back(-1);
        }
    }

    printf("%d\n-\n", LIS);
    for(int i = idx.size(); i >= 0; i--){
        if(idx[i] == LIS){
            LIS--;
            ans.push(seq[i]);
        }
    }
    while(!ans.empty()){
        printf("%d\n", ans.top());
        ans.pop();
    }

    return 0;
}