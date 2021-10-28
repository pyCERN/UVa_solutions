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
int hiero[210][210], letter[210][210];
vector<char> ans;
char ans_letter[] = "WAKJSD";
// E, N, W, S, ES, EN, WN, WS
int dr[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
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

void floodfill(int r, int c, int c1, int c2){ // if c1 -> c2
    if(r < 0 || r >= H || c < 0 || c >= 4*W) return;
    if(hiero[r][c] != c1) return;
    hiero[r][c] = c2;
    letter[r+1][c+1] = c1;
    for(int i = 0; i < 8; i++) floodfill(r+dr[i], c+dc[i], c1, c2);
}

void floodfill_letter(int r, int c, int c1, int c2){
    if(r < 0 || r >= H+2 || c < 0 || c >= 4*W+2) return;
    if(letter[r][c] != c1) return;
    letter[r][c] = c2;
    for(int i = 0; i < 8; i++) floodfill_letter(r+dr[i], c+dc[i], c1, c2);
}

int main(void){
    int TC = 0;
    char str[60];
    int num_holes = 0;

    while(scanf("%d %d", &H, &W), H | W){

        memset(hiero, 0, sizeof(hiero));
        ans.clear();
        for(int i = 0; i < H; i++){
            scanf("%s", str);
            for(int j = 0; j < W; j++){
                for(int k = 0; k < 4; k++){
                    // Zero padding
                    if(str[j] >= 97) hiero[i][4*j+k] = hex_to_bin[str[j]-97+10][k];
                    else hiero[i][4*j+k] = hex_to_bin[str[j]-48][k];
                }
            }
        }

        for(int i = 0; i < H; i++){
            for(int j = 0; j < 4*W; j++){
                if(hiero[i][j] != 1) continue;
                memset(letter, 0, sizeof(letter));

                floodfill(i, j, 1, 2);
                num_holes = 0;
                for(int r = 0; r < H+2; r++){
                    for(int c = 0; c < 4*W+2; c++){
                        if(letter[r][c] != 0) continue;
                        floodfill_letter(r, c, 0, 2);
                        num_holes++;
                    }
                }
                ans.push_back(ans_letter[num_holes-1]);
            }
        }

        sort(ans.begin(), ans.end());
        printf("Case %d: ", TC+1);
        for(int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
        printf("\n");
    }

    return 0;
}