// UVa 10158 - War
// Incomplete
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

class UnionFind{
private:
    vi parent, rank;
    vi isSet; // Is person i is set friend or enemy previously
public:
    UnionFind(int N){
        parent.assign(N, 0); rank.assign(N, 0);
        isSet.assign(N, 0);
        for(int i = 0; i < N; i++)
            parent[i] = i;
    }
    
    int findSet(int i){
        return (parent[i] == i ? i : (parent[i] = findSet(parent[i])));
    }

    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);

            if(rank[x] > rank[y])
                parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    void set(int i){
        isSet[i] = 1;
    }

    bool isRelationSet(int i, int j){
        return (isSet[i] == 1) && (isSet[j] == 1);
    }
};

int main(void){
    int N, c, x, y;
    FILE *fp = fopen("ans.txt", "w");

    scanf("%d", &N);
    UnionFind uf(N);

    while(scanf("%d %d %d", &c, &x, &y), c | x | y){
        // if x, y are set friends/enemies already
        if(uf.isRelationSet(x, y)){
            fprintf(fp, "a %d %d %d\n", c, x, y);
            if(c == 1 || c == 2){
                // if contradictory to previous knowledge
                if((c == 1 && !uf.isSameSet(x, y)) || (c == 2 && uf.isSameSet(x, y)))
                    fprintf(fp, "%d %d %d -1\n", c, x, y);
            }
            else{ // if c == 3 || c == 4
                if((c == 3 && uf.isSameSet(x, y)) || (c == 4 && !uf.isSameSet(x, y)))
                    fprintf(fp, "%d %d %d 1\n", c, x, y);
                else
                    fprintf(fp, "%d %d %d 0\n", c, x, y);
            }
        }
        else{
            fprintf(fp, "b %d %d %d\n", c, x, y);
            if(c == 1 || c == 2){
                // set x, y to friends
                if(c == 1)
                    uf.unionSet(x, y);
                uf.set(x); uf.set(y);
            }
            else{
                fprintf(fp, "%d %d %d 0\n", c, x, y);
            }
        }
    }

    fclose(fp);
    return 0;
}