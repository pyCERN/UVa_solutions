// UVa 12405 - Scarecrow
// Interval covering problem (Greedy)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int TC, N;

    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int ans = 0;

        scanf("%d", &N);
        vector<char> p(N);
        for(int i = 0; i < N; i++){
            char c;
            scanf(" %c", &c);
            p[i] = c;
        }

        for(int i = 0; i < N;){
            if(p[i] == '.'){
                ans++;
                i += 3;
            }
            else i++;
        }
        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}