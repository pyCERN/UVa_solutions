#include <iostream>
#include <cstring>
#include <cstdlib>

int row[8], a, b, lineCount;

bool check(int r, int c){
	for(int prev = 0; prev < c; prev++)
		if(row[prev] == r || abs(row[prev] - r) == abs(prev - c)) return false;
	return true;
}

void place(int c){
	if(c == 8 && row[b] == a){
		printf("%d ", lineCount++);
		for(int i = 0; i < 8; i++){
			printf("%d ", row[i] + 1);
			if(i == 7) printf("\n");
		}
	}
	for(int r = 0; r < 8; r++){
		if(check(r, c)){
			row[c] = r;
			place(c+1);
		}
	}
}	
		
int main(void){
	int n;

	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &a, &b); a--; b--;
		memset(row, 0, sizeof row);
		lineCount++;
		printf("SOLN COLUMN\n");
		printf("# 1 2 3 4 5 6 7 8\n\n");
		place(0);
		if(n) printf("\n");
	}
	return 0;
}
