// UVa 983 - Localized Summing for Blurring
#include <cstdio>
#include <cstring>
using namespace std;

int arr[1010][1010];
long long subRect[1010][1010];

int main(void){
    int N, M, TC = 0;
    long long sum, sumOfSum;

    while(scanf("%d %d", &N, &M) == 2){
        memset(arr, 0, sizeof(arr));
        for(int i = N-1; i >= 0; i--){
            for(int j = 0; j < N; j++) scanf("%d", &arr[i][j]);
        }
        if(TC++) printf("\n");

        sumOfSum = 0;
        for(int i = N-1; i >= M-1; i--){
            for(int j = 0; j <= N-M; j++){
                sum = 0;
                for(int r = i; r >= i-M+1; r--){
                    for(int c = j; c < j+M; c++) sum += arr[r][c];
                }
                subRect[i][j] = sum;
                sumOfSum += sum;
                printf("%d\n", sum);
            }
        }

        printf("%lld\n", sumOfSum);
    }

    return 0;
}
