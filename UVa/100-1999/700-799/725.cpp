// UVa 725 - Division
// Complete search
#include <cstdio>
#include <bitset>
using namespace std;

int main(void){
	int TC = 0, N;
	bitset<10> used;

	while(scanf("%d", &N), N != 0){
		int num = 0;
		if(TC > 0) printf("\n");

		for(int fghij = 1234; fghij <= 98765/N; fghij++){
			bool f = (fghij < 10000);
			int abcde = fghij * N;
			// digits check for abcde, fghij
			used.set();
			for(int tmp = fghij; tmp > 0; tmp /= 10) used.set(tmp%10, 0);
			for(int tmp = abcde; tmp > 0; tmp /= 10) used.set(tmp%10, 0);
			if(f) used.set(0, 0);
			if(!used.any()){
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
				num++;
			}
		}
		if(num == 0) printf("There are no solutions for %d.\n", N);
		TC++;
	}

	return 0;
}