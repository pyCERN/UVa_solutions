// UVa 12405 - Scarecrow
// Interval covering problem (Greedy)
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
using namespace std;

typedef pair<int, int> ii;

int main(void){
    int TC, N;
FILE *fp = fopen("ans.txt", "w");
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int left = 0, right = 0, cnt = 0;
        vector<ii> p;

        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            char c;
            scanf(" %c", &c);
            // if(c == '.')
            p.push_back(make_pair(MAX(i-1, 0), MIN(i+1, N-1)));
        }

        int i = 0;
        while(left < N-1){
            while(i < p.size() && p[i].first <= left)
                right = MAX(right, p[i++].second);
            if(left == right)
                break;
            cnt++;
            left = right;
            printf("%d %d\n", p[i].first, p[i].second);
        }
        fprintf(fp, "Case %d: %d\n", tc, p.size()-cnt);
    }
fclose(fp);
    return 0;
}