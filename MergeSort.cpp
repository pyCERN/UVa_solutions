#include <iostream>
using namespace std;

int *arr;
int N;

void merge(int *arr_sorted, int left, int mid, int right){
    int i = left, j = mid+1, k = left;
    for(int m = left; m <= right; m++) arr[m] = arr_sorted[m];
    
    while(i <= mid && j <= right){
        if(arr[i] < arr[j])
            arr_sorted[k++] = arr[i++];
        else
            arr_sorted[k++] = arr[j++];
    }

    if(i > mid){
        for(int l = j; l <= right; l++)
            arr_sorted[k++] = arr[l];
    }
    else{
        for(int l = i; l <= mid; l++)
            arr_sorted[k++] = arr[l];
    }
}

void merge_sort(int *arr_sorted, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(arr_sorted, left, mid);
        merge_sort(arr_sorted, mid+1, right);
        merge(arr_sorted, left, mid, right);
    }
    else return;
}

int main(void){
    scanf("%d", &N);
    int *arr_sorted = new int[N + 20];
    arr = new int[N + 20];

    for(int i = 0; i < N; i++) scanf("%d", &arr_sorted[i]);

    merge_sort(arr_sorted, 0, N-1);
    for(int i = 0; i < N; i++) printf("%d ", arr_sorted[i]);
    printf("\n");

    delete arr;
    delete arr_sorted;
    arr = nullptr;
    arr_sorted = nullptr;

    return 0;
}