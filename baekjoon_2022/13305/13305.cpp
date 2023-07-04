#include <iostream>
#include <vector>
#define ll unsigned long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> roads;

    for(int i = 0; i < N - 1; i++) {
        int road; cin >> road;
        roads.push_back(road);
    }

    ll price = 1e9;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        ll x; cin >> x;
        if(i == N - 1) break;
        if(x < price)  { 
            sum += x * roads.at(i);
            price = x;
        } else sum += price * roads.at(i);
    }

    cout << sum;

    return 0;
}