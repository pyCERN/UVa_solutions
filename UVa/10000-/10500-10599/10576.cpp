// UVa 10576 - Y2K Accounting Bug
#include <cstdio>

/*
0, 1, 2, 3, 4
1, 2, 3, 4, 5
2, 3, 4, 5, 6
3, 4, 5, 6, 7
4, 5, 6, 7, 8
5, 6, 7, 8, 9
6, 7, 8, 9, 10
7, 8, 9, 10, 11

2^12 total cases
(s, s, ..., s)
(s, s, ..., -d)
...
(-d, -d, ..., -d)
*/

int s, d, surplus;
int five[8];

void backtrack(int i, int num){
    if(i == 12){
        return;
    }

    if(i >= 5){
        
    }
}

int main(void){
    scanf("%d %d", &s, &d);
    surplus = 0;

    backtrack(0, 0);

    return 0;
}