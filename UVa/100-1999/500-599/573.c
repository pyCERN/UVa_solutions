#include <stdio.h>

void cal_day(int H, int U, int D, int F){
	float d = 0, fatigue = 0.01*F;
	int t = 0;
	float climb;
	while(1){
		t++;

		// day
		climb = U - fatigue*(t-1)*U;
		if(climb < 0) climb = 0;
		d += climb;
		if(d > H){
			printf("success on day %d\n", t);
			return;
		}
		// night
		d -= D;
		if(d < 0){
			printf("failure on day %d\n", t);
			return;
		}
	}
}

int main(void){
	int H, U, D, F;

	while(scanf("%d %d %d %d", &H, &U, &D, &F), H){
		cal_day(H, U, D, F);	
	}

	return 0;
}
