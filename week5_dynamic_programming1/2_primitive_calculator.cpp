#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> optimal_sequence(int n) {

  vector <int> operations(n+1, INT_MAX);

  for(int i = 2; i < n + 1; ++i){
    int Add_1 = INT_MAX, mult_2 = INT_MAX, mult_3 = INT_MAX;

    Add_1 = operations[i - 1] + 1;

    if(i % 2 == 0){ 
      mult_2 = operations[i / 2] + 1;
    }

    if(i % 3 == 0){ 
      mult_3 = operations[i / 3] + 1;
    }

    operations[i] = min({Add_1, mult_2, mult_3});
  }

  vector <int> ans = {n};
  while(n != 1){
    if(n % 3 == 0 && operations[n] - 1 == operations[n / 3]){
      ans.push_back(n / 3);
      n /= 3;
    }
    else if(n % 2 == 0 && operations[n] - 1 == operations[n / 2]){
      ans.push_back(n / 2);
      n /= 2;
    }
    else{
      ans.push_back(n - 1);
      n -= 1;
    }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> sequence = optimal_sequence(n);
  cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}
