#include <iostream>
#include <set>
 
using namespace std;

multiset <long long> numbers;
 
int main(){
    int n, num; 
    long long result = 1;
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>num;
        numbers.insert(num);
    }
    int cnt = 0;
    for(auto i = numbers.rbegin(); i != numbers.rend(), cnt<2; i++, cnt++){
        result*=(*i);
    }
    cout<<result<<endl;
    return 0;
}