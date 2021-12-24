#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define MIN -10001
using namespace std;

typedef pair<pair<int, int>, int> iii;

// (W, IQ, idx)
vector<iii> ele;
vector<int> sortedEle, eleIdx;
stack<int> ans;

bool compare(const iii &a, const iii &b){
    if(a.first.first < b.first.first) return true;
    else if(a.first.first == b.first.first) return a.first.second < b.first.second;
    return false;
}

int main(void){
    int w, iq, idx = 1;
    int LIS = 0;
    FILE *fp = fopen("ans.txt", "w");

    while(scanf("%d %d", &w, &iq) == 2){
        ele.push_back(make_pair(make_pair(w, -iq), idx++));
    }
    // sort by weight
    sort(ele.begin(), ele.end(), compare);

    for(auto i : ele) fprintf(fp, "%d %d %d\n", i.first.first, i.first.second, i.second);
    fprintf(fp, "\n");

    // LDS by IQ
    sortedEle.push_back(MIN);
    for(int i = 0; i < idx-1; i++){
        if(i > 0 && ele[i-1].first.first == ele[i].first.first){
            eleIdx.push_back(-1);
            continue;
        }
        if(ele[i].first.second > sortedEle[LIS]){
            sortedEle.push_back(ele[i].first.second);
            eleIdx.push_back(++LIS);
        }
        else{
            auto it = lower_bound(sortedEle.begin(), sortedEle.end(), ele[i].first.second);
            *it = ele[i].first.second;
            eleIdx.push_back(it-sortedEle.begin());
        }
    }
    for(auto i : eleIdx) fprintf(fp, "%d\n", i);

    printf("\n%d\n", LIS);
    for(int i = eleIdx.size(); i >= 0; i--){
        if(eleIdx[i] == LIS){
            ans.push(i);
            LIS--;
        }
    }
    while(!ans.empty()){
        fprintf(fp, "%d %d %d\n", ele[ans.top()].first.first, ele[ans.top()].first.second, ele[ans.top()].second);
        ans.pop();
    }
    fclose(fp);
    return 0;
}