#include <iostream>

using namespace std;

long long GCD(long long a, long long b){
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

long long lcm(long long a, long long b) {
  return (a * b)/GCD(a, b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << lcm(a, b) <<endl;
  return 0;
}
