#include <vector>
using namespace std;

typedef vector<int> vi;

class SegmentTree{
private:
    int N;
    vi st, v;
public:
    SegmentTree(int n) : N(n){
        st.assign(2*n, 0);
    }
    void build(int p, int L, int R){
        if(L != R){
            int left_idx = p << 1;
            int right_idx = p << 1 + 1;
            int L_right = (L+R) / 2;
            int R_left = L_right + 1;
            build(left_idx, L, L_right);
            build(right_idx, R_left, R);
            st[p] = min(st[left_idx], st[right_idx]);
        }
        else st[p] = v[L];
    }
}