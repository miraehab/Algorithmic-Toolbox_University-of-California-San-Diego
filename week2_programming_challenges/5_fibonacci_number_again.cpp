#include <iostream>
#include <vector>

using namespace std;

//function to get the pisano period
long long get_period(long long  m){
    long long  a=0, b=1, c=a+b;
    for (long long i=0; i<m*m; i++){
        c=(a+b)%m;
        a=b;
        b=c;
        if(a==0 && b==1) 
            return i+1;
    }
    return 0;
}

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;

    vector<long long> last_digit(n+1);
    last_digit[0] = 0;
    last_digit[1] = 1;
    for(int i = 2; i<=n; ++i){
        last_digit[i] = (last_digit[i-1] + last_digit[i-2])%m;
    }
    return last_digit[n]; 
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    n = n%get_period(m);
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
