#include <cstdio>
using namespace std;

#define MIN 10000001

int L, n;
int A[52];
/*
cut_dp[i][j]
piece of [A[i], A[j]]
*/
int cut_dp[52][52] = {0,};

int min(int a, int b){
    return a < b ? a : b;
}

// return min cost given piece of [A[left], A[right]]
int cut(int left, int right){
    int min_cost = MIN;

    if(left + 1 == right) return 0;
    if(cut_dp[left][right] != -1) return cut_dp[left][right];
    
    for(int i = left + 1; i < right; i++){
        int cost = cut(left, i) + cut(i, right) + (A[right] - A[left]);
        min_cost = min(min_cost, cost);
    }
    cut_dp[left][right] = min_cost;
    return min_cost;
}

int main(void){
    while(true){
        scanf("%d", &L);
        if(L == 0) break;
        scanf("%d", &n);

        A[0] = 0; A[n+1] = L;
        for(int i = 1; i < n+1; i++) scanf("%d", &A[i]);
        for(int i = 0; i < n+2; i++){
            for(int j = 0; j < n+2; j++) cut_dp[i][j] = -1;
        }

        printf("The minimum cutting is %d.\n", cut(0, n+1));
    }

    return 0;
}