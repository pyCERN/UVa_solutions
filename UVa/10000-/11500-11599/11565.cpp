// UVa 11565 - Simple Equations
// Complete search
#include <cstdio>

int main(void){
	int N, A, B, C;

	scanf("%d", &N);
	while(N--){
		scanf("%d %d %d", &A, &B, &C);
		bool done = false;

		for(int x = -100; x <= 100 && !done; x++){
			for(int y = -100; y <= 100 && !done; y++){
				for(int z = -100; z <= 100 && !done; z++){
					if(!(x | y | z)) continue;
					if(x == y || y == z || z == x) continue;
					if(x + y + z == A && x * y * z == B && x*x + y*y + z*z == C){
						printf("%d %d %d\n", x, y, z);
						done = true;
					}
				}
			}
		}
		if(!done) printf("No solution.\n");
	}

	return 0;
}