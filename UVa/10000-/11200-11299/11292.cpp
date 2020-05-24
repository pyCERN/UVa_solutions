#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(void){
	int n, m, gold;
	int d, k;
	vi dragon, knight;

	while((scanf("%d %d", &n, &m) != EOF) && (n != 0 && m !=0)){
		dragon.clear(); knight.clear();

		for(int i = 0; i < n; i++) { int dd; scanf("%d", &dd); dragon.push_back(dd); }
		for(int i = 0; i < m; i++) { int kh; scanf("%d", &kh); knight.push_back(kh); }
		if(n > m) { printf("Loowater is doomed!\n"); continue; }
		sort(dragon.begin(), dragon.end()); sort(knight.begin(), knight.end());
		gold = d = k = 0;
		while(d < n && k < m){
			while(knight[k] < dragon[d]) k++;
			if(k == m) break;
			gold += knight[k];
			d++; k++;
		}
		if(d == n) printf("%d\n", gold);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}

