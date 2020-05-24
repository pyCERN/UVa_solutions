#include <iostream>

int main(void){
	for(int i = 0; i < 10; i++){
		int j = i + 1;
		if(j % 2) j++;
		i = j;
		printf("%d\n", i);
	}
	return 0;
}
