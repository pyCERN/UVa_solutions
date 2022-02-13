// UVa 11389 - The Bus Driver Problem
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool greater(int a, int b){
    return a > b;
}

int main(void){
    int n, d, r; // # of drivers, day route limit, overtime pay per hour

    while(scanf("%d %d %d", &n, &d, &r), n | d | r){
        vector<int> morning(n), afternoon(n);
        int sum = 0;

        for(int i = 0; i < n; i++) scanf("%d", &morning[i]);
        for(int i = 0; i < n; i++) scanf("%d", &afternoon[i]);
        sort(morning.begin(), morning.end());
        sort(afternoon.begin(), afternoon.end(), greater);

        for(int i = 0; i < n; i++) sum += (morning[i] + afternoon[i] > d ? morning[i] + afternoon[i] - d : 0) * r;
        printf("%d\n", sum);
    }

    return 0;
}