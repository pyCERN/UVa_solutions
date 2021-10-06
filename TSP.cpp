#include <cstdio>
#include <bitset>
using namespace std;

#define MIN 100000001
// DP

/*
W[i][j]
weight for i -> j
*/
int N;
int W[16][16];
int weight_dp[16][65536];

int tsp(int cur_pos, int visit_state){ // return total weight for visit_state at cur_pos
    if(visit_state == (1<<N)-1 && W[cur_pos][0] != 0) // visit all cities if the last city is connected to the initial city
        return W[cur_pos][0];

    if(weight_dp[cur_pos][visit_state] != -1) // if already computed
        return weight_dp[cur_pos][visit_state];

    int min_weight = MIN;
    for(int nxt_pos = 0; nxt_pos < N; nxt_pos++){
        if(!(visit_state & (1<<nxt_pos)) && W[cur_pos][nxt_pos]){ // nxt_pos not visited
            int weight = W[cur_pos][nxt_pos] + tsp(nxt_pos, visit_state | (1<<nxt_pos)); // move on to nxt_pos
            min_weight = min(min_weight, weight);
        }
    }
    weight_dp[cur_pos][visit_state] = min_weight;
    return min_weight;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) scanf("%d", &W[i][j]);
    }

    for(int pos = 0; pos < N; pos++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < (1<<N); j++) weight_dp[i][j] = -1;
        }
    }
    tsp(0, 1);
    printf("%d\n", weight_dp[0][1]);

    return 0;
}