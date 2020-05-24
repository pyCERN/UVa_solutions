#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// Greedy Algorithm

typedef vector<pair<double, double>> vdd;

/*
void print(vdd v){
	for(int i = 0; i < v.size(); i++) printf("%lf, %lf\n", v[i].first, v[i].second);
}
*/

int main(void){
	int n, l, w;
	vdd range;

	while(scanf("%d %d %d", &n, &l, &w) == 3){
		double x, R, dx;
		int c = 1;
		double rightmost = 0.0;
		range.clear();

		for(int i = 0; i < n; i++){
			scanf("%lf %lf", &x, &R);
			if(R > w / 2.0){
				dx = sqrt(R * R - (w * w) / 4.0);
				range.push_back(make_pair(x-dx, x+dx));
			}
		}

		sort(range.begin(), range.end());
//		print(range);

		if(range[0].first > 0) { printf("%d\n", -1); continue; }
		for(int i = 0, j = 0; i < range.size(); i++){
			double tmp = rightmost;
			while(j < range.size() && rightmost >= range[j].first){
				if(tmp < range[j].second) tmp = range[j].second;
				j++;
			}
			rightmost = tmp;
			if(rightmost >= l) { printf("%d\n", i+1); break; }
		}
		if(rightmost < l) printf("%d\n", -1);
	}

	return 0;
}
