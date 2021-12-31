// UVa 1213 - 
#include <cstdio>
#include <cstring>
using namespace std;

unsigned DP[1140][20][200], primes[200];
int N, K, nPrimes;

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// if sum of k primes[1:i] == n
int knapsack(int n, int k, int i){
    // if sum of k primes == N
    if(n == 0 && k == 0) return 1;
    if(n > 0 && k == 0) return 0;
    if(n < 0 || k < 0) return 0;
    if(primes[i] > N) return 0;

    if(DP[n][k][i] != -1) return DP[n][k][i];

    DP[n][k][i] = knapsack(n, k, i+1) + knapsack(n-primes[i], k-1, i+1);

    return DP[n][k][i];
}

int main(void){
    memset(DP, -1, sizeof(DP));
    nPrimes = 0;

    for(int n = 2; n <= 1130; n++){
        if(isPrime(n)) primes[++nPrimes] = n;
    }

    while(scanf("%d %d", &N, &K), N | K){
        printf("%d\n", knapsack(N, K, 1));
    }

    return 0;
}