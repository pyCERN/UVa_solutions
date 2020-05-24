#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// lower_bound, upper_bound

typedef vector<int> vi;
vi heights;

int main(void){
	int N, Q;

	scanf("%d", &N);
	for(int i = 0; i < N; i++){ int h; scanf("%d", &h); heights.push_back(h); }
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		int q;
		scanf("%d", &q);
		auto low = lower_bound(heights.begin(), heights.end(), q);
		auto upp = upper_bound(heights.begin(), heights.end(), q);
		auto ind1 = low - heights.begin();
		auto ind2 = upp - heights.begin();
		if(heights[ind1-1] == 0) printf("X ");
		else printf("%d ", heights[ind1-1]);

		if(heights[ind2] == 0) printf("X\n");
		else printf("%d\n", heights[ind2]);
	}
	return 0;
}
