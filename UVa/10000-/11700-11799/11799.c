#include <stdio.h>

int main(void){
	int T;
	int c, v, v_max = 0;
	int i;

	scanf("%d", &T);

	for(i = 0; i < T; i++){
		v_max = 0;
		scanf("%d", &c);
		while(c--){
			scanf("%d", &v);
			if(v > v_max) v_max = v;
		}
		printf("Case %d: %d\n", i+1, v_max);
	}

	return 0;
}
