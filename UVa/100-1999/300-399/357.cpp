// UVa 357 - Let Me Count The Ways
// DP (coin change)
#include <cstdio>
#include <cstring>
using namespace std;

int coins[] = {1, 5, 10, 25, 50};
int cent;
long long DP[30001][5]; // cent required to produce value

long long waysOfChange(int value, int coinIndex){
    if(value == 0) return 1;
    if(DP[value][coinIndex] != -1) return DP[value][coinIndex];

    long long ways = 0;

    for(int i = coinIndex; i < 5; i++){
        if(value >= coins[i])
            ways += waysOfChange(value-coins[i], i);
    }
    DP[value][coinIndex] = ways;

    return DP[value][coinIndex];
}

// void waysOfChange(void){
//     DP[0] = 1;
    
//     for(int i = 0; i < 5; i++){
//         for(int value = 0; value <= 30000; value++){
//             if(value >= coins[i]) DP[value] += DP[value-coins[i]];
//         }
//     }
// }

int main(void){
    long long ans;
    
    memset(DP, -1, sizeof(DP)); DP[0][0] = 1;
    waysOfChange(30000, 0);

    while(scanf("%d", &cent) == 1){
        ans = DP[cent][0];
        if(ans == 1) printf("There is only 1 way to produce %d cents change.\n", cent);
        else printf("There are %lld ways to produce %d cents change.\n", ans, cent);
    }

    return 0;
}