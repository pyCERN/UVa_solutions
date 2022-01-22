// UVa 729 - The Hamming Distance Problem
// Backtracking
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <bitset>
using namespace std;

int N, H;
bitset<16> origin, bits;

void backtrack(int nFlipped, int idx){
    if(nFlipped == H){
        for(int i = 0; i < N; i++) cout << bits[i];
        printf("\n");
        return;
    }

    for(int i = N-1; i >= idx; i--){
        if(bits[i] ^ origin[i] == 0){
            bits[i] = !origin[i];
            backtrack(nFlipped+1, i);
            bits[i] = origin[i];
        }
    }
}

int main(void){
    int TC;
    string s;

    scanf("%d", &TC);
    getline(cin, s); getline(cin, s);
    origin.reset();

    while(TC--){
        scanf("%d %d", &N, &H);
        getline(cin, s); getline(cin, s);

        bits.reset();
        backtrack(0, 0);
        if(TC > 0) printf("\n");
    }

    return 0;
}