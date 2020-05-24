#include <iostream>
#include <cmath>

// Binary Search

int max_node;

int search(int node, int balls){
	int left = 2 * node, right = left + 1;
	if(left < max_node && right <= max_node){
		if(balls % 2) return search(left, balls / 2 + 1);
		else return search(right, balls / 2);
	}
	else return node;
}

int main(void){
	int T, D, I;

	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &D, &I);
		max_node = pow(2, D);
		printf("%d\n", search(1, I));
	}
	return 0;
}
