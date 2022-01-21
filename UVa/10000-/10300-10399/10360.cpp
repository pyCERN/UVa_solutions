// UVa 10360 - Rat Attack
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
using namespace std;

int gas[1026][1026] = {0,};

int main(void){
    int TC, d, N, x, y, rats;
    string s;

    scanf("%d", &TC);

    while(TC--){
        int maxRat = 0;
        int ansX, ansY;

        scanf("%d", &d);
        scanf("%d", &N);
        memset(gas, 0, sizeof(gas));
        
        for(int n = 0; n < N; n++){
            scanf("%d %d %d", &x, &y, &rats);
            for(int i = MAX(y-d, 0); i <= MIN(y+d, 1024); i++){
                for(int j = MAX(x-d, 0); j <= MIN(x+d, 1024); j++){
                    gas[i][j] += rats;
                    if(maxRat < gas[i][j]){
                        maxRat = gas[i][j];
                        ansX = j;
                        ansY = i;
                    }
                    else if(maxRat == gas[i][j]){
                        if(ansX > j){
                            ansX = j;
                            ansY = i;
                        }
                    }
                }
            }
        }

        printf("%d %d %d\n", ansX, ansY, maxRat);
        if(TC > 0) getline(cin, s); getline(cin, s);
    }

    return 0;
}