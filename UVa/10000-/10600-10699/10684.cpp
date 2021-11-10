// UVa 10684 - The jackpot
#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
    int N;
    int seq[10010];

    while(scanf("%d", &N), N){
        int ans = 0, sum = 0;
        memset(seq, 0, sizeof(seq));
        for(int i = 0; i < N; i++) scanf("%d", &seq[i]);
        for(int i = 0; i < N; i++){
            sum = 0;
            for(int j = i; j < N; j++){
                sum += seq[j];
                if(ans < sum) ans = sum;
            }
        }
        if(ans > 0) printf("The maximum winning streak is %d.\n", ans);
        else printf("Losing streak.\n");
    }

    return 0;
}