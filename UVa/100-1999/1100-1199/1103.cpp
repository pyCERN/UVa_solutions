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
char hieroglyphs[200][50];
// int hieroglyphs_copy[200][50];
// E, W, S, N, EN, WN, WS, ES
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

void floodfill(int x, int y, char c1, char c2, char c3, bool is_letter){ // '1', '0', '.'
    if(x < 0 | x >= W | y < 0 | y >= H) return;
    if(hieroglyphs[x][y] == c3) return;
    if(hieroglyphs[x][y] == c2{
        if(is_letter){

        }
        else return;
    }

    // Pass conditions -> letter exists
    hieroglyphs[x][y] = c3;

    for(int i = 0; i < 8; i++){
        floodfill(x+dx[i], y+dy[i], c1, c2);
    }
}

int main(void){
    int TC = 0;

    while(scanf("%d %d", &H, &W), H | W){
        
    }

    return 0;
}