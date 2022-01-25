// UVa 10576 - Y2K Accounting Bug
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
0 1 2 3 4 5 6 7 8 9 10 11 12
0 s s s s s s s s s  s  s  s
2^12 total cases
(s, s, ..., s)
(s, s, ..., -d)
...
(-d, -d, ..., -d)
*/

int s, d, surplus;
int accSum[7]; // save sum of [0..0], ..., [0..6]
FILE *fp = fopen("ans.txt", "w");

void backtrack(int i, int num){ // num : sum [1..i]
    if(i == 12){
        surplus = MAX(surplus, num);
        fprintf(fp, "%d %d\n", num, surplus);
        return;
    }
    int five = 0;
    
    if(i < 7){
        accSum[i] = num;
    }

    // check 5 five months, i = [4..11]
    if(i >= 4){
        if(i == 4) five = num;
        else five = num-accSum[i-5]; // sum of [i-4..i]
    }
    if(five > 0) backtrack(i, num-d);
    else{
        backtrack(i+1, num+s);
        backtrack(i+1, num-d);
    }
}

int main(void){
    scanf("%d %d", &s, &d);
    memset(accSum, 0, sizeof(accSum));
    surplus = 0;

    backtrack(0, 0);
    printf("%d\n", surplus);
fclose(fp);
    return 0;
}