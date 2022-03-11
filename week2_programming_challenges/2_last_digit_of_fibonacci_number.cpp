#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;

    vector<int> last_digit(n+1);
    last_digit[0] = 0;
    last_digit[1] = 1;
    for(int i = 2; i<=n; ++i){
        last_digit[i] = (last_digit[i-1] + last_digit[i-2])%10;
    }
    return last_digit[n]; 
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit(n);
    cout << c << '\n';
}
