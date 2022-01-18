#include <iostream>
#include <cstdio>
#include <string>
#include <bitset>
using namespace std;

int main(void){
    int nVertices, nEdges, nAcorns, TC;
    string line;
    bitset<26> hasEdge;
    FILE *fp = fopen("ans.txt", "w");
    scanf("%d", &TC);
    fflush(stdin); // prevent line[0] = '\n'

    while(TC--){
        nEdges = nAcorns = 0; hasEdge.reset();
        while(getline(cin, line), line[0] == '('){ // input edges
            nEdges += 1;
            hasEdge.set(line[1]-65, 1);
            hasEdge.set(line[3]-65, 1);
        }
        getline(cin, line); // input vertices
        nVertices = (line.size() + 1) / 2;
        for(int i = 0; i < line.size(); i += 2){
            if(!hasEdge[line[i]-65]) nAcorns++;
        }
        fprintf(fp, "There are %d tree(s) and %d acorn(s).\n", nVertices-nEdges-nAcorns, nAcorns);
    }
    fclose(fp);
    return 0;
}