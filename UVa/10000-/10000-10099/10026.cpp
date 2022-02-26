// UVa 10026 - Shoemaker's Problem
// Greedy
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

/*
Compare i-th, j-th tasks
(1) i -> j
    fine: prev * Si + (prev + Ti) * Sj
(2) j -> i
    fine: prev * Sj + (prev + Tj) * Si
*/
bool compare(iii &i, iii &j){
    int Ti = i.first.first, Tj = j.first.first;
    int Si = i.first.second, Sj = j.first.second;
    int ij = Sj * Ti, ji = Si * Tj;

    return ij < ji;
}

int main(void){
    int TC, N;
    string s;

    scanf("%d", &TC);

    while(TC--){
        getline(cin, s);
        scanf("%d", &N);

        viii jobs(N);
        for(int i = 0; i < N; i++){
            scanf("%d %d", &jobs[i].first.first, &jobs[i].first.second);
            jobs[i].second = i+1;
        }
        sort(jobs.begin(), jobs.end(), compare);

        for(int i = 0; i < N; i++){
            printf("%d", jobs[i].second);
            if(i < N-1) printf(" ");
        }
        printf("\n");
        if(TC) printf("\n");
    }
    
    return 0;
}