#include <stdio.h>

int main(void) {
	int T = 0;
	int v, v_max = 0;
	int i = 0;

	scanf("%d", &T);

	for(i = 0; i < T; i++){
		while (scanf("%d", &v) != EOF) {
			if (v > v_max) v_max = v;
		}
		printf("Case %d: %d\n", i, v_max);
	}

	return 0;
}