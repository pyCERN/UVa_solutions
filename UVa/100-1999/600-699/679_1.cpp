// UVa 679 - Dropping Balls
// Binary search
#include <cstdio>
#include <cstring>

bool tree[2<<20+1];
int D, I;
int ans[21][524289] = {0,}; // (D, I)

void binarySearch(int depth, int node){
	if(depth == D){
		ans[D][I] = node;
		return;
	}
	int left = node<<1, right = left+1;
	
	tree[node] = !tree[node];
	if(tree[node]) binarySearch(depth+1, left);
	else binarySearch(depth+1, right);
}

int main(void){
	int TC;
	
	for(D = 2; D <= 20; D++){
		memset(tree, false, sizeof(tree));
		for(I = 1; I <= 524288; I++) binarySearch(1, 1);
	}

	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &D, &I);
		printf("%d\n", ans[D][I]);
	}
	scanf("%d", &D);

	return 0;
}