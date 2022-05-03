#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int coins[3] = {1, 3, 4};

int get_change(int m) {
  vector<int> total(m + 1, INT_MAX);
	total[0] = 0;

	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < 3; ++j){
			if(i >= coins[j]){
				int prev = total[i - coins[j]];

				if(prev != INT_MAX){ 
          total[i] = min(total[i], prev + 1);
        }
			}
		}
	}

	return total[m];
}

int main(){
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
