#include <iostream>

// Complete Search

int main(void){
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);
	for(int x = -22; x <= 22; x++){			// x = y = z
		for(int y = -100; y < 100; y++){
			for(int z = -100; z < 100; z++){
				if(x != y && y != z && z != x){
					if(x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
						printf("%d %d %d\n", x, y, z);
				}
			}
		}
	}
	return 0;
}
