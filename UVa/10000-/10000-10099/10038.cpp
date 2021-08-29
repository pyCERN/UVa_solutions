#include <cstdio>
using namespace std;

int abs(int a){
    return a > 0 ? a : -a;
}

int main(void){
    int N;
    int *arr;
    bool *flag, is_jolly;

    while(scanf("%d", &N) != EOF){
        int abs_diff;
        is_jolly = true;

        arr = new int[N];
        flag = new bool[N-1]();
        for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
        for(int i = 0; i < N-1; i++){
            abs_diff = abs(arr[i] - arr[i+1]);
            if(abs_diff <= N-1) flag[abs_diff-1] = true;
        }
        for(int i = 0; i < N-1; i++){
            if(!flag[i]){
                is_jolly = false;
                break;
            }
        }
        if(is_jolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }

    delete arr; arr = nullptr;
    delete flag; flag = nullptr;

    return 0;
}