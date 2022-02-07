// UVa 10341 - Solve It
// Bisection method
#include <cstdio>
#include <cmath>

int main(void){
    int p, q, r, s, t, u;

    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6){
        double lo = 0.0, hi = 1.0, mid;
        double value, ans;

        while(hi-lo > 1e-9){
            mid = (lo + hi) / 2;
            value = p*exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*mid*mid + u;
            ans = mid;
            if(value > 0) lo = mid;
            else hi = mid;
        }
        if(fabs(value) <= 1e-4) printf("%.4lf\n", mid);
        else printf("No solution\n");
    }

    return 0;
}