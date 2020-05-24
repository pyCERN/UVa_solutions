#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(void){
	vi spec;
	int C, S, s, c = 0;
	float avg;
	float imb;
	
	while(scanf("%d %d", &C, &S) != EOF){
		avg = 0.0f;
		imb = 0.0f;
		spec.clear();
		for(int i = 0; i < S; i++) { scanf("%d", &s); spec.push_back(s); avg += s; }
		avg /= C;

		if(S < 2 * C) for(int i = 0; i < 2 * C - S; i++) spec.push_back(0);
		sort(spec.begin(), spec.end());

		printf("Set #%d\n", ++c);
		for(int i = 0; i < C; i++){
			int a = spec[i], b = spec[2 * C - i -1];
			imb += fabs(a + b - avg);
			printf(" %d : ", i);
			if(a) printf("%d %d\n", a, b);
			else printf("%d\n", b);
		}
		printf("IMBALANCE = %.5f\n", imb);
	}
	return 0;
}
