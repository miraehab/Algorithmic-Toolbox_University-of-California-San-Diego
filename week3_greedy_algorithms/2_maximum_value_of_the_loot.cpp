#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<pair<double, int>> ratios;
  for(int i = 0; i<values.size(); ++i){
    ratios.push_back({double(values[i])/weights[i], weights[i]});
  }

  sort(ratios.begin(), ratios.end(), greater<pair<double,int>>());

  for (int i = 0; i < ratios.size() && capacity > 0; ++i) {
		value += min(ratios[i].second, capacity)*ratios[i].first;
		capacity -= min(ratios[i].second, capacity); 
	}

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
