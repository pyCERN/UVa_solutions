#include <stdio.h>

int main(void){
	int t = 0;
	int a = 0, b = 0;

	scanf("%d", &t);
	
	while((t--) > 0){
		scanf("%d %d", &a, &b);
		if(a > b)
			puts(">");
		else if(a < b)
			puts("<");
		else puts("=");
	}
	return 0;
}
