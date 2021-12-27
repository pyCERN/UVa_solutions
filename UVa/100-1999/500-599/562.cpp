// UVa 562 - Dividing coins
#include <cstdio>
using namespace std;

/*
(id, remW)
0 - ignore
1 - take
*/
int val[105][100*500], V[105];
int m;

int knapsack(int id, int remVal){
    val[id][0] = 0;

    for(int i = m-1; i >= 0; i--){
        for(int remW = 
    }
}

int main(void){
    scanf("%d", &m);

    for(int i = 0; i < m; i++) scanf("%d", &

}