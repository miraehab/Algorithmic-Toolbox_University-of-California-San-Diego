#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal_weight(int W, const vector<int> &weights) {
  int n = weights.size();
  vector<vector<int>> values(n + 1, vector<int>(W + 1, 0));

  for (size_t i = 1; i <= n; ++i){
    for (int j = 1; j <= W; ++j){
      values[i][j] = values[i - 1][j];

      if (weights[i - 1] <= j){
        int val = values[i - 1][j - weights[i - 1]] + weights[i - 1];
        if (values[i][j] < val) values[i][j] = val;
      }
      
    }
  }
  return values[n][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> weights(n);
  for (int i = 0; i < n; i++) cin >> weights[i];
  cout << optimal_weight(W, weights) << '\n';
}