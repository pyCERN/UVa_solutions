#include <cstdio>
#include <bitset>
using namespace std;

// DP

/*
tsp[pos][visit]
total weight of visit state at pos
*/
int N;
int adj_graph[16][16];     // weight matrix between cities
int tsp[16][65536] = {0,};
bitset<16> visited;

void tour(void){
    tsp[0][1] = adj_graph[0][0]; // start at pos 0
    for(int cur_pos = 0; cur_pos < N; cur_pos++){
        tsp[cur_pos][(1<<N)-1] = adj_graph[cur_pos][0];
        for(int nxt_pos = 0; nxt_pos < N; nxt_pos++){
            int mask = visited.to_ulong();
            if((nxt_pos != cur_pos) && (mask & (1 << nxt_pos) == 0)){ // not cur_pos and not visited
                tsp[cur_pos][mask] = 
            }

        }
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) scanf("%d", adj_graph[i][j]);
    }

}