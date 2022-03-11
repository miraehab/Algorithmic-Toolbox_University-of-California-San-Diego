#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_sum(long long n) {
    if(n == 0) return 0;
    if (n <= 1)
        return n;

    vector<long long> last_digit(n+1);
    long long sum = 1;
    last_digit[0] = 0;
    last_digit[1] = 1;
    for(long long i = 2; i<=n; ++i){
        last_digit[i] = (last_digit[i-1] + last_digit[i-2])%10;
        sum+=last_digit[i];
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum(n);
}
