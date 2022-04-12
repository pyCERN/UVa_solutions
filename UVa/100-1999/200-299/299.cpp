// UVa 299 - Train Swapping
// Bubble sort
#include <cstdio>
using namespace std;

int main(void){
    int TC; scanf("%d", &TC);

    while(TC--){
        int L, ans = 0;
        int arr[51];

        scanf("%d", &L);
        for(int i = 0; i < L; i++) scanf("%d", &arr[i]);

        for(int i = 0; i < L-1; i++){
            for(int j = i+1; j < L; j++){
                if(arr[i] > arr[j]){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    ans++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }

    return 0;
}