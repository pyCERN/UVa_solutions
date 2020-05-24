#include <iostream>
using namespace std;

// Complete Search 

int main(void){
	int N = 62;

	for(int fghij = 1234; fghij < 98765 / N; fghij++){
		int abcde = fghij * N;
		int tmp, diff = (fghij < 10000);
		tmp = abcde;
		while(tmp) { diff |= 1 << (tmp % 10); tmp /= 10; }
		tmp = fghij;
		while(tmp) { diff |= 1 << (tmp % 10); tmp /= 10; }

		if(diff == (1 << 10) -1)
			printf("%.5d, %.5d\n", abcde, fghij);
	}
	return 0;
}

