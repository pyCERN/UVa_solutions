#include <iostream>
#include <algorithm>
using namespace std;

// DP

int main(void){
	int N;
	int A[100][100];
	int sum = 0, subRect = 0;
	int maxSubRect = -127*100*100;

	scanf("%d", &N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		scanf("%d", &A[i][j]);
		if(i > 0) A[i][j] += A[i-1][j];
		if(j > 0) A[i][j] += A[i][j-1];
		if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		for(int m = i; m < N; m++) for(int n = j; n < N; n++){
			subRect = A[m][n];
			if(i > 0) subRect -= A[i-1][n];
			if(j > 0) subRect -= A[m][j-1];
			if(i > 0 && j > 0) subRect += A[i-1][j-1];
			maxSubRect = max(maxSubRect, subRect);
		}
	}
	printf("%d\n", maxSubRect);
	return 0;
}
