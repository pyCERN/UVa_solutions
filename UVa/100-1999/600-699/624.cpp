// UVa 624 - CD
// Backtracking
#include <cstdio>
#include <vector>
using namespace std;

int N, nTracks, sum, maxSum;
int CD[21];
vector<int> seq, ans;

void backtrack(int length, int id){
    if(id == nTracks){
        // print only for max length (<= N)
        // seq saves any sequences with length <= N
        if(maxSum < sum){
            maxSum = sum;
            ans = seq;
        }
        return;
    }
    
    if(length >= CD[id]){
        seq.push_back(CD[id]); sum += CD[id];
        backtrack(length-CD[id], id+1);
        seq.pop_back(); sum -= CD[id];
    }
    backtrack(length, id+1);
}

int main(void){
    while(scanf("%d", &N) != EOF){
        scanf("%d", &nTracks);
        sum = maxSum = 0;
        for(int id = 0; id < nTracks; id++) scanf("%d", &CD[id]);

        backtrack(N, 0);
        for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
        printf("sum:%d\n", maxSum);
    }

    return 0;
}