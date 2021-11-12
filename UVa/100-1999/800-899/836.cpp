// UVa 836 - Largest Submatrix
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<string> arr;
int subRect[30][30];
int N;

int main(void){
    int TC;
    int ans, sum;
    string s;

    scanf("%d", &TC);
    getline(cin, s); // input \n after TC
    getline(cin, s); // input \n
    
    while(TC--){
        // getline(cin, s); // input \n
        arr.clear();
        while(getline(cin, s), s != "") arr.push_back(s);
        N = arr.size();
        
        // maxSub[i][j] : sum of arr[0][0] to arr[i][j]
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                sum = 0;
                for(int m = 0; m <= i; m++){
                    for(int n = 0; n <= j; n++) sum += arr[m][n] - 48;
                }
                subRect[i][j] = sum;
            }
        }
        /*
        sum from (i, j) to (m, n)
        subRect[m][n] - subRect[i-1][n] - subRect[m][j-1] + subRect[i-1][j-1]
        */
        ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int m = i; m < N; m++){
                    for(int n = j; n < N; n++){
                        sum = subRect[m][n];
                        if(i > 0) sum -= subRect[i-1][n];
                        if(j > 0) sum -= subRect[m][j-1];
                        if(i > 0 && j > 0) sum += subRect[i-1][j-1];
                        if(ans < sum && sum == (m-i+1)*(n-j+1)) ans = sum;
                    }
                }
            }
        }
        printf("%d\n", ans);
        if(TC) printf("\n");
    }

    return 0;
}