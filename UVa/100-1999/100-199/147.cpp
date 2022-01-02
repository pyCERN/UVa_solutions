// UVa 147 - Dollars
// DP (coin change)
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int dollars[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long DP[30001];

void waysOfChange(void){
    DP[0] = 1;

    for(int i = 0; i < 11; i++){
        for(int value = dollars[i]; value <= 30000; value++) DP[value] += DP[value-dollars[i]];
    }
}

int main(void){
    double temp;
    int money;

    memset(DP, 0, sizeof(DP));
    waysOfChange();

    while(scanf("%lf", &temp), temp != 0.00f){
        money = round(100.0 * temp);
        printf("%6.2lf%17lld\n", temp, DP[money]);
    }

    return 0;
}