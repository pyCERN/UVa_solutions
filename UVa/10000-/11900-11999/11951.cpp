// UVa 11951 - Area
#include <cstdio>
#include <cstring>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    int t = 0, T;
    int N, M, K;
    int arr[110][110];
    long long subRect[110][110];
    int area, ansArea;
    long long sum, ansCost;

    scanf("%d", &T);

    while(t++ < T){
        scanf("%d %d %d", &N, &M, &K);
        memset(arr, 0, sizeof(arr));
        for(int r = 0; r < N; r++){
            for(int c = 0; c < M; c++) scanf("%d", &arr[r][c]);
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                sum = 0;
                for(int m = 0; m <= i; m++){
                    for(int n = 0; n <= j; n++) sum += arr[m][n];
                }
                subRect[i][j] = sum;
            }
        }

        /*
        sum from (i, j) to (m, n)
        subRect[m][n] - subRect[i-1][n] - subRect[m][j-1] + subRect[i-1][j-1]
        */
        ansArea = 0; ansCost = (long long)100 * 100 * 1000000;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                for(int m = i; m < N; m++){
                    for(int n = j; n < M; n++){
                        sum = subRect[m][n];
                        area = (m-i+1) * (n-j+1);
                        if(i > 0) sum -= subRect[i-1][n];
                        if(j > 0) sum -= subRect[m][j-1];
                        if(i > 0 && j > 0) sum += subRect[i-1][j-1];
                        if(ansArea <= area && sum <= K){
                            if(ansArea == area) ansCost = min(ansCost, sum);
                            else ansCost = sum;
                            ansArea = area;
                        }
                    }
                }
            }
        }
        if(ansArea == 0) ansCost = 0;
        printf("Case #%d: %d %lld\n", t, ansArea, ansCost);
    }

    return 0;
}