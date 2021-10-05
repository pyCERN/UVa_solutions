#include <cstdio>
#include <map>
using namespace std;

/*
items : V, W, S
state : (id, remW)
val[id, 0] = 0 # no remaining weight
val[n, remW] = 0 # searched all items
else:
    if W[id] > remW:
        val[id, remW] = val[id + 1, remW] # ignore, search next item
    else:
        # ignore
        val[id, remW] = val[id + 1, remW]
        # take
        val[id, remW] = V[id] + val[id + 1, remW - W[id]]

        val[id, remW] = max(val[id + 1, remW], V[id] + val[id + 1, remW - W[id]])
*/

int N, K;
int *V, *W;
int val[101][100001] = {0,};

void knap(void){
    for(int id = N-1; id >= 0; id--){
        for(int remW = K; remW >= 0; remW--){
            if(W[id] > remW) val[id][remW] = val[id + 1][remW];
            else val[id][remW] = max(val[id + 1][remW], V[id] + val[id + 1][remW - W[id]]);
        }
    }
    printf("%d\n", val[0][K]);
}

int main(void){
    int remW;

    scanf("%d %d", &N, &K);
    V = new int[N];
    W = new int[N];
    for(int i = 0; i < N; i++){
        scanf("%d %d", &W[i], &V[i]);
    }
    knap();

    delete V; delete W;
    return 0;
}