// UVa 10037 - Bridge
// Greedy
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int TC, N;
    string s;
    
    scanf("%d", &TC);

    while(TC--){
        getline(cin, s); getline(cin, s);
        scanf("%d", &N);
        
        stringstream ss;
        vector<int> times(N);
        for(int i = 0; i < N; i++) scanf("%d", &times[i]);
        sort(times.begin(), times.end());

        int sum = 0, i = N-1;
        while(i >= 3){
            int fast1 = times[0], fast2 = times[1];
            /*
            fastest: A, B
            slowest: X, Y
            choose one of the routes:
            (i)  (A, X), (A), (A, Y), (A) 2A+X+Y
            (ii) (A, B), (A), (X, Y), (B) A+2B+Y
            */
            int slow1 = times[i-1], slow2 = times[i];
            int route1 = 2*fast1 + slow1 + slow2, route2 = fast1 + 2*fast2 + slow2;

            if(route1 < route2){
                ss << fast1 << " " << slow1 << endl;
                ss << fast1 << endl;
                ss << fast1 << " " << slow2 << endl;
                ss << fast1 << endl;
                sum += route1;
            }
            else{
                ss << fast1 << " " << fast2 << endl;
                ss << fast1 << endl;
                ss << slow1 << " " << slow2 << endl;
                ss << fast2 << endl;
                sum += route2;
            }
            i -= 2;
        }
        if(i == 2){
            ss << times[0] << " " << times[1] << endl;
            ss << times[0] << endl;
            ss << times[0] << " " << times[2] << endl;
            sum += times[0] + times[1] + times[2];
        }
        else if(i == 1){
            ss << times[0] << " " << times[1] << endl;
            sum += times[1];

        }
        else{
            ss << times[0] << endl;
            sum += times[0];
        }
        cout << sum << endl;
        cout << ss.str();
        if(TC) cout << endl;
    }

    return 0;
}