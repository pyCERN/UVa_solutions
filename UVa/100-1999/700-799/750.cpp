// UVa 750 - 8 Queens Chess Problem
// Backtracking
#include <iostream>
#include <cstring>
#include <string>
#define ABS(x) ((x) > 0 ? (x) : -(x))
using namespace std;

int row[10] = {0,}; // row[i] : position of queen at i-th row
int R, C, nSol;

bool check(int r, int c){
	for(int prevRow = 1; prevRow < r; prevRow++){
		if(c == row[prevRow] || r-prevRow == ABS(row[prevRow]-c)) return false;
	}
	return true;
}

void backtrack(int r){
	if(r == 9 && row[R] == C){
		nSol++;
		printf("%2d      ", nSol);
		for(int rr = 1; rr <= 8; rr++) printf("%d ", row[rr]);
		printf("\n");
		return;
	}

	for(int c = 1; c <= 8; c++){
		if(check(r, c)){
			row[r] = c;
			backtrack(r+1);
		}
	}
}

int main(void){	
	int TC;
	string s;

	scanf("%d", &TC); getline(cin, s); getline(cin, s);
	while(TC--){
		memset(row, 0, sizeof(row)); nSol = 0;
		scanf("%d %d", &R, &C);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(1);
	}

	return 0;
}