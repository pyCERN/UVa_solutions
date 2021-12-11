// UVa 793 - Network Connections
// Union-Find disjoint set
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class UnionFind{
private:
    vector<int> parent, rank;
public:
    UnionFind(int n){
        parent.assign(n, 0); rank.assign(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findSet(int i){
        if(parent[i] == i) return i;
        else{
            parent[i] = findSet(parent[i]);
            return parent[i];
        }
    }

    bool isSameSet(int i, int j){
        return (findSet(i) == findSet(j));
    }

    void unionSet(int i, int j){
        int x = findSet(i), y = findSet(j);
        if(x != y){
            if(rank[x] > rank[y]) parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(void){
    int TC;
    int no_of_computers, node1, node2;
    char cq;
    char line[1000];
    string s;

    scanf("%d\n", &TC); // to get blank as input
    while(TC--){
        scanf("%d", &no_of_computers);

        UnionFind uf(no_of_computers);
        int success = 0, unsuccess = 0;
        getline(cin, s);

        // input ((c or q), node1, node2)
        while(true){
            gets(line);
            if(strcmp(line, "") == 0) break;

            sscanf(line, "%c %d %d", &cq, &node1, &node2);
            node1--; node2--;
            if(cq == 'c') uf.unionSet(node1, node2);
            else{
                if(uf.isSameSet(node1, node2)) success++;
                else unsuccess++;
            }
        }
        printf("%d,%d\n", success, unsuccess);
        if(TC) printf("\n");
    }

    return 0;
}