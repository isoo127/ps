#include <iostream>
#include <vector>
using namespace std;

int dp[11];

int main() {
    int T; cin >> T;
    vector<int> v;
    int tmp;
    for(int i = 0; i < T; i++) {
        cin >> tmp; v.push_back(tmp);
    }

    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 10; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    for(int i = 0; i < T; i++) {
        cout << dp[v.at(i)] << endl;
    }

    return 0;
}