#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  map<int, int> Freq; 
  int n = a.size();
	for (size_t i = 0; i < n; i++)
		Freq[a[i]]++;

	for (int i = 0; i <n; i++)
		if (Freq[a[i]] > (n / 2))
      return true; 
	
	return false;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  cout << get_majority_element(a, 0, a.size())<< '\n';
}
