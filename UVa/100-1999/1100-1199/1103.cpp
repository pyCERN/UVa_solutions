#include <cstdio>
#include <string>
using namespace std;

// Find connected component
/*
Num of holes
A J D S W K
1 3 5 4 0 2

A
........
.11111..
.1...1..
.11111..
..11....
........

DWWW
........
.111111.
.1....1.
.111111.
.1....1.
.111111.
.1....1.
.111111.
.1....1.
.111111.
.1....1.
.111111.
........
........
.1..1.1.
........

AKW
............
.111.1111...
.1.1.1..1...
.111.1..1...
.1.1.1111...
.111........
............
.1111111....
...1111.....
............

AWW
....
...1
..11
..1.
1...
111.
1111
.1.1
.111
.11.
.1..
11..
11.1
1..1
1.11
1.1.

........
.111111.
.1....1.
.111111.
.1....1.
.111111.
.1....1.
.111111.
........
*/

int H, W;
char hieroglyphs[200][200];
// int hieroglyphs_copy[200][50];
// E, W, S, N, EN, WN, WS, ES
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

int floodfill(int x, int y, char c1, char c2, char c3, bool is_letter){ // '1', '0', '.'
    int ans = 1;

    if(x < 0 | x >= W | y < 0 | y >= H) return 0;
    if(hieroglyphs[x][y] != c1) return 0;
    // if(hieroglyphs[x][y] == c2{
    //     if(is_letter){

    //     }
    //     else return;
    // }

    // Pass conditions -> letter exists
    hieroglyphs[x][y] = c3;

    for(int i = 0; i < 8; i++){
        ans += floodfill(x+dx[i], y+dy[i], c1, c2, c3, true);
    }
    
    // Letter found
    return ans;
}

int main(void){
    int TC = 0;

    while(scanf("%d %d", &H, &W), H | W){
        char str[200];
        memset(hieroglyphs, 0, sizeof(hieroglyphs));

        for(int i = 0; i < H; i++){
            fgets(str, W, stdin);
            for(int j = 0; j < W; j++){
                str[i]
            }
        }
    }

    return 0;
}