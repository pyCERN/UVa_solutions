// UVa 10576 - Y2K Accounting Bug
// Backtracking
#include <cstdio>
#include <cstring>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

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
*/

int s, d, surplus;
int earn[12];

void backtrack(int i, int num){ // num : sum [0, i-1]
    if(i == 12){
        surplus = MAX(surplus, num);
        return;
    }

    if(i < 4){
        earn[i] = s;
        backtrack(i+1, num+s);
        earn[i] = -d;
        backtrack(i+1, num-d);
    }

    else{ // 4, 5, 6, 7, 8, 9, 10, 11
        int five;
        earn[i] = s;
        five = earn[i-4] + earn[i-3] + earn[i-2] + earn[i-1] + earn[i];
        if(five < 0) backtrack(i+1, num+s);
        earn[i] = -d;
        five = earn[i-4] + earn[i-3] + earn[i-2] + earn[i-1] + earn[i];
        if(five < 0) backtrack(i+1, num-d);
    }
}

int main(void){
    while(scanf("%d %d", &s, &d) == 2){
        surplus = 0;

        backtrack(0, 0);
        if(surplus > 0) printf("%d\n", surplus);
        else printf("Deficit\n");
    }

    return 0;
}