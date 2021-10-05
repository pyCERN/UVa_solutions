#include <vector>
using namespace std;

typedef vector<int, int> vi;

class UnionFind{
private:
    vi p, rank;
public:
    UnionFind(int N){
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i){
        return p[i];
    }
    bool isSameSet(int i, int j){
        return p[i] == p[j];
    }
    void unionSet(int i, int j){
        int root_i = findSet(i), root_j = findSet(j);
        if(!isSameSet(i, j)){
            if(rank[i] < rank[j]) p[i] = root_j;
            else{
                p[j] = root_i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
    }
};