#include <cstdio>
#include <unordered_map>
#include <map>
using namespace std;

map<int, int> m;

int main(void){
    int TC;
    int n_snow;
    scanf("%d", &TC);

    while(TC--){
        int snow, length = 0, max_length = 0;
        scanf("%d", &n_snow);

        for(int i = 1; i <= n_snow; i++){
            scanf("%d", &snow);
            int idx = m[snow];
            if(idx != 0){ // Found
                // If the element at idx is farther from current i, the element is included in old subarray.
                if(i - idx > length) length++;
                else length = i - idx;
            }
            else length++;
            m[snow] = i;
            if(max_length < length) max_length = length;
        }
        m.clear();
        printf("%d\n", max_length);
    }

    return 0;
}
