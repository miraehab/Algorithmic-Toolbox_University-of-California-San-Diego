#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
   vector <vector<int>> longest_table((a.size() + 1), vector <int> (b.size() + 1));

  for(int i = 0; i <= a.size(); i++){
    for(int j = 0; j <= b.size(); j++){

      if(i == 0 || j == 0){ 
        longest_table[i][j] = 0;
      }else if(a[i - 1] == b[j - 1]){ 
        longest_table[i][j] = 1 + longest_table[i - 1][j - 1];
      }else{ 
        longest_table[i][j] = max(longest_table[i][j - 1], longest_table[i - 1][j]);
      }

    }
  }
  
  return longest_table[a.size()][b.size()];
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
