#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// Find connected component
/*
Num of holes
A J D S W K
1 3 5 4 0 2
*/

int H, W;
int hieroglyphs[210][210], letter[210][210];
vector<char> ans;
char ans_letter[] = "WAKJSD";
// E, W, S, N
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int hex_to_bin[][4] = {
                        {0, 0, 0, 0},
                        {0, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 0, 1, 1},
                        {0, 1, 0, 0},
                        {0, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 1},
                        {1, 0, 1, 0},
                        {1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0},
                        {1, 1, 1, 1}
                       };

void floodfill(int grid[210][210], int x, int y, int c1, int c2, int c3){
    if(x < 0 | x > 4*W+1 | y < 0 | y > H+1) return;
    if(grid[y][x] != c1) return;

    // Use floodfill func twice
    if(grid != letter)
        hieroglyphs[y][x] = c2;
    letter[y][x] = c3;

    for(int i = 0; i < 8; i++){
        floodfill(grid, x+dx[i], y+dy[i], c1, c2, c3);
    }
}

int get_letter(void){
    int num, n_holes = 0;

    // Flip letter to group of 1s
    // Group of 1s -> number of holes
    for(int y = 0; y <= H+1; y++){
        for(int x = 0; x <= 4*W; x++){
            if(letter[y][x] == 1) letter[y][x] = 0;
            else letter[y][x] = 1;
        }
    }

    for(int y = 0; y <= H+1; y++){
        for(int x = 0; x <= 4*W+1; x++){
            if(letter[y][x] == 1){
                floodfill(letter, x, y, 1, 2, 2);
                n_holes++;
            }
        }
    }
    
    return ans_letter[n_holes-1];
}

int main(void){
    int TC = 0;

    while(scanf("%d %d", &H, &W), H | W){
        if(TC) printf("\n");
        char str[200];
        memset(hieroglyphs, 0, sizeof(hieroglyphs));
        ans.clear();

        // Hexadecimal input to binary
        for(int i = 0; i < H; i++){
            scanf("%s", str);
            for(int j = 0; j < W; j++){
                int hex = 0;
                if(str[j] >= 97) hex = str[j] - 97 + 10;
                else hex = str[j] - 48;
                for(int k = 0; k < 4; k++){
                    hieroglyphs[i+1][4*j+k+1] = hex_to_bin[hex][k];
                }
            }
        }

        // Floodfill letters one by one
        for(int y = 0; y <= H+1; y++){
            for(int x = 0; x <= 4*W+1; x++){
                if(hieroglyphs[y][x] == 1){ // floodfill one letter
                    memset(letter, 0, sizeof(letter));
                    floodfill(hieroglyphs, x, y, 1, 2, 1);
                    ans.push_back(get_letter());
                }
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case %d: ", ++TC);
        for(int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
    }

    return 0;
}