// UVa 441 - Lotto
// Complete search
#include <cstdio>
using namespace std;

int main(void){
	int S[50];
	int TC = 0, N;

	while(scanf("%d", &N), N != 0){
		if(TC > 0) printf("\n");
		for(int i = 0; i < N; i++) scanf("%d", &S[i]);

		for(int i = 0; i < N-5; i++){
			for(int j = i+1; j < N-4; j++){
				for(int k = j+1; k < N-3; k++){
					for(int l = k+1; l < N-2; l++){
						for(int m = l+1; m < N-1; m++){
							for(int n = m+1; n < N; n++) printf("%d %d %d %d %d %d\n", S[i], S[j], S[k], S[l], S[m], S[n]);
						}
					}
				}
			}
		}
		TC++;
	}

	return 0;
}