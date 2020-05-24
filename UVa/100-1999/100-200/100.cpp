#include <cstdio>
using namespace std;

// Complete Search

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int m, n;

	while(scanf("%d" "%d", &m, &n) != EOF){
		for(int i = min(m, n); i <= max(m, n); i++){
			int k = i;

			printf("%d ", k);
			while(k != 1){
				if(k & 1) k = 3 * k + 1;
				else k >>= 1;
				printf("%d ", k);
			}
			printf("\n");
		}
	}
	return 0;
}
