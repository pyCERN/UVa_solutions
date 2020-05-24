#include <iostream>
#include <bitset>
#define POW(n) (1 << n)
using namespace std;

int main(void){
	int T, D, I;
	int offset;
	int s;

	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &D, &I);
		s = 0;
		offset = POW(D-1);
		bitset<20> bs(I-1);
		for(int i = 0; i < D - 1; i++) s += POW(D-2-i) * bs.test(i);
		s += offset;
		printf("%d\n", s);
	}
	return 0;
}
