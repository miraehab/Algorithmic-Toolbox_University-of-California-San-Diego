#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  }
    return a - b;
}

int get_maximum_value(const string &exp) {
	int operands = (exp.size() + 1) / 2;
	vector<vector<int>> mini(operands, vector<int>(operands, 0));
	vector<vector<int>> maxi(operands, vector<int>(operands, 0));

	for (int i = 0; i < operands; ++i) {
		mini[i][i] = int(exp[2 * i]) - 48;
		maxi[i][i] = int(exp[2 * i]) - 48;
	}

	for(int s = 0; s < operands - 1; ++s) {
		for(int i = 0; i < operands - s - 1; ++i) {
			int j = i + s + 1;
			int min_Val = INT_MAX;
			int max_Val = INT_MIN;

			for(int o = i; o < j; ++o) {
				int a = eval(mini[i][o], mini[o + 1][j], exp[2 * o + 1]);

				int b = eval(mini[i][o], maxi[o + 1][j], exp[2 * o + 1]);

				int c = eval(maxi[i][o], mini[o + 1][j], exp[2 * o + 1]);

				int d = eval(maxi[i][o], maxi[o + 1][j], exp[2 * o + 1]);

				min_Val = min({min_Val, a, b, c, d});
				max_Val = max({max_Val, a, b, c, d});
			}
			mini[i][j] = min_Val;
			maxi[i][j] = max_Val;
		}
	}

	return maxi[0][operands - 1];
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
  return 0;
}