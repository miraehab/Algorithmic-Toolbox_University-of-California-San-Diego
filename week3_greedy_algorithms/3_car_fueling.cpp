#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> stops) {

    if(tank >= dist) return 0;
    int curr = 0, num = 0;

    while(curr < dist){
        int new_stop = *(upper_bound(stops.begin(), stops.end(), (curr + tank)) - 1);
        if(new_stop > curr){
            curr = new_stop;
            ++num;
            if(curr + tank >= dist) return num;
        }
        else return -1;
    }
    return num;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}