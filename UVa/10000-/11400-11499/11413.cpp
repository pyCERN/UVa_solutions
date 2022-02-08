// UVa 11413 - Fill the Containers
#include <cstdio>
#include <vector>
using namespace std;

bool canFill(vector<int> vessels, int maxCapacity, int m){
    int nContainers = 1;
    int capacity = maxCapacity;

    for(int i = 0; i < vessels.size(); i++){
        if(vessels[i] > maxCapacity) return false;
        if(vessels[i] > capacity){
            nContainers++;
            
        }
    }
}

int main(void){
    int n, m;

    scanf("%d %d", &n, &m);
    vector<int> vessels(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &vessels[i]);
    
}