#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
	int round = 0, count;
	string ans, sol, str, ans_cpy;

	while(scanf("%d", &round), round != -1){
		printf("Round %d\n", round);
		cin >> ans >> sol;
		ans_cpy = ans;
		str.clear();

		for(int i = 0; i < sol.size() && ans_cpy != ""; i++){
			if(ans.find(sol[i]) == string::npos)
				str.push_back(sol[i]);
			else{
				ans_cpy.erase(remove(ans_cpy.begin(), ans_cpy.end(), sol[i]), ans_cpy.end());
			}
		}
		sort(str.begin(), str.end());
		str.erase(unique(str.begin(), str.end()), str.end());
		if(str.size() < 7 && ans_cpy == "")
			printf("You win.\n");
		else if(str.size() < 7 && ans_cpy != "")
			printf("You chickened out.\n");
		else
			printf("You lose.\n");
	}

	return 0;
}
