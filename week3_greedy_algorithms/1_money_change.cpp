#include <iostream>

using namespace std;

int get_change(int m) {
  int n;
  int coins[3] = {10, 5, 1};
  for(int i = 0; i < 3; ++i){
    if(m >= coins[i]){
      n+=(m/coins[i]);
      m %=coins[i];
    }
    if(m == 0) break;
  }
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
