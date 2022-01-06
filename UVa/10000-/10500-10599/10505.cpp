#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> enemyList[201];
int enemyMat[201][201];

/*
  1 2 3 4 5
1 o x x o o
2 x o o o o
3 x o o o o
4 o o o o x
5 o o o x o

e of e -> f
e of f -> e
f of f -> f
*/
int main(void){
    int TC;
    int nEnemies, enemyIdx;

    scanf("%d", &TC);
    scanf("%d", &N);
    memset(enemyMat, 0, sizeof(enemyMat));

    for(int n = 1; n <= N; n++){
        scanf("%d", &nEnemies);

        for(int i = 1; i <= nEnemies; i++){
            scanf("%d", &enemyIdx);
            enemyMat[n][i] = 1; enemyMat[i][n] = 1; // symmetric
        }
    }

    
}