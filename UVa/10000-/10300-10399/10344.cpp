// UVa 10344 - 23 out of 5
// Backtracking
#include <cstdio>
#include <algorithm>
using namespace std;

int nums[5];
bool flag = false;

void backtrack(int i, int num){
    if(i == 5){
        if(num == 23){
            flag = true;
        }
        return;
    }

    backtrack(i+1, num+nums[i]);
    backtrack(i+1, num-nums[i]);
    backtrack(i+1, num*nums[i]);
}

int main(void){
    while(true){
        for(int i = 0; i < 5; i++) scanf("%d", &nums[i]);
        if(nums[0] == 0) break;
        flag = false;

        sort(nums, nums+5);
        do{
            backtrack(1, nums[0]);
            if(flag) break;
        }while(next_permutation(nums, nums+5));

        if(flag) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}