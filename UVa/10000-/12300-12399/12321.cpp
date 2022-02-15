// UVa 12321 - Gas Stations
// Interval covering problem (Greedy)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool compare(ii &a, ii &b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main(void){
    int L, G;

    while(scanf("%d %d", &L, &G), L | G){
        vector<ii> station(G);
        int left = 0, right = 0, cnt = 0;

        for(int i = 0; i < G; i++){
            int x, r;
            scanf("%d %d", &x, &r);
            station[i] = make_pair(max(x-r, 0), min(x+r, L));
        }
        
        sort(station.begin(), station.end(), compare);
        int i = 0;
        while(left < L){
            while(i < G && station[i].first <= left) // go as furthest as possible while left bound of interval <= min bound of current range
                right = max(right, station[i++].second);
            if(left == right) // right not changed -> interval cannot go further
                break;
            // select next interval as start
            left = right;
            cnt++;
        }
        if(right < L) printf("-1\n");
        else printf("%d\n", G-cnt);
    }

    return 0;
}