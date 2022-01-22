// UVa 628 - Passwords
// Backtracking
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<string> words, rules;
string ans[300];

void backtrack(int pos, string rule){ // idx of answer string
    // printf("%d %d\n", pos, ruleSize);
    if(pos == rule.size()){
        for(int i = 0; i < pos; i++) cout << ans[i];
        cout << endl;
        return;
    }

    if(rule[pos] == '0'){
        for(int i = 48; i <= 57; i++){
            ans[pos] = (char)i;
            backtrack(pos+1, rule);
        }
    }
    else{
        for(int i = 0; i < words.size(); i++){
            ans[pos] = words[i];
            backtrack(pos+1, rule);
        }
    }
}

int main(void){
    string word, rule;

    words.clear(); rules.clear();

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        cin >> word;
        words.push_back(word);
    }
    
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        cin >> rule;
        rules.push_back(rule);
    }

    for(int id = 0; id < rules.size(); id++)
        backtrack(0, rule);

    return 0;
}