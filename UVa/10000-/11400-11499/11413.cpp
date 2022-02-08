// UVa 11413 - Fill the Containers
// Bisection method
#include <cstdio>
#include <vector>
using namespace std;

// Assume that each m containers has maxCapacity
bool canFill(vector<int> vessels, int maxCapacity, int m){
    int nContainers = 1;
    int capacity = maxCapacity;

    for(int i = 0; i < vessels.size(); i++){
        if(vessels[i] > maxCapacity) return false;
        if(vessels[i] > capacity){
            if(nContainers == m) // if reached to the last container but vessels remained
                return false;
            // else increase # of new container
            nContainers++;
            capacity = maxCapacity;
        }
        capacity -= vessels[i];
    }
    return true;
}

int main(void){
    int n, m;

    while(scanf("%d %d", &n, &m) == 2){
        vector<int> vessels(n);
        int sum = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &vessels[i]);
            sum += vessels[i];
        }
        
        int lo = 1, hi = sum, mid, ans;
        while(hi-lo >= 0){
            mid = (hi + lo) / 2;
            if(canFill(vessels, mid, m)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        printf("%d\n", ans);
    }

    return 0;
}