#include <iostream>
#include <algorithm>
using namespace std;

// DP

int main(void){
	int TC, cases = 0;
	int s, x;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &s);
		int sum = 0, ans = 0;
		int begin = 1, end = 1;
		int tmp = 1;
		for(int i = 1; i <= s - 1; i++){
			scanf("%d", &x);
			sum += x;
			if(sum > ans || (sum == ans && (i - tmp) > (end - begin))){
				ans = sum;
				end = i;
				begin = tmp;
			}
			if(sum < 0) { sum = 0; tmp = i + 1; }
		}
		if(ans > 0) printf("The nicest part of route %d is between stops %d and %d\n", ++cases, begin, end + 1);
		else printf("Route %d has no nice parts\n", ++cases);
	}
	return 0;
}
