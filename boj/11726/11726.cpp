#include <iostream>
using namespace std;

long long unsigned int dp[1001];

int main() {
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 1000; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    int N; cin >> N;
    cout << dp[N];

    return 0;
}