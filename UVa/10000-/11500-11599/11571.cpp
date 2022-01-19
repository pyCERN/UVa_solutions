// UVa 11571 - Simple Equations - Extreme!!
// Complete search
#include <cstdio>
#include <cmath>

int main(void){
	int N;
    long long A, B, C;
FILE *fp = fopen("ans.txt", "w");
	scanf("%d", &N);
	while(N--){
		scanf("%lld %lld %lld", &A, &B, &C);
		bool done = false;
        int xbound = (int)pow(B, 1.0/3), ybound = (int)sqrt(C);

		for(long long x = -xbound; x <= xbound && !done; x++){
            long long x2 = x * x;
            for(long long y = -ybound; y <= ybound && !done; y++){
                long long y2 = y * y;
                if(x != y && x2 + y2 < C){
                    long long z = A - x - y;
                    // printf("%lld %lld %lld\n", x, y, z);
                    long long Bxy = (long long)(B / (x*y));
                    if(z != x && z != y && z == Bxy && x2 + y2 + z*z == C){
                        fprintf(fp, "%lld %lld %lld\n", x, y, z);
                        done = true;
                    }
                }
            }
		}
		if(!done) fprintf(fp, "No solution.\n");
	}
fclose(fp);
	return 0;
}