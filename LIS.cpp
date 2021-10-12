#include <cstdio>
using namespace std;

int N;
int A[100];
int LIS_dp[100];

int max(int a, int b){
    return a > b ? a : b;
}

int LIS(int i){ // Length of sequence ending at i
    int max_LIS = 1;
    
    for(int j = 0; j < i; j++){
        if(j < i && A[j] < A[i]){
            max_LIS = max(max_LIS, LIS(j) + 1);
        }
    }
    LIS_dp[i] = max_LIS;
    return max_LIS;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    LIS_dp[0] = 1;
    for(int i = 0; i < N; i++) LIS(i);
    
    for(int i = 0; i < N; i++) printf("%d ", LIS_dp[i]);
    printf("\n");

    return 0;
}