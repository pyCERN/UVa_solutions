#include <iostream>
using namespace std;

int *arr_sorted;

void counting(int *count){
    int k = 0;

    for(int i = 0; i < 10000; i++){
        if(count[i] == 0) continue;
        for(int j = 0; j < count[i]; j++)
            arr_sorted[k++] = i;
    }
}

int main(void){
    int n, N;
    scanf("%d", &N);
    int *count = new int[10000]();

    for(int i = 0; i < N; i++){
        scanf("%d", &n);
        count[n]++;
    }
    counting(count);

    delete count;
    count = nullptr;

    return 0;
}