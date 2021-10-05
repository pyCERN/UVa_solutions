#include <cstdio>
using namespace std;

// DP

// 1D
int Max1DRangeSum(int n, int A[]){
    int ans = 0, sum = 0;

    for(int i = 0; i < n; i++){
        sum += A[i];
        ans = max(ans, sum);
        if(sum < 0) sum = 0;
    }
    return ans;
}

// 2D m x n
/*
A[i][j] = A[i-1][j] + A[i][j-1] - A[i-1][j-1] + A[i][j]
O(n^4)
*/
int Max2DRangeSum(int M, int N, int *A[]){
    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            if(i > 0) A[i][j] += A[i-1][j];
            if(j > 0) A[i][j] += A[i][j-1];
            if (i > 0 && j > 0)
                A[i][j] -= A[i-1][j-1];
        }
    }
    /*
    sum of A[i:m][j:n]
    A[m][n] - A[m][j-1] - A[i-1][n] + A[i-1][j-1]
    */
    int min_value = 127 * 100 * 100;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            for(int m = i; m < M; m++){
                for(int n = j; n < N; n++){
                    int sub_value = A[m][n];
                    if(i > 0) sub_value -= A[i-1][n];
                    if(j > 0) sub_value -= A[m][j-1];
                    if(i > 0 && j > 0) sub_value += A[i-1][j-1];
                    min_value = min(min_value, sub_value);
                }
            }
        }
    }
    return min_value;
}
