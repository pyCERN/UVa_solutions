// UVa 957 - Popes
// Binary search
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int Y, P;
vector<int> years;

int main(void){
    int year, L;
    int maxPopes, firstY, lastY;

    while(scanf("%d", &Y) == 1){
        scanf("%d", &P);
        years.clear(); maxPopes = 0;
        for(int i = 0; i < P; i++){
            scanf("%d", &year);
            years.push_back(year);
        }

        for(int i = years.size()-1; i >= 0; i--){
            int y = years[i];
            int numPopes = upper_bound(years.begin()+i, years.end(), y+Y-1) - (years.begin()+i);
            if(numPopes >= maxPopes){
                maxPopes = numPopes;
                firstY = y;
                lastY = years[numPopes+i-1];
            }
        }
        printf("%d %d %d\n", maxPopes, firstY, lastY);
    }

    return 0;
}