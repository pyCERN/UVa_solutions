// UVa 352 - The Seasonal War
// Floodfill
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
int map[26][26];
// E, EN, N, NW, W, WS, S, SE
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1}, dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(void){
    int numOfCC = 0;

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(map[r][c] != 1) continue;
            queue<pair<int, int> > q; q.push(make_pair(r, c));

            while(!q.empty()){
                pair<int, int> u = q.front(); q.pop();
                int r = u.first, c = u.second;
                for(int i = 0; i < 8; i++){
                    int rr = r + dr[i], cc = c + dc[i];
                    if(rr > N || cc > N || rr < 0 || cc < 0) continue;
                    if(map[rr][cc] == 1){
                        map[rr][cc] = 2;
                        q.push(make_pair(rr, cc));
                    }
                }
            }
            numOfCC++;
        }
    }

    return numOfCC;
}

int main(void){
    int TC = 1;

    while(scanf("%d", &N) != EOF){
        for(int r = 0; r < N; r++){
            string s;
            cin >> s;
            for(int c = 0; c < N; c++) map[r][c] = s[c]-48;
        }
        printf("Image number %d contains %d war eagles.\n", TC++, floodfill());
    }

    return 0;
}