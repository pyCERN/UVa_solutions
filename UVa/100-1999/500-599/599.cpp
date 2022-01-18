// UVa 599 - The Forrest for the Trees
// Graph structure
#include <iostream>
#include <cstdio>
#include <string>
#include <bitset>
using namespace std;

int main(void){
    int nVertices, nEdges, nAcorns, TC;
    string line;
    bitset<26> hasEdge;

    scanf("%d", &TC);
    fflush(stdin); // prevent line[0] = '\n'

    while(TC--){
        nEdges = nAcorns = 0; hasEdge.reset();
        while(cin >> line, line[0] == '('){ // input edges
            nEdges += 1;
            hasEdge.set(line[1]-65, 1);
            hasEdge.set(line[3]-65, 1);
        }
        cin >> line; // input vertices
        nVertices = (line.size() + 1) / 2;
        for(int i = 0; i < line.size(); i += 2){
            if(hasEdge[line[i]-65] == 0) nAcorns++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", nVertices-nEdges-nAcorns, nAcorns);
    }

    return 0;
}