#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> coms[8];
double dist[8][8], DP[8][256];
int nCom;

void buildMat(void){
    for(int i = 0; i < nCom; i++){
        for(int j = 0; j < nCom; j++){
            dist[i][j] = sqrt(pow(coms[i].first-coms[j].first, 2) + pow(coms[i].second-coms[j].second, 2));
        }
    }
}

double min(double a, double b){
    return a < b ? a : b;
}

double tsp(int pos, int mask){
    if(mask == (2^nCom-1)) return 0; // if all pos visited
    if(DP[pos][mask] != -1) return DP[pos][mask];

    for(int nxt = 0; nxt < nCom; nxt++){
        if(nxt != pos) DP[pos][mask] = min(DP[pos][mask], dist[pos][nxt] + tsp(nxt, mask | (1<<nxt)));
    }

    return DP[pos][mask];
}

int main(void){
    scanf("%d", &nCom);
    memset(DP, -1, sizeof(DP));
    for(int i = 0; i < nCom; i++) scanf("%d %d", &coms[i].first, &coms[i].second);

    buildMat();
    printf("%lf\n", tsp(0, 1));

    return 0;
}