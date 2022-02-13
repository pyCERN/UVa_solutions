// UVa 12321 - Gas Stations
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool leftmost(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

bool rightmost(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

bool isCovered(pair<int, int> a, pair<int, int> b){
    if(b.first < a.first || b.second > a.second) return false;
    return true;
}

int main(void){
    int L, G;

    scanf("%d %d", &L, &G);
    vector<pair<int, int>> station(G);

    for(int i = 0; i < G; i++){
        int x, r;
        scanf("%d %d", &x, &r);
        station[i] = make_pair(x-r, x+r);
    }
    
    sort(station.begin(), station.end(), leftmost);
    sort(station.begin(), station.end(), rightmost);

    return 0;
}