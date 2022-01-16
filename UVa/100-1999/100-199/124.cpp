#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
vi topsort, visited;
map<char, int> vertexList;
map<int, char> listVertex;
int N;

void dfs2(int u){
    visited[u] = 1;
    printf("%c : ", listVertex[u]);
    for(int i = 0; i < (int)adjList[u].size(); i++){
        int v = adjList[u][i];
        printf("%c ", listVertex[v]);
        if(visited[v] == 0)
            dfs2(v);
    }
    topsort.push_back(u);
}

int main(void){
    string input;
    int nLine = 0;

    while(getline(cin, input)){
        if(nLine % 2 == 0){
            for(int i = 0; i < input.size(); i += 2){
                vertexList[input[i]] = i/2;
                listVertex[i/2] = input[i];
            }
            N = vertexList.size();
            adjList.assign(N, vi());
            topsort.clear();
        }
        else{
            for(int i = 0; i < input.size(); i += 4){
                adjList[vertexList[input[i]]].push_back(vertexList[input[i+2]]);
            }
            // for(int i = 0; i < adjList.size(); i++){
            //     printf("%c : ", listVertex[i]);
            //     for(int j = 0; j < adjList[i].size(); j++) printf("%c ", listVertex[adjList[i][j]]);
            //     printf("\n");
            // }

            visited.assign(N, 0);
            for(int i = 0; i < (int)adjList.size(); i++){
                if(visited[i] == 0){
                    dfs2(i);
                    printf("\n");}
            }
            // dfs2(0);
            for(int i = topsort.size()-1; i >= 0; i--) printf("%c ", listVertex[topsort[i]]);
            printf("\n");
        }


        nLine++;
    }

    return 0;
}