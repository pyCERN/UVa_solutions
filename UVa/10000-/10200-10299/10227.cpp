// UVa 10227 - Forests
// Union-Find disjoint set
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;

class UnionFind{
private:
    vi parent, rank;
public:
    UnionFind(int N){
        parent.assign(N, 0); rank.assign(N, 0);
        for(int i = 0; i < N; i++)
            parent[i] = i;
    }

    int findSet(int i){
        return (parent[i] == i ? i : (parent[i] = findSet(parent[i])));
    }

    bool isSameSet(int i, int j){
        return (findSet(i) == findSet(j));
    }

    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);

            if(rank[x] > rank[y]) parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

si convertVecToSet(vi v){
    si s;

    for(int i = 0; i < (int)v.size(); i++)
        s.insert(v[i]);

    return s;
}

int main(void){
    int TC, P, T, i, j;
    char trash[10];

    scanf("%d ", &TC);

    while(TC--){
        scanf("%d %d ", &P, &T);

        set<int> ans;
        UnionFind uf(P+1);
        vvi opinionList(P+1, vi());

        while(gets(trash)){
			if(strcmp(trash, "") == 0)
				break;
			sscanf(trash, "%d %d", &i, &j);
            opinionList[i].push_back(j);
        }

        for(int i = 1; i <= P; i++)
            sort(opinionList[i].begin(), opinionList[i].end());
        sort(opinionList.begin(), opinionList.end());

        for(int i = 2; i <= P; i++){
            // To eliminate same elements in opinionList[i]
            if(convertVecToSet(opinionList[i-1]) == convertVecToSet(opinionList[i]))
                uf.unionSet(i-1, i);
        }

        for(int i = 1; i <= P; i++){
            if(opinionList[i].size() != 0)
                ans.insert(uf.findSet(i));
        }

        printf("%d\n", ans.size());
        if(TC) printf("\n");
    }

    return 0;
}