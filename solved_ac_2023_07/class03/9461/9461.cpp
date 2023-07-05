#include <iostream>
#include <vector>
using namespace std;

long long int dp[101];

int main() {
    int T; cin >> T;
    vector<int> v; int tmp;
    for(int i = 0 ; i < T; i++) {
        cin >> tmp; v.push_back(tmp);
    }

    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for(int i = 4; i <= 100; i++)
        dp[i] = dp[i-3] + dp[i-2];

    for(int i = 0; i < T; i++) 
        cout << dp[v.at(i)] << endl;

    return 0;
}