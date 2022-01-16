#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjList;
vi toposort;
map<char, int> vertexList; // convert alphabet to index
map<int, char> listVertex; // convert index to alphabet
int visited[21];
int N;

// 0 -> 1 -> 2
// 3
void dfs(int u){
    // search for all vertices
    for(int i = 0; i < N; i++){
        if(visited[i] == 0){ // if node i not visited
            // for all vertices connected to node i
            for(int j = 0; j < (int)adjList[i].size(); j++){
                if(visited[j] == 1) return;
            }
        }
    }
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
            toposort.clear();
        }
        else{
            for(int i = 0; i < input.size(); i += 4){
                adjList[vertexList[input[i]]].push_back(vertexList[input[i+2]]);
            }
        }
        dfs(0);
        nLine++;
    }

    return 0;
}