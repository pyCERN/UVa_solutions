#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort and lower_bound

typedef vector<int> vi;
vi v, query;

int main(void){
	int T;
	int N = -1, Q = -1;
	int c = 0;

	while(N != 0 || Q != 0){
		v.clear(); query.clear();
		scanf("%d %d", &N, &Q);
		for(int i = 0; i < N; i++){
			int n; scanf("%d", &n);
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < Q; i++){
			int q; scanf("%d", &q);
			query.push_back(q);
		}
		if(N != 0 || Q != 0) printf("CASE# %d:\n", ++c);
		for(int i = 0; i < Q; i++){
			int q = query[i];
			auto low = lower_bound(v.begin(), v.end(), q);
			auto pos = low - v.begin();
			if(q == v[pos]) printf("%d found at %d\n", q, pos + 1);
			else printf("%d not found\n", q);
		}
	}
	return 0;
}
