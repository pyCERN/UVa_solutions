#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Using next_permutation

int main(void){
    char str[51];
    vector<char> v;
    string s;

    while(scanf("%s", str), s = str, s != "#"){
        for(int i = 0; i < s.length(); i++) v.push_back(str[i]);
        if(next_permutation(v.begin(), v.end())){
            for(int i = 0; i < s.length(); i++)
                printf("%c", v[i]);
            printf("\n");
        }
        else printf("No Successor\n");
        v.clear();
    }
    
    return 0;
}